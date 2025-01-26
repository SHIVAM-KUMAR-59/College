package p2;

public class Design extends Check {
    public void displayResults(int number) {
        System.out.println("Number: " + number);
        System.out.println("Is Prime: " + prime(number));
        System.out.println("Is Odd: " + odd(number));
    }

    public static void main(String[] args) {
        Design design = new Design();

        // Test with some numbers
        int[] testNumbers = {2, 3, 4, 5, 9, 11};
        for (int number : testNumbers) {
            design.displayResults(number);
            System.out.println("------------------");
        }
    }
}
