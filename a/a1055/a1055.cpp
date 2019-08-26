#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person
{
    char name[10];
    int age;
    int money;
} p[100010];

bool cmpA(Person a, Person b)
{
    return a.age < b.age;
}

bool cmpM(Person a, Person b)
{
    if (a.money != b.money)
    {
        return a.money > b.money;
    }
    else if (a.age != b.age)
    {
        return a.age < b.age;
    }
    else
    {
        return strcmp(a.name, b.name) < 0;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", p[i].name, &p[i].age, &p[i].money);
    }

    sort(p, p + n, cmpM);

    int m, l, r, ca = 0;
    for (int y = 0; y < k; y++)
    {
        scanf("%d %d %d", &m, &l, &r);
        
        printf("Case #%d:\n", y+1);
        for (int i = 0; i < n; i++)
        {
            if (p[i].age >= l && p[i].age <=r)
            {
                printf("%s %d %d\n", p[i].name, p[i].age, p[i].money);
                ca++;
                if (ca == m)
                {
                    break;
                }
            }
        }
        
        if (ca == 0 )
        {
            printf("None\n");
        }

        ca =0;
    }

    return 0;
}

//g++ a1055/*.cpp -o a.out && ./a.out
/*
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50

*/