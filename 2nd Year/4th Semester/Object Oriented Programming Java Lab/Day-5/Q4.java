/*
Write a class Complex in Java with two data members -real, img and overloaded constructors.
It contains two methods - Swap() and Sum(). Swap method interchanges the values of real
and img of an object and Sum method adds two complex numbers and returns a new complex
object. Write the complete program to check the functionality of both the methods.
 */

import java.util.*;

class Complex {
    double real, img;
    public Complex(double real, double img) {
        this.real = real;
        this.img = img;
    }
    public void Swap() {
        double temp = this.real;
        this.real = this.img;
        this.img = temp;
    }
    public Complex Sum(Complex c) {
        double real = this.real + c.real;
        double img = this.img + c.img;
        return new Complex(real, img);
    }
    public void print() {
        System.out.println(this.real + " + " + this.img + "i");
    }
}

class Demo{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the real and imaginary part of first complex number:");
        double real1 = sc.nextDouble();
        double img1 = sc.nextDouble();
        System.out.println("Enter the real and imaginary part of second complex number:");
        double real2 = sc.nextDouble();
        double img2 = sc.nextDouble();
        Complex c1 = new Complex(real1, img1);
        Complex c2 = new Complex(real2, img2);
        System.out.println("First complex number: ");
        c1.print();
        System.out.println("Second complex number: ");
        c2.print();
        c1.Swap();
        c2.Swap();
        System.out.println("After swapping: ");
        System.out.println("First complex number: ");
        c1.print();
        System.out.println("Second complex number: ");
        c2.print();
        Complex c3 = c1.Sum(c2);
        System.out.println("Sum of two complex numbers: ");
        c3.print();
    }
}