import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a;
		a = sc.nextInt();
		
		for (int i=1; i < 10; i++) {
			System.out.println(a + " * "+i+" = "+a*i);
		}
	}
}