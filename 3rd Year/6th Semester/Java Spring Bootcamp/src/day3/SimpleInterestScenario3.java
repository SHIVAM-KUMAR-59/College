package day3;

import java.util.Scanner;

public class SimpleInterestScenario3 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the principle amount: ");
		int principle = sc.nextInt();
		System.out.println("Enter the annual rate: ");
		int rate = sc.nextInt();
		System.out.println("Enter the time in years: ");
		int time = sc.nextInt();
		
		float ans = simpleInterest(principle, rate, time);
		System.out.println("Simple Interest: " + ans);
	}
	
	public static float simpleInterest(int principle, int rate, int time) {
		float ans = (float)((principle * rate * time) / 100);
		return ans;
	}
}
