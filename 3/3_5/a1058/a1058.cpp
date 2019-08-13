#include <cstdio>

int main()
{
    int a[3], b[3], v[3];
    scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);

    v[2] = (a[2] + b[2]) % 29;
    v[1] = ((a[1] + b[1] + (a[2] + b[2])/29)) % 17;
    v[0]= a[0] + b[0] + ((a[1] + b[1] + (a[2] + b[2])/29))/17;

    printf("%d.%d.%d", v[0],v[1],v[2]);
    return 0;
}

//g++ a1058/*.cpp -o 3.out && ./3.out