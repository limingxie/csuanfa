#include <cstdio>
#include <cmath>

int main()
{
    int n;
    char s;
    scanf("%d %c", &n, &s);

    int bt;
    bt = (int)sqrt(2.0 * (n + 1)) - 1;
    if (bt % 2 == 0)
        bt--;
    int used = (bt + 1) * (bt + 1) / 2 - 1;

    for (int i = 1; i <= (bt + 1) / 2; i++)
    {
        for (int j = 1; j <= bt; j++)
        {
            if (i > j || bt  < i + j - 1)
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
            if ((bt + 1)/2 - i > j  ||  bt - i - j + 1 > (bt + 1)/2)
            {
                printf("1");
            }
            else
            {
                printf("%c", s);
            }
        }
        printf("\n");
    }

    return 0;
}

//g++ b1027/*.cpp -o b1036.out && ./b1036.out