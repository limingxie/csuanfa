#include <cstdio>

struct student
{
    long long id;
    int ex;
} s[1111];

int main()
{
    int n = 0;
    scanf("%d", &n);

    long long iid;
    int eex;
    int zz;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %d %d", &iid, &zz, &eex);
        s[zz].id = iid;
        s[zz].ex=eex;
    }

     scanf("%d", &n);
     for (int i = 0; i < n; i++)
    {
        scanf("%d", &zz);
        printf("%lld %d\n", s[zz].id, s[zz].ex);
    }
}

//g++ b1041/*.cpp -o 3_2.out && ./3_2.out