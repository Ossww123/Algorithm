import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 입력 받기
        int N = scanner.nextInt(); // 카드 개수
        int M = scanner.nextInt(); // 목표 값
        int[] cards = new int[N];

        for (int i = 0; i < N; i++) {
            cards[i] = scanner.nextInt();
        }

        // 카드 정렬
        Arrays.sort(cards);

        int maxSum = 0;

        // 3장의 카드 조합 탐색
        for (int i = 0; i < N - 2; i++) {
            if ( cards[i] > M) break;
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
