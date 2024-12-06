/*
 * Print all prime numbers from 1 to 500
 */

 public class Assignment2{
    public static void main(String[] args) {
        System.out.println("Prime Numbers between 1 and 500 are:");
        for (int i = 1; i <= 500; i++) {
            int flag = 0;
            for(int j = 2; (j * j) < i; j++){
                if(i % j == 0){
                    flag = 1;
                }
            }
            if(flag == 0){
                System.out.print(i + ", ");
            }
        }
    }
 }