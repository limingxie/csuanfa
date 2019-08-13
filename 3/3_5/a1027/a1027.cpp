#include <cstdio>

int main()
{
    char r[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("#");
    printf("%c%c", r[a / 13], r[a % 13]);
    printf("%c%c", r[b / 13], r[b % 13]);
    printf("%c%c", r[c / 13], r[c % 13]);

    return 0;
}

//g++ a1027/*.cpp -o 3.out && ./3.out