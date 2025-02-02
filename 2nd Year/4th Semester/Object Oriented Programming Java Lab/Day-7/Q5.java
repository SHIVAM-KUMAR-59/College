/*
Create an user defined exception named CheckArgument to check the number of
arguments passed through command line. If the number of arguments is less than four then
throw the Check Argument exception, else print the addition of squares of all the four
elements.

Input: 4 3 2 1
Output: 30
Input: 4 3 2
Output: Exception occurred - CheckArgument
 */

 class CheckArgument extends RuntimeException{
     CheckArgument(String msg){
         super(msg);
     }
 }

 class Q5{
     public static void main(String[] args) {
         if(args.length < 4){
             throw new CheckArgument("Too few arguments");
         }else{
             int sum = 0;
             for(int i = 0; i < args.length; i++){
                 sum += Integer.parseInt(args[i]) * Integer.parseInt(args[i]);
             }
             System.out.println(sum);
         }
     }
 }