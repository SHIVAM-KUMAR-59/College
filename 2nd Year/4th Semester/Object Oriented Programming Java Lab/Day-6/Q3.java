/*
Write an interface called Numbers with a method int Process(int x, int y). Write a class called
Sum in which the process() method finds the sum of two numbers and returns an int value. Write
another class called Average in which the process() method finds the average of the two numbers
and retuns an int value.
 */

import java.util.*;
interface Numbers{
    int Process(int x, int y);
}
class Sum implements Numbers{
    public int Process(int x, int y){
        return x + y;
    }
}
class Average implements Numbers{
    public int Process(int x, int y){
        return (x + y) / 2;
    }
}
class Demo{
    public static void main(String[] args){
        Numbers n = new Sum();
        System.out.println("Sum of 10 and 20 is: " + n.Process(10, 20));
        n = new Average();
        System.out.println("Average of 10 and 20 is: " + n.Process(10, 20));
    }
}