/*
Create an interface currency that contains two methods moneyconversion() and
countrycurrency() methods. Create a class CurrencyConversion to implement the currency interface
and its methods. In the main method class create an object for the class to invoke the methods of
the interface and test it.
 */

 import java.util.*;
 interface Currency {
    void moneyconversion();
    void countrycurrency();
 }
 class CurrencyConversion implements Currency {
    public void moneyconversion() {
        System.out.println("Money Conversion");
    }
    public void countrycurrency() {
        System.out.println("Country Currency");
    }
 }
 class Demo {
    public static void main(String[] args) {
        CurrencyConversion obj = new CurrencyConversion();
        obj.moneyconversion();
        obj.countrycurrency();
    }
 }