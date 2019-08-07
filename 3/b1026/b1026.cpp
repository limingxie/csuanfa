#include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int r = b - a;
    int v = 0;
    if (r % 100 >= 50)
        v = r / 100 + 1;
    else
        v = r / 100;

    printf("%02d:%02d:%02d", v / 3600, (v % 3600) / 60, v % 60);

    return 0;
}

//g++ b1026/*.cpp -o b1026.out && ./b1026.out