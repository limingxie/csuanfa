#include <cstdio>

void b1001(int&,int);

//g++ b1001/*.cpp -o b1001.out && ./b1001.out
int main (){
    int step = 0;
    int n = 0;

    scanf("%d", &n);
    b1001(step, n);
    printf("%d\n", step);
    return 0;
}
