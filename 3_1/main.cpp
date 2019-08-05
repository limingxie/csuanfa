#include <stdio.h>
#include <b1001.h>

int main (){
    int step = 0;
    int n = 0;

    void  b1001(int step, int n);

    scanf("%d", &n);
    b1001(step, n);
    printf("%d\n", step);
    return 0;
}