#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

#include <string>
using std::string;

#include <algorithm>
using std::fill;
using std::max;
using std::min;
using std::find;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <unordered_set>
using std::unordered_set;

int DY[4] = { 0, 0, -1, 1 };
int DX[4] = { 1, -1, 0, 0 };

enum class DIR {
    RIGHT,
    LEFT,
    UP,
    DOWN,
};

struct chess_piece {
    int index;
    DIR D;
};

enum class SQUARE_INFO {
    WHITE,
    RED,
    BLUE,
};

struct chess_square {
    vector<chess_piece> chess_pieces;
    SQUARE_INFO s_info;

    bool IsEmpty() { return chess_pieces.empty(); }
    void push_back(chess_piece cp) {
        chess_pieces.push_back(cp);
    }
    void push_back(const vector<chess_piece>& cp) {
        chess_pieces.insert(chess_pieces.end(), cp.begin(), cp.end());
    }
    void push_reverse_back(const vector<chess_piece>& cp) {
        chess_pieces.insert(chess_pieces.end(), cp.rbegin(), cp.rend());
    }
    int GetBottomPieceIndex() {
        if (chess_pieces.empty()) {
            return -1;
        }
        return chess_pieces[0].index;
    }
};

bool game_over = false;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<chess_square>> chess_board(N, vector<chess_square>(N));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            int i_temp;
            cin >> i_temp;
            chess_board[y][x].s_info = (SQUARE_INFO)i_temp;
        }
    }

    for (int i = 1; i <= K; ++i) {
        int y, x, d;
        cin >> y >> x >> d;
        chess_piece cp_temp = { i, (DIR)(d - 1) };
        chess_board[y - 1][x - 1].push_back(cp_temp);
    }

    int turn = 0;
    while (!game_over) {
        ++turn;

        if (turn > 1000) break;

        for (int piece_num = 1; piece_num <= K; ++piece_num) {
            // 현재 차례의 말이 맨 아래에 깔려 있는데 확인
            bool found = false;
            for (int y = 0; y < N && !found; ++y) {
                for (int x = 0; x < N && !found; ++x) {
                    if (!chess_board[y][x].IsEmpty() &&
                        chess_board[y][x].GetBottomPieceIndex() == piece_num) {

                        found = true;

                        // 해당 위치의 모든 말들을 가져오기
                        vector<chess_piece> moving_pieces = chess_board[y][x].chess_pieces;

                        // 현재 칸 비우기
                        chess_board[y][x].chess_pieces.clear();

                        // 이동할 방향 계산
                        DIR current_dir = moving_pieces[0].D;
                        int ny = y + DY[(int)current_dir];
                        int nx = x + DX[(int)current_dir];

                        // 제자리 체크용
                        bool dont_move = false;

                        // 파란색이거나 범위 밖이면 방향 전환
                        if (ny < 0 || ny >= N || nx < 0 || nx >= N ||
                            chess_board[ny][nx].s_info == SQUARE_INFO::BLUE) {

                            // 방향 전환
                            if (current_dir == DIR::RIGHT) current_dir = DIR::LEFT;
                            else if (current_dir == DIR::LEFT) current_dir = DIR::RIGHT;
                            else if (current_dir == DIR::UP) current_dir = DIR::DOWN;
                            else if (current_dir == DIR::DOWN) current_dir = DIR::UP;

                            // 말의 방향 업데이트
                            moving_pieces[0].D = current_dir;

                            // 반대 방향
                            ny = y + DY[(int)current_dir];
                            nx = x + DX[(int)current_dir];

                            // 여전히 파란색이거나 범위 밖이면 제자리
                            if (ny < 0 || ny >= N || nx < 0 || nx >= N ||
                                chess_board[ny][nx].s_info == SQUARE_INFO::BLUE) {
                                ny = y;
                                nx = x;

                                dont_move = true;
                            }
                        }

                        // 목표 칸에 말들 배치
                        if (dont_move || chess_board[ny][nx].s_info == SQUARE_INFO::WHITE) {
                            chess_board[ny][nx].push_back(moving_pieces);
                        }
                        else if (chess_board[ny][nx].s_info == SQUARE_INFO::RED) {
                            chess_board[ny][nx].push_reverse_back(moving_pieces);
                        }
                        else { // 파란색
                            chess_board[ny][nx].push_back(moving_pieces);
                        }

                        // 이동 완료 후 4개 이상 쌓였는지 체크
                        if (chess_board[ny][nx].chess_pieces.size() >= 4) {
                            game_over = true;
                            break;
                        }
                    }
                }
            }
            if (game_over) break;
        }
    }

    if (game_over && !(turn > 1000)) {
        cout << turn << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}