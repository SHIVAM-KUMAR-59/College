/*
 * WAP to find the maximum of 3 numbers take input through command line prompt
 */

public class Q1{
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);
        int max = a;
        if (b > max) {
            max = b;
        }
        if (c > max) {
            max = c;
        }
        System.out.println(max);
    }
}

/*
 * $ javac Q1.java
 * $ java Q1 1 2 3
 * Output: 
 * 3
 */