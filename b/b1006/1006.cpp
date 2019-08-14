#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int a = 0, b = 0, c = 0;
    c = n % 10;
    b = ((n / 10) % 10);
    a = (n / 100) % 10;

    for (int i = 0; i < a; i++)
    {
        printf("%c", 'B');
    }

    for (int i = 0; i < b; i++)
    {
        printf("%c", 'S');
    }

    for (int i = 0; i < c; i++)
    {
        printf("%d", i + 1);
    }

    return 0;
}

//g++ b1006/*.cpp -o b.out && ./b.out