import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력 받기
        String[] firstLine = br.readLine().split(" "); // 첫 줄 입력
        int N = Integer.parseInt(firstLine[0]); // 카드 개수
        int M = Integer.parseInt(firstLine[1]); // 목표 값
        int[] cards = new int[N];

        String[] cardInput = br.readLine().split(" "); // 카드 숫자들 입력
        for (int i = 0; i < N; i++) {
            cards[i] = Integer.parseInt(cardInput[i]);
        }

        // 카드 정렬
        Arrays.sort(cards);

        int maxSum = 0;

        // 3장의 카드 조합 탐색
        for (int i = 0; i < N - 2; i++) {
            if (cards[i] > M) break;
            for (int j = i + 1; j < N - 1; j++) {
                if (cards[i] + cards[j] > M) break;

                for (int k = j + 1; k < N; k++) {
                    int sum = cards[i] + cards[j] + cards[k];

                    // M을 초과하면 멈춤
                    if (sum > M) break;

                    // 최댓값 갱신
                    maxSum = Math.max(maxSum, sum);
                }
            }
        }
        System.out.println(maxSum);
    }
}
