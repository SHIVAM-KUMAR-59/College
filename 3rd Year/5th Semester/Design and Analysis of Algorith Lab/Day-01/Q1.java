// Write a program to find out the smallest and largest element stored in an array of n integers. 
// Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.

import java.util.*;
public class Q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array: ");
        int n = sc.nextInt();
        System.out.println("Enter elements");
        int []arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int largest = Integer.MIN_VALUE;
        int smallest = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++) {
            if(arr[i] > largest) {
                largest = arr[i];
            }
            if(arr[i] < smallest) {
                smallest = arr[i];
            }
        }

        System.out.println("Largest: " + largest + " Smallest: " + smallest);

        sc.close();
    }
}