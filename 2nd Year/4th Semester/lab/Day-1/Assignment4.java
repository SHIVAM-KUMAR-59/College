/*
 * WAP to display armstrong number between 2000 to 1
 */
public class Assignment4 {
    public static void main(String[] args) {
        System.out.println("Armstrong numbers from 2000 to 1:");
        
        for (int num = 2000; num >= 1; num--) {
            int sum = 0;
            int digits = 0;

            // Count the number of digits in the number
            int temp = num;
            while (temp > 0) {
                temp /= 10;
                digits++;
            }

            // Calculate the sum of the digits raised to the power of the number of digits
            temp = num;
            while (temp > 0) {
                int digit = temp % 10;
                int power = 1;

                for (int i = 0; i < digits; i++) { // Raise the digit to the power of 'digits'
                    power *= digit;
                }

                sum += power;
                temp /= 10;
            }

            // Check if the number is an Armstrong number
            if (sum == num) {
                System.out.println(num);
            }
        }
    }
}
    
