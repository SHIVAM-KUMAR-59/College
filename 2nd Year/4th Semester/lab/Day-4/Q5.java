/*
Write a program in java using constructor overloading concept to calculate the area of a
rectangle having data member as length and breadth. Use default constructor to initialize
the value of the data member to zero and parameterized constructor to initialize the value
of data member according to the user input.
Input: Enter the value of length and breadth of rectangle
Output: Display the area of rectangle accordingly.
 */

import java.util.*;
class Rectangle{
    int length;
    int breadth;
    Rectangle(){
        this.length = 0;
        this.breadth = 0;
    }
    Rectangle(int l, int b){
        this.length = l;
        this.breadth = b;
    }
    void area(){
        System.out.println("Area of rectangle: " + this.length * this.breadth);
    }
}

class Demo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Rectangle r = new Rectangle();
        System.out.println("Enter length and breadth of a rectangle: ");
        r.length = sc.nextInt();
        r.breadth = sc.nextInt();
        r.area();
    }
}