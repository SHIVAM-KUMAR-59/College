/*
Aim of the program: Write a class Account containing acc_no, balance as data members and
two methods as input() for taking input from user and disp() method to display the details.
Create a subclass Person which has name and aadhar_no as extra data members and
override disp() function. Write the complete program to take and print details of three
persons.
Input: Enter details of three persons
Output: Display details of three persons
 */

 import java.util.*;
 class Account{
    int acc_no;
    float balance;
    void input(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter account number: ");
        acc_no = sc.nextInt();
        System.out.println("Enter balance: ");
        balance = sc.nextFloat();
    }
    void disp(){
        System.out.println("Account number: "+acc_no);
        System.out.println("Balance: "+balance);
    }
 }
 class Person extends Account{
    String name;
    long aadhar_no;
    void input(){
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name: ");
        name = sc.next();
        System.out.println("Enter aadhar number: ");
        aadhar_no = sc.nextLong();
    }
    void disp(){
        super.disp();
        System.out.println("Name: "+name);
        System.out.println("Aadhar number: "+aadhar_no);
    }
 }

 class Demo{
    public static void main(String[] args){
        Person p1 = new Person();
        p1.input();
        p1.disp();
    }
 }