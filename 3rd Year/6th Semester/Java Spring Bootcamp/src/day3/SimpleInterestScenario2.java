package day3;

import java.util.Scanner;

public class SimpleInterestScenario2 {
	public static void main(String[] args) {
		float ans = simpleInterest();
		System.out.println("Simple Interest: " + ans);
	}
	
	public static float simpleInterest() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the principle amount: ");
		int principle = sc.nextInt();
		System.out.println("Enter the annual rate: ");
		int rate = sc.nextInt();
		System.out.println("Enter the time in years: ");
		int time = sc.nextInt();
		
		float ans = (float)((principle * rate * time) / 100);
		return ans;
	}
}
