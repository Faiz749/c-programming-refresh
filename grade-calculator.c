#include <stdio.h>

int main(void)
{
    int obtained, total;
    float percentage;

    printf("Enter obtained marks: ");
    scanf("%d", &obtained);

    printf("Enter total marks: ");
    scanf("%d", &total);

    if (obtained < 0)
    {
        printf("Invalid obtained marks\n");
    }
    else if (total <= 0)
    {
        printf("Invalid total marks\n");
    }
    else if (obtained > total)
    {
        printf("Invalid marks\n");
    }
    else
    {
        percentage = (float) obtained / total * 100;

        printf("Percentage: %.2f%%\n", percentage);

        if (percentage >= 90)
        {
            printf("Grade: A+ \n");
            printf("Status : Pass");
        }
        else if (percentage >= 80)
        {
            printf("Grade: A\n");
             printf("Status : Pass");
        }
        else if (percentage >= 70)
        {
            printf("Grade: B\n");
            printf("Status : Pass");
        }
        else if (percentage >= 60)
        {
            printf("Grade: C\n");
            printf("Status : Pass");
        }
        else if (percentage >= 50)
        {
            printf("Grade: D\n");
            printf("Status : Pass");
        }
        else
        {
            printf("Grade: Fail\n");
            printf("Status : Fail");
        }
    }

    return 0;
}