
#include <stdio.h>

void b1001(int &step, int n)
{
    if (n == 1 or n == 0)
    {
        return;
    }

    if (n % 2 == 0)
    {
        n = n / 2;
    }
    else
    {
        n = (3 * n + 1) / 2;
    }

    step = step + 1;

    b1001(step, n);
}

int main()
{
    int step = 0;
    int n = 0;

    scanf("%d", &n);
    b1001(step, n);
    printf("%d\n", step);
    return 0;
}


// int main()
// {
//     int step = 0;
//     int n = 0;

//     scanf("%d", &n);
//     while (n != 1)
//     {
//         if (n % 2 == 0)
//         {
//             n = n / 2;
//         }
//         else
//         {
//             n = (3 * n + 1) / 2;
//         }
//         step++;
//     }
//     printf("%d\n", step);
//     return 0;
// }
