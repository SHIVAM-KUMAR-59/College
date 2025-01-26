package p3;

import p1.Employee as RegularEmployee; // Alias to resolve conflicts
import p1.Regular_empsalary;
import p2.Employee as ContractEmployee; // Alias to resolve conflicts
import p2.Contract_empsalary;

public class Empdetails {
    public static void main(String[] args) {
        // p1.Employee instance
        RegularEmployee regularEmp = new RegularEmployee("Alice", 101);
        regularEmp.displayDetails();

        Regular_empsalary regularSalary = new Regular_empsalary(60000);
        regularSalary.displaySalary();

        // p2.Employee instance
        ContractEmployee contractEmp = new ContractEmployee("Bob", 202);
        contractEmp.displayDetails();

        Contract_empsalary contractSalary = new Contract_empsalary(50);
        contractSalary.displaySalary();
    }
}
