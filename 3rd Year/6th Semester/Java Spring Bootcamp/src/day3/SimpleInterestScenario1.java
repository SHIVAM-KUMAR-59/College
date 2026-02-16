package day3;

import java.util.Scanner;

public class SimpleInterestScenario1 {
	public static void main(String[] args) {
		simpleInterest();
	}
	
	public static void simpleInterest() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the principle amount: ");
		int principle = sc.nextInt();
		System.out.println("Enter the annual rate: ");
		int rate = sc.nextInt();
		System.out.println("Enter the time in years: ");
		int time = sc.nextInt();
		
		float ans = (float)((principle * rate * time) / 100);
		System.out.println("Simple Interest: " + ans);
	}
}
