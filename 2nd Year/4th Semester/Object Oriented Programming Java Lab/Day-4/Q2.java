/*
Write a program in Java to create a class Rectangle having data members length and breadth
and three methods called read, calculate and display to read the values of length and
breadth, calculate the area and perimeter of the rectangle and display the result
respectively.
Input: Enter length and breadth of a rectangle
Output: Display area and perimeter of rectangle
 */

import java.util.*;
class Rectangle{
    int length, breadth, area, volume;
    void read(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length and breadth of a rectangle: ");
        this.length = sc.nextInt();
        this.breadth = sc.nextInt();
    }
    void calculate(){
        this.area = length*breadth;
        this.volume = 2*(length+breadth);
    }
    void display(){
        System.out.println("Length of rectangle: " + this.length);
        System.out.println("Breadth of rectangle: " + this.breadth);
        System.out.println("Area of rectangle: " + this.area);
        System.out.println("Perimeter of rectangle: " + this.volume);
    }
}
class Demo{
    public static void main(String[] args){
        Rectangle r = new Rectangle();
        r.read();
        r.calculate();
        r.display();
    }
}