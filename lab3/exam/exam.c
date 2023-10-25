#include <stdio.h>
#include <stdlib.h>

typedef struct subj
{
    int sub1;
    int sub2;
    int sub3;
} Subject;

int main()
{
    int n;
    scanf("%d", &n);
    int data[n][3];
    double sum = 0;
    double sub1 = 0, sub2 = 0, sub3 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &data[i][j]);
            sum += data[i][j];
            if (j == 0)
            {
                sub1 += data[i][0];
            }
            else if (j == 1)
            {
                sub2 += data[i][1];
            }
            else
            {
                sub3 += data[i][2];
            }
        }
    }
    double average = sum / n;
    double averageSub1 = sub1 / n;
    double averageSub2 = sub2 / n;
    double averageSub3 = sub3 / n;
    for (int i = 0; i < n; i++)
    {
        int moreThan = 0;
        int sumBLongI = 0;
        int haveZero = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0 && data[i][j] >= averageSub1)
            {
                moreThan += 1;
            }
            else if (j == 1 && data[i][j] >= averageSub2)
            {
                moreThan += 1;
            }
            else if (j == 2 && data[i][j] >= averageSub3)
            {
                moreThan += 1;
            }
            if (data[i][j] == 0)
            {
                haveZero = 1;
            }
            sumBLongI += data[i][j];
        }
        if (moreThan >= 2 && sumBLongI >= average && haveZero != 1)
        {
            printf("%d ", i + 1);
        }
    }
}