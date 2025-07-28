// WAP to assign values to each member of the following struct: 
/*
struct student_info {
    int roll_no;
    char name[20];
    float CGPA;
    struct dob age;
};
pass to function using call by value and call by referrence and print value of each member of structure
*/
#include<stdio.h>

struct dob {
    int date;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[20];
    float CGPA;
    struct dob age;
};

void callByValue(struct student_info student) {
    printf("Passing by value...\n");
    printf("Roll: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CPGA: %f\n", student.CGPA);
    printf("DOB: %d/%d/%d\n", student.age.date, student.age.month, student.age.year);
}

void callByReference(struct student_info *student) {
    printf("Passing by reference...\n");
    printf("Roll: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CPGA: %f\n", student->CGPA);
    printf("DOB: %d/%d/%d\n", student->age.date, student->age.month, student->age.year);
}

int main(){
    struct student_info s1 = {20, "Shivam", 9.05, {20, 6, 2005}};
    callByValue(s1);
    callByReference(&s1);
    return 0;
}