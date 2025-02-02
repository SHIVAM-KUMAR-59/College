/*
Write a Java program to handle an ArithmeticException using try, catch, and finally block.
Input: Operand values for division operation mentioned in the program
Output: ArithmeticException caught by try-catch-finally block
 */

 public class Q2{
    public static void main(String[] args) {
        try{
            int a = 10/0;
        }catch(ArithmeticException e){
            System.out.println("ArithmeticException caught by try-catch-finally block");
        }finally{
            System.out.println("Finally block executed");
        }
    }
 }