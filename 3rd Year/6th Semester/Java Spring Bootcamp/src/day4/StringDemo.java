package day4;

public class StringDemo {

	public static void main(String[] args) {
		
		String date1 = "06-02-2026";
		String date2 = "07-02-2026";
		String date3 = "08-02-2026";
		
		String description1 = "ATM Withdrawl";
		String description2 = "Salary Credit";
		String description3 = "Online Shopping";
		
		float debit1 = 2000;
		float debit2 = 0;
		float debit3 = 3500;
		
		float credit1 = 0;
		float credit2 = 25000;
		float credit3 = 0;
		
		float balance1 = 18000;
		float balance2 = 43000;
		float balance3 = 39500;
		
		System.out.println(String.format("Date: %s Description: %s Amount debited: %.2f Amount credited: %.2f Net balance: %.2f", date1, description1, debit1, credit1, balance1));
		System.out.println(String.format("Date: %s Description: %s Amount debited: %.2f Amount credited: %.2f Net balance: %.2f", date2, description2, debit2, credit2, balance2));
		System.out.println(String.format("Date: %s Description: %s Amount debited: %.2f Amount credited: %.2f Net balance: %.2f", date3, description3, debit3, credit3, balance3));

	}

}
