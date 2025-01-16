/*
Aim of the program: Write a program to find no. of objects created out of a class using
‘static’ modifier.
Input: Counter variable is set to zero in the program
Output: Display the number of objects created
 */

class Object{
    static int count = 0;
    Object(){
        count++;
    }
}

class Demo{
    public static void main(String[] args) {
        Object obj;
        for(int i = 0;i < 10;i++){
            obj = new Object();
        }
        System.out.println("No. of objects created: " + Object.count);
    }
}