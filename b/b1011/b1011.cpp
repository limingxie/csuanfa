#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a + b > c)
        {
            printf("Case #%d: true\n", i);
        }
        else
        {
            printf("Case #%d: false\n", i);
        }
    }

    return 0;
}

//g++ b1011/*.cpp -o b1011.out && ./b1011.out