import java.util.Scanner;

public class printCalendar {
	public static void printTitle(int month, int year) {
		System.out.println("===========================");
		System.out.println("         " + month + "   " + year + "         ");
		System.out.println("===========================");
		System.out.println("Mon Tue Wed Thu Fri Sat Sun");
	}
	public static boolean isleapyear(int year) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			return true;
		else
			return false;
	}
	public static int getdays(int month, int year) {
		if (month == 2) {
			if (isleapyear(year))
				return 29;
			else
				return 28;
		} else if (month == 4 || month == 6 || month == 9 || month == 11) 
			return 30;
		else
			return 31;
	}
	public static int getfirstday(int month, int year) {
		int firstday, totalday = 0;
		if (year >= 2000) {
			for (int i = 0; i + 2000 < year; i++)
				if (isleapyear(i + 2000)) 
					totalday += 366;
				else
					totalday += 365;
			for (int i = 1; i < month; i++)
				totalday += getdays(i, year);
			firstday = (totalday + 6) % 7 ;
		} else {
			for (int i = -1; i + 2000 > year; i--)
				if (isleapyear(i + 2000)) 
					totalday += 366;
				else
					totalday += 365;
			for (int i = 12; i >= month; i--)
				totalday += getdays(i, year);
			firstday = (8 - (totalday - 5) % 7) % 7;
		}
		if (firstday == 0)
			firstday = 7;
		return firstday;
	}
	public static void printbody(int firstday, int days) {
		for (int i = 0; i < (firstday - 1) * 4; i++)
			System.out.print(" ");
		for (int i = 1; i <= days; i++) {
			System.out.printf("%3d ", i);
			if ((i + firstday - 1) % 7 == 0)
				System.out.println();
		}
		if ((firstday + days) % 7 == 1)
			System.out.println("===========================");
		else
			System.out.println("\n===========================");
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			System.out.println("Please input month and year by order:");
			int month = input.nextInt();
			int year = input.nextInt();
			printTitle(month, year);
			printbody(getfirstday(month, year), getdays(month, year));
		}
	}
}