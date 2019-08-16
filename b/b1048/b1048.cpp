#include <cstdio>
#include <cstring>

int main()
{
    char w[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
 
    char a1[110],b1[110],a2[110],b2[110],r[110];
    scanf("%s %s", a1, b1);

    int alen = strlen(a1);
    int blen = strlen(b1);

    int num =0;
    for (int i = alen -1; i >= 0; i--)
    {
        a2[num] = a1[i];
        num++;
    }
    num =0;
    for (int i = blen -1; i >= 0; i--)
    {
        b2[num] = b1[i];
        num++;
    }
    for (int i = 0; i < alen || i < blen; i++)
    {
        int n1 = i < alen ? a2[i] - '0':0;
        int n2 = i < blen ? b2[i] - '0':0;
        if (i % 2 == 0)
        {
            r[i] = w[(n1 + n2) % 13];
        }
        else
        {
            r[i] = n2 >= n1 ? w[n2 - n1] : w[n2 - n1 + 10] ;
        }
    }
    
    for (int i = strlen(r) - 1; i < strlen(r); i--)
    {
        printf("%c",r[i]);
    }
    

    return 0;
}

//g++ b1048/*.cpp -o b.out && ./b.out