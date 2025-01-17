// WAP to calculate area of rectangle using parameterized constructor
class Rectangle{
    int length;
    int width;
    int area;
    Rectangle(int l, int b){
        length = l;
        width = b;
        area = length * width;
    }
}

class Demo{
    public static void main(String[] args) {
        Rectangle r = new Rectangle(5, 6);
        System.out.println("Area:" + r.area);
    }
}