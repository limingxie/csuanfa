#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        long long res = a + b;

        if (a > 0 && b > 0 && res < 0)
        {
            printf("Case #%d: true\n", i);
        }
        else if (a < 0 && b < 0 && res >= 0)
        {
            printf("Case #%d: false\n", i);
        }
        else if (a + b > c)
        {
            printf("Case #%d: true\n", i);
        }
        else
        {
            printf("Case #%d: false\n", i);
        }
    }
}

//g++ a1065/*.cpp -o 3.out && ./3.out