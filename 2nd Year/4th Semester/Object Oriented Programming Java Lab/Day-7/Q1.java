/*
Write a Java program to generate an ArrayIndexOutofBoundsException and handle it using
catch statement.
Input: Enter the numbers -Example: 1 2 3 4 5 (Suppose array size is 4)
Output: Exception in thread “main” java.lang.ArrayIndexOutOfBoundsException:4
 */

 import java.util.*;
 public class Q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[4];
        System.out.println("Enter the numbers:");
        try{
            for(int i=0;i<5;i++){
                arr[i] = sc.nextInt();
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }

    }
 }