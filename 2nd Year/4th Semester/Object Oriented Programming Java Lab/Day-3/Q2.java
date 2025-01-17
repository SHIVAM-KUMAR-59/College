
// WAP to calculate the area of a triangle using default constructor
class Rectangle{
    int length;
    int width;
    int area;

    Rectangle(){
        length = 3;
        width = 4;
        area = length * width;
    }

    void displayArea(){
        System.out.println("Area:" + area);
    }
}

class Demo{
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        r.displayArea();
    }
}
