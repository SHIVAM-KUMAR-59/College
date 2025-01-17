// WAP to calculate area of rectangle using parameterized constructor and command line argument

class Rectangle{
    int length;
    int width;
    int area;
    Rectangle(int l, int b){
        length = l;
        width = b;
        area = length * width;
    }

    void displayArea(){
        System.out.println("Area:" + area);
    }
}

class Demo{
    public static void main(String[] args){
        Rectangle r = new Rectangle(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        r.displayArea();
    }
}