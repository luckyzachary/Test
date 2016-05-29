import java.util.Scanner;
//x++ %= 9;
public class NineSquares {
	private static int[][] nail = new int[2][];
	public static void showMatrixes(int[][] matrixes) {
		for (int i = 0; i < matrixes.length; i++) {
			if (i % 3 == 0)
				System.out.println("-------------------------");
			for (int j = 0; j < matrixes[i].length; j++) {
				if (j % 3 == 0)
					System.out.print("| ");
				System.out.print(matrixes[i][j] + " ");
				if (j == 8)
					System.out.print("|");
			}
			System.out.println();
			if (i == 8)
				System.out.println("-------------------------");
		}
	}
	public static int[][] randomNail(int[][] matrixes) {
		int number = (int)(Math.random() * 82);
		nail[0] = new int[number];
		nail[1]	= new int[number];
		boolean isRepetitive;
		for (int i = 0; i < number; i++) {
			do {
				isRepetitive = false;
				nail[0][i] = (int)(Math.random() * 9);
				nail[1][i] = (int)(Math.random() * 9);
				for (int j = 0; j < i; j++) 
					if (nail[0][i] == nail[0][j] && nail[1][i] == nail[1][j])
						isRepetitive = true;
			} while(isRepetitive);
			matrixes[nail[0][i]][nail[1][i]] = (int)(Math.random() * 9) + 1;
		}
		return matrixes;
	}
	public static int[][] inputNail(int[][] matrixes) {
		Scanner input = new Scanner(System.in);
		System.out.print("Please input the number of nail: ");
		int number = input.nextInt();
		nail[0] = new int[number];
		nail[1]	= new int[number];
		System.out.println("Please input correct coordinates(0-8) and correct element(1-9): ");
		for (int i = 0; i < number; i++) {
			nail[0][i] = input.nextInt();
			nail[1][i] = input.nextInt();
			matrixes[nail[0][i]][nail[1][i]] = input.nextInt();
		}
		return matrixes;
	}
	public static boolean checkNail(int[][] matrixes) {
		for (int i = 1; i < nail[0].length; i++)
			for (int j = 0; j < i; j++)
				if (nail[0][i] == nail[0][j]
					|| nail[1][i] == nail[1][j]
					|| nail[0][i] / 3 == nail[0][j] / 3 && nail[1][i] / 3 == nail[1][j] / 3) 
					if (matrixes[nail[0][i]][nail[1][i]] == matrixes[nail[0][j]][nail[1][j]])
						return false;
		return true;
	}
	public static int[][] buildNail(int[][] matrixes) {
		int times = 0;
		do { 
			for (int i = 0; i < matrixes.length; i++)
				for (int j = 0; j < matrixes[i].length; j++)
					matrixes[i][j] = 0;
			randomNail(matrixes);
			times++;
		} while (!checkNail(matrixes));
		System.out.println("Times built nails is " + times + ".");
		return matrixes;
	}
	public static int[][] buildMatrixes(int[][] matrixes) {
		int direction = 1;
		for (int row = 0; row < matrixes.length; row++) {
			for (int column = 0; column < matrixes[row].length; column++) {
				for (int i = 0; i < nail[0].length; i++) {
					if (row == nail[0][i] && column == nail[1][i]) {
						column++;
						i = 0;
					}
				}
			}
		}
		return matrixes;
	}
	public static boolean isCover(int...array) {
		boolean[] chArr = new boolean[array.length];
		for (int c = 0; c < array.length; c++)
			if (array[c] == 0)
				return false;
		for (int i = 0; i < chArr.length; i++)
			chArr[i] = false;
		for (int j = 0; j < array.length; j++)
			chArr[array[j] - 1] = true;
		for (int k = 0; k < chArr.length; k++)
			if (chArr[k] == false)
				return false;
		return true;
	}
	public static boolean checkMatrixes(int[][] matrixes) {
		for (int row = 0; row < matrixes.length; row++)
			if (!isCover(matrixes[row]))
				return false;
		for (int column = 0; column < matrixes[0].length; column++)
			if (!isCover(matrixes[0][column], matrixes[1][column], matrixes[2][column], 
						 matrixes[3][column], matrixes[4][column], matrixes[5][column], 
						 matrixes[6][column], matrixes[7][column], matrixes[8][column]))
				return false;
		for (int rOrigin = 0; rOrigin < 3; rOrigin++)
			for (int cOrigin = 0; cOrigin < 3; cOrigin++)
				if (!isCover(matrixes[rOrigin * 3][cOrigin * 3], matrixes[rOrigin * 3][cOrigin * 3 + 1], matrixes[rOrigin * 3][cOrigin * 3 + 2], 
							 matrixes[rOrigin * 3 + 1][cOrigin * 3], matrixes[rOrigin * 3 + 1][cOrigin * 3 + 1], matrixes[rOrigin * 3 + 1][cOrigin * 3 + 2], 
							 matrixes[rOrigin * 3 + 2][cOrigin * 3], matrixes[rOrigin * 3 + 2][cOrigin * 3 + 1], matrixes[rOrigin * 3 + 2][cOrigin * 3 + 2])) 
					return false;
		return true;
	}
	public static void main(String[] args) {
		int[][] matrixes = new int[9][9];
		buildNail(matrixes);
		System.out.println("The number of nails is " + nail[0].length + ".");
		showMatrixes(matrixes);
		buildMatrixes(matrixes);
		
	}
}