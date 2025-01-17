/*
Write a class file – box with three data members (length, width, height) and a method
volume (). Also implement the application class Demo where an object of the box class is
created with user entered dimensions and volume is printed.
Input: Enter length, width and height of a box
Output: Display the calculated volume of box
 */

import java.util.*;
class Box{
    int length;
    int width;
    int height;
    int volume(){
        return this.length * this.width * this.height;
    }
}
class Demo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Box b = new Box();
        System.out.println("Enter length of box: ");
        b.length = sc.nextInt();
        System.out.println("Enter width of box: ");
        b.width = sc.nextInt();
        System.out.println("Enter height of box: ");
        b.height = sc.nextInt();
        System.out.println("Volume of box is: " + b.volume());
    }
}