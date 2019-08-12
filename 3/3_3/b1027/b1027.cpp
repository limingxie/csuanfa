#include <cstdio>
#include <cmath>

/*
int main()
{
    int n;
    char s;
    scanf("%d %c", &n, &s);

    int bt;
    bt = (int)sqrt(2.0 * (n + 1)) - 1;
    if (bt % 2 == 0)
        bt--;
    int used;
    if (n <= 0)
        used = 0;
    else
        used = (bt + 1) * (bt + 1) / 2 - 1;

    for (int i = 1; i <= (bt + 1) / 2; i++)
    {
        for (int j = 1; j <= bt; j++)
        {
            if (i > j || bt < i + j - 1)
            {
                printf(" ");
            }
            else
            {
                printf("%c", s);
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= (bt - 1) / 2; i++)
    {
        for (int j = 1; j <= bt; j++)
        {
            if ((bt + 1) / 2 - i > j || (bt + 1) / 2 + i < j)
            {
                printf(" ");
            }
            else
            {
                printf("%c", s);
            }
        }
        printf("\n");
    }
    printf("%d", n - used);
    printf("\n");
    return 0;
}
*/
//g++ b1027/*.cpp -o 3.out && ./3.out

int main()
{
    int n;
    char s;
    scanf("%d %c", &n, &s);

    int bt;
    bt = (int)sqrt(2.0 * (n + 1)) - 1;
    if (bt % 2 == 0)
        bt--;
    int used;
    if (n <= 0)
        used = 0;
    else
        used = (bt + 1) * (bt + 1) / 2 - 1;

    for (int i = 0; i < (bt + 1) / 2; i++)
    {
        for (int j = 0; j < bt; j++)
        {
            if (i > j)
            {
                printf(" ");
            }
            else if( bt  > i + j)
            {
                printf("%c", s);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < (bt - 1) / 2; i++)
    {
        for (int j = 0; j < bt; j++)
        {
            if (bt/2 - 1 > j + i)
            {
                printf(" ");
            }
            else if(bt/2 + i + 2 > j)
            {
                printf("%c", s);
            }
        }
        printf("\n");
    }
    printf("%d", n - used);
    printf("\n");

    return 0;
}