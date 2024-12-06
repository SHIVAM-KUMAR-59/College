/*
 * WAP to display following pattern:
 * 9
 * 8 7
 * 6 5 4
 * 3 2 1 0
 */
public class Assignment5 {
    public static void main(String[] args) {
        int num = 9; // Starting number
        for (int i = 1; i <= 4; i++) { // Outer loop for rows
            for (int j = 1; j <= i; j++) { // Inner loop for columns
                System.out.print(num + " ");
                num--; // Decrease the number
            }
            System.out.println(); // Move to the next line after each row
        }
    }
}