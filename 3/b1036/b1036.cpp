#include <cstdio>

int main()
{
    int n, row;
    char s;
    scanf("%d %c", &n, &s);

    for (int i = 0; i < n; i++)
    {
        printf("%c", s);
    }
    printf("\n");

    if (n % 2 == 0)
    {
        row = n / 2 - 2;
    }
    else
    {
        row = n / 2 + 1 - 2;
    }

    for (int i = 0; i < row; i++)
    {
        printf("%c", s);
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        printf("%c\n", s);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", s);
    }
    printf("\n");

    return 0;
}

//g++ b1036/*.cpp -o b1036.out && ./b1036.out