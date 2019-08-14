#include <cstdio>
#include <cstring>

char c[10][5] = {"ling","yi","er","san", "si","wu","liu", "qi","ba","jiu"};
int main()
{
    char s[110];
    scanf("%s", s);
    int slen = strlen(s);
    int sum = 0;
    int r[1010];
    for (int i = 0; i < slen; i++)
    {
        sum = sum + (s[i]-'0');
    }


    int num=0;
  

     while (sum != 0)
     {
       r[num] = sum % 10;
       sum = sum/10;
       num++;
     }
    

    for (int i = num - 1; i >= 0; i--)
    {
        printf("%s", c[r[i]]);
        if( i != 0)
        {
            printf(" ");
        }
    }

        if (num=0)
    {
            printf("ling");
        }
    
    return 0;
}

//g++ b1002/*.cpp -o b.out && ./b.out