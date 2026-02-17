package day2;

import java.util.*;

public class Test {
	
	public static void areaOfRectangle() {
		Scanner sc =  new Scanner(System.in);
		
		System.out.println("Enter the length of the rectange:");
		int length = sc.nextInt();
		
		System.out.println("Enter the width of the rectange:");
		int width = sc.nextInt();
		
		int area = length * width;
		System.out.println(area);
		
		sc.close();
	}
	
	public static void areaOfCircle() {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the radius of the circle");
		int radius = sc.nextInt();
		
		float area = (float) (3.14 * radius * radius);
		System.out.println("Area of the circle is: " + area);
		
		sc.close();
	}
	
	public static void main (String[] args) {
		
//		areaOfRectangle();
		areaOfCircle();
	}
	
}