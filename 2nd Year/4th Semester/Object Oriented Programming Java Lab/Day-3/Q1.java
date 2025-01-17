// WAP to calculate area of a rectangle without using constructor

class Rectangle{
    int length;
    int width;
    void area(int l, int b){
        System.out.println("Area:" + l*b);
    }
}

class Demo{
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        r.length = 10;
        r.width = 5;
        r.area(r.length, r.width);
    }
}
