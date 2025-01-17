/*
 * WAP to print name, roll number, section and branch in seperate lines (user provides the input through command line prompt).
 */

public class Q5 {
    public static void main(String[] args) {
        System.out.println("Name: " + args[0]);
        System.out.println("Roll Number: " + args[1]);
        System.out.println("Section: " + args[2]);
        System.out.println("Branch: " + args[3]);
    }
}

/*
 * $ javac Q5.java
 * $ java Q5 "Shivam Kumar" 2305XXXX CSE-23 CSE
 * Output:
 * Name: Shivam Kumar
 * Roll Number: 2305XXXX
 * Section: CSE-23
 * Branch: CSE
 */
