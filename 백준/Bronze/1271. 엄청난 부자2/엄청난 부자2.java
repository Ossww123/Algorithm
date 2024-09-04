import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		BigInteger n = new BigInteger(sc.next());
		BigInteger m = new BigInteger(sc.next());
		
		BigInteger div = n.divide(m);
		BigInteger mod = n.mod(m);
		
		System.out.println(div);
		System.out.println(mod);
		
	}
}
