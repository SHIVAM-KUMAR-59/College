// Create a structture to pass 3 student marks of science and maths an return maximum mark of a student and average of all science mark and average of all maths mark

#include <stdio.h>
#include <stdlib.h>

struct marks
{
    int maths;
    int science;
};

void calculations(struct marks *data, int size)
{
    int max_science = 0, max_math = 0, sum_science = 0, sum_maths = 0;
    for (int i = 0; i < size; i++)
    {
        printf("The science marks of student %d is: %d \nand its maths marks is: %d\n", i, data[i].science, data[i].maths);
        sum_science += data[i].science;
        if (data[i].science > max_science)
        {
            max_science = data[i].science;
        }
        sum_maths += data[i].maths;
        if (data[i].maths > max_math)
        {
            max_math = data[i].maths;
        }
    }
    
    printf("The maximum of all maths marks: %d\n", max_math);
    printf("The maximum of all science marks: %d\n", max_science);
    printf("The average of all maths marks: %.2f\n", (float)sum_maths/size);
    printf("The average of all science marks: %.2f\n", (float)sum_science/size);
}

int main()
{
    int size = 3;
    struct marks s[size];
    for (int i = 0; i < size; i++)
    {
        s[i].maths = rand() % 100;
        s[i].science = rand() % 100;
    }
    calculations(s, size);

    return 0;
}