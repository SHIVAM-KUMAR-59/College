
// WAP to calculate area of rectangle using default constructor and command line argument
class Rectangle{
    int length;
    int width;

    Rectangle(){
        length = 0;
        width = 0;
    }

    void area(int l, int b){
        System.out.println("Area:" + l*b);
    }
}

class Demo{
    public static void main(String args[]){
        Rectangle r = new Rectangle();
        r.area(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
    }
}