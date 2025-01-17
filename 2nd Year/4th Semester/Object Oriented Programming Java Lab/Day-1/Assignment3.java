/*
 * WAP to display fibonacci series upto 10 elements
 */
public class Assignment3 {
    public static void main(String[] args) {
        int n = 10; // Number of elements in the Fibonacci sequence
        int first = 0, second = 1;
        
        System.out.println("Fibonacci Sequence (First 10 Elements):");
        for (int i = 0; i < n; i++) {
            System.out.print(first + " ");
            // Calculate the next term
            int next = first + second;
            first = second;
            second = next;
        }
    }
}
