package day3;

import java.util.Scanner;

public class AreaOfCircleScenario1 {
	public static void main (String[] args) {
		areaOfCircle();
	}
	
	public static void areaOfCircle() {
		int radius;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the radius: ");
		radius = sc.nextInt();
		
		float area = (float)(3.14 * radius * radius);
		System.out.println("Area or circle: " + area);
	}
}
