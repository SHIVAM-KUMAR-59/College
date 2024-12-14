
/*
 * WAP to take 10 integers input from command line prompt and check how many of them are even and odd.
 */

public class Q3 {
    public static void main(String[] args) {
        int[] arr = new int[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = Integer.parseInt(args[i]);
        }
        int even = 0, odd = 0;
        for (int i = 0; i < 10; i++) {
            if (arr[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        System.out.println("Even numbers: " + even);
        System.out.println("Odd numbers: " + odd);
    }
}

/*
 * $ javac Q3.java
 * $ java Q3 0 1 2 3 4 5 6 7 8 9
 * Output:
 * Even numbers: 5
 * Odd numbers: 5
 */
