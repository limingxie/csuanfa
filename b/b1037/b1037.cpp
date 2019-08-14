#include <cstdio>

int main()
{
    int a1, b1, c1,a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int sum = ((a2*17 + b2) * 29 + c2) -((a1*17 + b1) * 29 + c1);
   if (sum < 0)
   {
       printf("-");
       sum = -sum;
   }

   printf("%d.%d.%d", sum/(17*29), (sum % (17 * 29))/29, sum % 29);
    return 0;
}

//g++ b1037/*.cpp -o 3.out && ./3.out