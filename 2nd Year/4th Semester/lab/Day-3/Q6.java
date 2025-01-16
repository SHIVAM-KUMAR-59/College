// WAP to calculate area of rectangle without constructor and command line argument
class Rectangle{
    int length;
    int width;
    int area;
    void area(int l, int b){
        length = l;
        width = b;
        area = length * width;
    }
}

class Demo{
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        r.area(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        System.out.println("Area:" + r.area);
    }
}