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

//g++ b1010/*.cpp -o 3.out && ./3.out



/* 
#include<stdio.h>
int main()
{
    int i=1;
    int a,a1;
    int b,b1;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        a1 = a*b;
        b1 = b - 1;
             
        if (i)     
        {          
            if (b1 != -1)      
            {
                printf("%d %d", a1, b1);        //第一个数前面无空格
                i = 0;
            }
        }
        else
        {
            if (b1 != -1)
                printf(" %d %d", a1, b1);       //之后的数设置前空格，这样最后一个数后面就不会有空格
        }
        if (i)
            printf("%d %d", 0, 0);
    }
}
*/