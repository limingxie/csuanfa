#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int fa = 0, fb = 0;
    for (int i = 1; i <= n; i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (a + c == b && a + c != d)
        {
            fb++;
        }
        else if (a + c != b && a + c == d)
        {
            fa++;
        }
    }
    printf("%d %d", fa, fb);
}

//g++ b1046/*.cpp -o b1046.out && ./b1046.out