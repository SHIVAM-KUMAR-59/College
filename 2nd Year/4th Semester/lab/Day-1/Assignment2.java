/*
 * WAP to display prime numbers between 1 to 1000
 */

public class Assignment2 {
    public static void main(String[] args) {
        System.out.println("Prime number between 1 to 1000 are");
        for(int i = 1; i <= 500; i++){
            int flag = 0;
            for(int j = 2; j < i; j++){
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
