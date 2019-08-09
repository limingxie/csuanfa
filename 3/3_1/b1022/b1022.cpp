#include <cstdio>

int main()
{
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);

    int sum = a + b;
    int num = 0;
    int c[31] = {0};
    do
    {
        c[num] = sum % p;
        sum = sum / p;
        num++;
    } while (sum != 0);

    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d", c[i]);
    }
    
    printf("\n");
    return 0;
}

//g++ b1022/*.cpp -o b1022.out && ./b1022.out