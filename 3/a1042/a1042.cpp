#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    char m[5] = {'S', 'H', 'C', 'D','J'};

    int a[55], b[55], c[55];

    for (int i = 1; i <= 54; i++)
    {
        a[i] = i;
    }

    for (int i = 1; i <= 54; i++)
    {
        scanf("%d", &c[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i < 55; i++)
        {
            b[c[i]] = a[i];
        }

        for (int i = 1; i < 55; i++)
        {
            a[i] = b[i];
        }
    }

    for (int i = 1; i < 55; i++)
    {
        a[i]--;
        printf("%c%d", m[a[i]/13], a[i]%13 + 1);
        if (i < 54){
            printf(" ");
        }
    }
}

//g++ a1042/*.cpp -o 3.out && ./3.out