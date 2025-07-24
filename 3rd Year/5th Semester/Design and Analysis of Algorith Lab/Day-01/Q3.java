// Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

import java.util.*;
public class Q3 {
    public static void main(String []args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array: ");
        int n = sc.nextInt();
        System.out.println("Enter elements");
        int []arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int sum = 0;
        int []ans = new int[n];
        for(int i = 0; i < n; i++) {
            sum = sum + arr[i];
            ans[i] = sum;
        }

        System.out.println("Cummulative array: ");
        System.out.println(Arrays.toString(ans));

        sc.close();
    }
}