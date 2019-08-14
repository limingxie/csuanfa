#include <stdio.h>

void b1001(int &step, int n){
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