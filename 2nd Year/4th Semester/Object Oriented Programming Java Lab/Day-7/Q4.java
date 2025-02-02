/*
Write a program to create user defined exceptions called HrsException, MinException and
SecException. Create a class Time which contains data members hours, minutes, seconds
and a method to take a time from user which throws the user defined exceptions if hours
(&gt;24 &amp; &lt;0), minutes( &gt;60 &amp; &lt;0), seconds (&gt;60 &amp; &lt;0) . 4:54:34
Input: Enter hours: 4
Enter minutes: 54
Enter seconds: 34
Output: Correct Time-&gt; 4:54:34
Input: Enter hours: 30
Enter minutes: 65
Enter seconds: 65
Output: Caught the exception
Exception occurred: InvalidHourException:hour is not greater than 24
Exception occurred: InvalidMinuteException:hour is not greater than 60
Exception occurred: InvalidSecondException:hour is not greater than 60
 */

 import java.util.*;
class HrsException extends RuntimeException{
    public HrsException(String message){
        super(message);
    }
}

class MinException extends RuntimeException{
    public MinException(String message){
        super(message);
    }
}

class SecException extends RuntimeException{
    public SecException(String message){
        super(message);
    }
}
class Time{
    int hours;
    int minutes;
    int seconds;
    Time(int hours, int minutes, int seconds){
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }
}

class Q4{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter hours: ");
        int hours = sc.nextInt();
        System.out.println("Enter minutes: ");
        int minutes = sc.nextInt();
        System.out.println("Enter seconds: ");
        int seconds = sc.nextInt();
        if(hours > 24 || hours < 0){
            throw new HrsException("hour is not greater than 24");
        }
        if(minutes > 60 || minutes < 0){
            throw new MinException("hour is not greater than 60");
        }
        if(seconds > 60 || seconds < 0){
            throw new SecException("hour is not greater than 60");
        }
        Time t = new Time(hours, minutes, seconds);
        System.out.println("Correct Time-> " + hours + ":" + minutes + ":" + seconds);
    }
}

