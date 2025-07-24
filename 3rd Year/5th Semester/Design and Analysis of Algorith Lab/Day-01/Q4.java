// Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
// a)Find out the total number of duplicate elements.
// b)Find out the most repeating element in the array.

import java.util.*;

public class Q4 {

    private static void analyzeDuplicates(int[] arr) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int duplicateCount = 0;
        int mostFreq = 0;
        int mostRepeated = arr[0];

        for (int num : arr) {
            int freq = freqMap.getOrDefault(num, 0) + 1;
            freqMap.put(num, freq);

            if (freq == 2) {
                duplicateCount++; 
            }

            if (freq > mostFreq) {
                mostFreq = freq;
                mostRepeated = num;
            }
        }

        System.out.println("Total number of duplicate elements: " + duplicateCount);
        System.out.println("Most repeating element: " + mostRepeated + " (repeated " + mostFreq + " times)");
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

        analyzeDuplicates(arr);
        sc.close();
    }
}
