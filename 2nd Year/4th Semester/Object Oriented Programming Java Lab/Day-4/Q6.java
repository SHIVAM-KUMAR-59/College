/*
Illustrate the execution of constructors in multi-level inheritance with three Java classes –
plate(length, width), box(length, width, height), wood box (length, width, height, thick)
where box inherits from plate and woodbox inherits from box class. Each class has
constructor where dimensions are taken from user.
Input: Enter the dimensions
Output: Display the dimensions accordingly
 */

import java.util.*;
class Plate {
    int length;
    int width;
    Plate(int length, int width) {
        this.length = length;
        this.width = width;
    }
}
class Box extends Plate {
    int height;
    Box(int length, int width, int height) {
        super(length, width);
        this.height = height;
    }
}
class WoodBox extends Box {
    int thickness;
    WoodBox(int length, int width, int height, int thickness) {
        super(length, width, height);
        this.thickness = thickness;
    }
}
class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the dimensions: ");
        int length = sc.nextInt();
        int width = sc.nextInt();
        int height = sc.nextInt();
        int thickness = sc.nextInt();
        WoodBox wb = new WoodBox(length, width, height, thickness);
        System.out.println("Length: " + wb.length);
        System.out.println("Width: " + wb.width);
        System.out.println("Height: " + wb.height);
        System.out.println("Thickness: " + wb.thickness);
    }
}