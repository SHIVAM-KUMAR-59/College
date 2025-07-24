// Write a program to find out the second smallest and second largest element stored in an array of n integers. 
// Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.

import java.util.*;
public class Q2 {


    private static int secondLargest(int[] arr) {
        int largest = arr[0];
        int secondLargest = -1;

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }else if(arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }

    private static int secondSmallest(int[] arr) {
        int smallest = Integer.MAX_VALUE;
        int secondSmallest = arr[0];

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] < smallest) {
                secondSmallest = smallest;
                smallest = arr[i];
            }else if(arr[i] > smallest && arr[i] < secondSmallest) {
                secondSmallest = arr[i];
            }
        }

        return secondSmallest;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array: ");
        int n = sc.nextInt();
        System.out.println("Enter elements");
        int []arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }


        System.out.println("Second Largest: " + secondLargest(arr) + " Second Smallest: " + secondSmallest(arr));

        sc.close();
    }
}