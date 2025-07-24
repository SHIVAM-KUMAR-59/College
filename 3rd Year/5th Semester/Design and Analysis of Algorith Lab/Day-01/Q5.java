// Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2 elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.

import java.util.*;

public class Q5 {

    private static void exchange(int[] arr, int p, int q) {
        int temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
    }

    private static void rotateRight(int[] arr, int rotate) {
        for (int i = rotate - 1; i > 0; i--) {
            exchange(arr, i, i - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Rotate first how many elements (p2): ");
        int rotate = sc.nextInt();
        System.out.println("Before rotation: " + Arrays.toString(arr));
        rotateRight(arr, rotate);
        System.out.println("After rotation:  " + Arrays.toString(arr));

        sc.close();
    }
}
