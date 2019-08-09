#include <cstdio>

int main()
{
    bool isFirst = true;
    int a, b;
    int a1, b1;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        a1 = a * b;
        b1 = b - 1;

        if (isFirst)
        {
            if (b1 != -1)
            {
                printf("%d %d", a1, b1);
            }
            else 
            {
                printf("%d %d", 0, 0);
            }
            isFirst = false;
        }
        else
        {
            if (b1 != -1)
            {
                printf(" %d %d", a1, b1);
            }
        }
    }
}

//g++ b1010/*.cpp -o 3.out && ./3.out