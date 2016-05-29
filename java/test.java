public class test {
	public static void main(String[] args) {
		char[] dst = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
		"java".getChars(1, 4, dst, 3);
		System.out.println(dst);
		"java".getChars(0, 4, dst, 3);
		System.out.println(dst);
	}
}