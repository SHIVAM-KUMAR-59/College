package p2;

public class Contract_empsalary {
    private double hourlyRate;

    public Contract_empsalary(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }

    public void displaySalary() {
        System.out.println("Contract Employee Hourly Rate = $" + hourlyRate);
    }
}
