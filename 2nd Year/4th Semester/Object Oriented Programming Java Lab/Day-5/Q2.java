/*
Aim of the program: Write a program in Java having three classes A, B and C. Class B and C
are inherited from class A and each class have their own member function show() . Using
Dynamic Method Dispatch concept display all the show() method of each class.
Input: Mention show function of each class in the program
Output: Display show function of each class accordingly
 */

import java.util.*;
class A{
    void show(){
        System.out.println("Class A");
    }
}

class B extends A{
    void show(){
        System.out.println("Class B");
    }
}

class C extends B{
    void show(){
        System.out.println("Class C");
    }
}

class Demo{
    public static void main(String[] args) {
        A ob1 = new A();
        A ob2 = new B();
        A ob3 = new C();
        
        ob1.show();
        ob2.show();
        ob3.show();
    }
}