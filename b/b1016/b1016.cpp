#include <cstdio>

int main()
{
    long long a, da, b, db;
    scanf("%lld %lld %lld %lld", &a, &da, &b, &db);
    long long pa = 0;
    long long pb = 0;
    while(a != 0)
    {
        if (a % 10 == da)
        {
            pa = pa * 10 + da;
        }
        a = a / 10;
    } 

    while(b != 0)
    {
        if (b % 10== db)
        {
            pb = pb * 10 + db;
        }
       b = b / 10;
    } 

    printf("%lld", pa + pb);

    return 0;
}

//g++ b1016/*.cpp -o b1016.out && ./b1016.out