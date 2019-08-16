#include <cstdio>
#include <cstring>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;

    char flag = true;

    if (c < 0)
    {
        flag = false;
        c = c * -1;
    }

    if (flag == false)
    {
        printf("-");
    }

    int v[10];

    int num = 0;
    if (c==0)
    {
         printf("0");
         return 0;
    }
    while (c != 0)
    {
        v[num] = c % 10;
        c = c / 10;
        num++;
    }
    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d", v[i]);
        if (num  % 3 == (num - i) % 3 && i > 0)
        {
            printf(",");
        }
    }

    return 0;
}

//g++ a1001/*.cpp -o a.out && ./a.out