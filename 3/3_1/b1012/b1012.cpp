#include <cstdio>

int main()
{
    int a[5] = {0};
    int c[5] = {0};
    int n = 0, temp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp % 5 == 0)
        {
            if (temp % 2 == 0)
            {
                a[0] += temp;
                c[0]++;
            }
        }
        else if (temp % 5 == 1)
        {
            if (c[1] % 2 == 0)
            {
                a[1] += temp;
            }
            else
            {
                a[1] -= temp;
            }
            c[1]++;
        }
        else if (temp % 5 == 2)
        {
            c[2]++;
        }
        else if (temp % 5 == 3)
        {
            a[3] += temp;
            c[3]++;
        }
        else
        {
            if (temp > a[4])
            {
                a[4] = temp;
                c[4]++;
            }
        }
    }

    if (c[0] == 0)
        printf("N ");
    else
        printf("%d ", a[0]);
    if (c[1] == 0)
        printf("N ");
    else
        printf("%d ", a[1]);
    if (c[2] == 0)
        printf("N ");
    else
        printf("%d ", c[2]);
    if (c[3] == 0)
        printf("N ");
    else
        printf("%.1f ", (double)a[3] / c[3]);
    if (c[4] == 0)
        printf("N");
    else
        printf("%d", a[4]);
}

//g++ b1012/*.cpp -o 3.out && ./3.out