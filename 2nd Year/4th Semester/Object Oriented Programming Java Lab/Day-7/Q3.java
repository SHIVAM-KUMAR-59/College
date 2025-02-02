/*
Write a Java class which has a method called ProcessInput(). This method checks the
number entered by the user. If the entered number is negative then throw an user defined
exception called NegativeNumberException, otherwise it displays the double value of the
entered number.
Input: Enter a number 4
Output: Double value: 8
Input: Enter a number -4
Output: Caught the exception Exception occurred: NegativeNumberException: number should be positive
 */

 import java.util.*;
 class NegativeNumberException extends RuntimeException{
    public NegativeNumberException(String message){
        super(message);
    }
 }

 class Check{
    void processInput(int n){
        if(n < 0){
            throw new NegativeNumberException("number should be positive");
        }else{
            System.out.println(n * 2);
        }
    }
 }

 class Q3{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int n = sc.nextInt();
        Check c = new Check();
        c.processInput(n);
    }
 }