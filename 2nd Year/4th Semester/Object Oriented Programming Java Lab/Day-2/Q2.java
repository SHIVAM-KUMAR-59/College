/*
 * WAP to print all prime numbers between a user input range, the range should be entered through command line prompt.
 */

 public class Q2{
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        for (int i = a; i <= b; i++) {
            int count = 0;
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    count++;
                    break;
                }
            }
            if (count == 0) {
                System.out.println(i + " ");
            }
        }
    }
}

/*
 * $ javac Q2.java
 * $ java Q2 1 10
 * Output:
 * 1 2 3 5 7
 */
