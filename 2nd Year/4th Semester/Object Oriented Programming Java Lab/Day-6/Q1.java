/*
Create the abstract base class Student with basic details of students as data members and
abstract method of marks(). Then create two subclasses called CIA and Semester classes. These two
subclasses should implement the marks() method. Then create objects for each subclass to invoke its
methods and test it.
 */

 import java.util.*;
 abstract class Student{
    String name;
    int roll_no;
    abstract void marks();
 }
 class CIA extends Student{
    int marks;
    void marks(){
        System.out.println("Marks of student: "+marks);
    }
 }
 class Semester extends Student{
    int marks;
    void marks(){
        System.out.println("Marks of student: "+marks);
    }
 }
 public class Q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name of student: ");
        String name = sc.nextLine();
        System.out.println("Enter the roll number of student: ");
        int roll_no = sc.nextInt();
        System.out.println("Enter the marks of student: ");
        int marks = sc.nextInt();
        CIA c = new CIA();
        c.name = name;
        c.roll_no = roll_no;
        c.marks = marks;
        c.marks();
        Semester s = new Semester();
        s.name = name;
        s.roll_no = roll_no;
        s.marks = marks;
        s.marks();
    }
 }