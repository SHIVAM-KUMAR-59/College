package p2;

import p1.Prime;
import p1.Odd;

public class Check implements Prime, Odd {

    public boolean prime(int number) {
        if (number <= 1) return false;
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    public boolean odd(int number) {
        return number % 2 != 0;
    }
}
