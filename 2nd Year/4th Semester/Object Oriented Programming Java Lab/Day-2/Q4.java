/*
 * WAP to find the factorial of the given number (the number will be entered by the user through command line prompt)
 */

public class Q4 {
    public static void main(String[] args) {
        int num = Integer.parseInt(args[0]);
        int fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        System.out.println("Factorial of " + num + " is " + fact);
    }
}

/*
 * $ javac Q4.java
 * $ java Q4 5
 * Output: 
 * Factorial of 5 is 120
 */