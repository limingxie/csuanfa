#include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int z[100], num = 0;
    do
    {
        z[num] = a % b;
        a = a / b;
        num++;
    } while (a != 0);

    bool flag = true;

    for (int i = 0; i < num / 2; i++)
    {
        if (z[i] != z[num - 1 - i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    for (int i = num - 1; i >= 0; i--)
    {
        if (i != num - 1)
            printf(" ");

        printf("%d", z[i]);
    }
    return 0;
}

//g++ a1019/*.cpp -o 3.out && ./3.out