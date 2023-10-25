#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[20];
    float score;
} StudentData;

int main()
{
    StudentData student[5];
    float sumScore = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Input student name [%d]: ", i + 1);
        scanf("%s", student[i].name);
        printf("Input student score [%d]: ", i + 1);
        scanf("%f", &student[i].score);
        sumScore += student[i].score;
    }
    float averageScore = sumScore / 5;
    printf("Average is %.2f \n", averageScore);
    printf("-- A group of student have score more than average -- \n");
    for (int x = 0; x < 5; x++)
    {
        if (student[x].score >= averageScore)
        {
            printf("Name: %s \n", student[x].name);
            printf("Score: %.2f \n", student[x].score);
        }
    }

    return 0;
}