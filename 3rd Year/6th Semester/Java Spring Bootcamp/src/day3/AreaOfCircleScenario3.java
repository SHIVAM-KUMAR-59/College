package day3;

import java.util.Scanner;

public class AreaOfCircleScenario3 {
	public static void main (String[] args) {
		
		int radius;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the radius: ");
		radius = sc.nextInt();
		
		float area = areaOfCircle(radius);
		System.out.println("Area or circle: " + area);
	}
	
	public static float areaOfCircle(int radius) {
		
		float area = (float)(3.14 * radius * radius);
		return area;
		
	}
}
