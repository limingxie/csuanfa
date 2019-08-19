#include <stdio.h>
#include <string.h>

void reverse_str(char s[1010])
{
    char r[1010];
    int slen = strlen(s);
    int num = 0;
    for (int k = slen - 1; k >= 0; k--)
    {
        r[num] = s[k];

        num++;
    }
    strcpy(s, r);
}

int main()
{
    char s[100][1010], z[1010];
    int n = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        fgets(s[i], 1010, stdin);
        reverse_str(s[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            strcpy(z, s[i]);
            continue;
        }
        int slen = strlen(s[i]);
        if (slen > strlen(z) )
        {
            slen = strlen(z);
        }
        char t[1010];
        for (int j = 0; j < slen; j++)
        {
            
            if (s[i][j] == z[j])
            {
                t[j] = s[i][j];
            }
            else
            {
                strcpy(z, t);
                break;
            }
        }
    }


    int zlen = strlen(z);
    if (zlen > 0)
    {
        for (int i = zlen - 1; i >= 0; i--)
        {
            printf("%c", z[i]);
        }
    }
    else
    {
        printf("nai");
    }

    return 0;
}

/*

#include <cstdio>
#include <cstring>
 
int n, minLen = 256, ans = 0;
char s[100][256];
 
int main(){
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		gets(s[i]);
		int len = strlen(s[i]);
		if(len < minLen){
			minLen = len;
		}
		for(int j = 0; j < len / 2; j++){
			char temp = s[i][j];
			s[i][j] = s[i][len - j - 1];
			s[i][len - j - 1] = temp;
		}
	}
	for(int i = 0; i < minLen; i++){
		char c = s[0][i];
		bool same = true;
		for(int j = 1; j < n; j++){
			if(c != s[j][i]){
				same = false;
				break;
			}
		}
		if(same){
			ans++;
		}
		else{
			break;
		}
	}
	if(ans){
		for(int i = ans - 1; i >= 0; i--){
			printf("%c", s[0][i]);
		}
	}
	else{
		printf("nai");
	}
	return 0;

}
*/
//g++ a1077/*.cpp -o a.out && ./a.out



