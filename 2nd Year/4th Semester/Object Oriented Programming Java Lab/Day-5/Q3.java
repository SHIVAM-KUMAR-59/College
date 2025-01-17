/*
Write a program in java to create an abstract class Shape with two abstract methods
getArea() , getPerimeter() and a non-abstract printInfo() method. Create two subclasses
Circle and Rectangle, each implementing these abstract methods. The application Demo
class demonstrates the usage of these classes by creating objects of Circle and Rectangle
and invoking their methods.
 */

 import java.util.*;
 abstract class Shape{
     abstract double getArea();
     abstract double getPerimeter();
     void printInfo(double area, double perimeter){
         System.out.println("Area: " + area);
         System.out.println("Perimeter: " + perimeter);
     }
 }
 class Circle extends Shape{
    double radius;
    Circle(double radius){
        this.radius = radius;
    }

    double getArea(){
        return Math.PI * this.radius * this.radius;
    }

    double getPerimeter(){
        return 2 * Math.PI * this.radius;
    }
 }

 class Rectangle extends Shape{
    double length;
    double breadth;
    Rectangle(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }
    double getArea(){
        return this.length * this.breadth;
    }
    double getPerimeter(){
        return 2 * (this.length + this.breadth);
    }
}

 class Demo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter radius of circle:");
        double radius = sc.nextDouble();
        Circle circle = new Circle(radius);
        circle.printInfo(circle.getArea(), circle.getPerimeter());
        System.out.println("Enter length and breadth of rectangle:");
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        Rectangle rectangle = new Rectangle(length, breadth);
        rectangle.printInfo(rectangle.getArea(), rectangle.getPerimeter());
    }
}