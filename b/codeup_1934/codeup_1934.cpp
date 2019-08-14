#include <cstdio>

int a[210] = {0};

int main()
{
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);

    int k = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            k = i;
            break;
        }
    }

    printf("%d\n", k);

    return 0;
}

//g++ codeup_1934/*.cpp -o a.out && ./a.out