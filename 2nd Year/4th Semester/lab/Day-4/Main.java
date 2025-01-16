/*
Write a program which will overload the area () method and display the area of a circle,
triangle and square as per user choice and user entered dimensions.
Input: Enter user’s choice number (Eg. Choice=1 -&gt;Area of Circle, Choice=2 - &gt;Area of
Triangle, Choice=3 -&gt;Area of Square) Enter dimensions like radius, base, height, side as per
the entered choice
Output: Display area of circle Display area of triangle Display area of square
 */

 import java.util.Scanner;

 class AreaCalculator {
     // Method to calculate the area of a circle
     public double area(double radius) {
         return Math.PI * radius * radius;
     }
 
     // Method to calculate the area of a triangle
     public double area(double base, double height) {
         return 0.5 * base * height;
     }
 
     // Method to calculate the area of a square
     public double area(int side) {
         return side * side;
     }
 }
 
 public class Main {
     public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);
         AreaCalculator calculator = new AreaCalculator();
 
         System.out.println("Choose an option to calculate area:");
         System.out.println("1: Area of Circle");
         System.out.println("2: Area of Triangle");
         System.out.println("3: Area of Square");
 
         int choice = scanner.nextInt();
 
         switch (choice) {
             case 1:
                 System.out.print("Enter the radius of the circle: ");
                 double radius = scanner.nextDouble();
                 System.out.printf("Area of Circle: %.2f\n", calculator.area(radius));
                 break;
 
             case 2:
                 System.out.print("Enter the base of the triangle: ");
                 double base = scanner.nextDouble();
                 System.out.print("Enter the height of the triangle: ");
                 double height = scanner.nextDouble();
                 System.out.printf("Area of Triangle: %.2f\n", calculator.area(base, height));
                 break;
 
             case 3:
                 System.out.print("Enter the side of the square: ");
                 int side = scanner.nextInt();
                 System.out.printf("Area of Square: %d\n", (int) calculator.area(side));
                 break;
 
             default:
                 System.out.println("Invalid choice. Please choose between 1 and 3.");
         }
 
     }
 }
 