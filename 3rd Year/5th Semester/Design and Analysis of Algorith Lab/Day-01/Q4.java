// Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
// a)Find out the total number of duplicate elements.
// b)Find out the most repeating element in the array.

import java.util.*;

public class Q4 {

    // Function to count duplicate elements
    private static int totalDuplicateElement(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0;

        for (int val : arr) {
            map.put(val, map.getOrDefault(val, 0) + 1);
        }

        for (int freq : map.values()) {
            if (freq > 1) {
                count++;
            }
        }

        return count;
    }

    // Function to find the most repeating element
    private static int mostRepeatingElement(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxFreq = 0;
        int maxVal = arr[0];

        for (int val : arr) {
            map.put(val, map.getOrDefault(val, 0) + 1);
            if (map.get(val) > maxFreq) {
                maxFreq = map.get(val);
                maxVal = val;
            }
        }

        return maxVal;
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

        int totalDuplicates = totalDuplicateElement(arr);
        int mostFrequent = mostRepeatingElement(arr);

        System.out.println("Total number of duplicate elements: " + totalDuplicates);
        System.out.println("Most repeating element: " + mostFrequent);

        sc.close();
    }
}
