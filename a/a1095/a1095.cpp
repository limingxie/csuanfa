#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Car
{
    char id[8];
    int time;
    char status[4];
}all[10010], valid[10010];

map<string, int> parkTime;
int num = 0;

int TimeToInt(int hh, int mm, int ss)
{
    return hh * 3600 + mm * 60 + ss;
}

bool cmpByTime(Car a, Car b)
{
    return a.time < b.time;
}

bool cmpByIdTime(Car a, Car b)
{
    int s = strcmp(a.id, b.id);
    if (s!=0)
    {
        return s < 0;
    }
    else 
    {
        return a.time < b.time;
    }
}

int main()
{
    int n, k, hh, mm, ss;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
        all[i].time = TimeToInt(hh,mm,ss);
    }
    
    sort(all, all + n, cmpByIdTime);

    int maxTime = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if(!strcmp(all[i].id, all[i+1].id) && !strcmp(all[i].status, "in") && !strcmp(all[i+1].status, "out"))
        {
            valid[num++]=all[i];
            valid[num++]=all[i+1];
            int inTime = all[i+1].time - all[i].time;
            if(parkTime.count(all[i].id) == 0)
            {
                parkTime[all[i].id] = 0;
            }
            parkTime[all[i].id] += inTime; 
            maxTime = max(maxTime, parkTime[all[i].id]);
        }
    }

    sort(valid, valid + num, cmpByTime);

    int now = 0, numCar = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = TimeToInt(hh, mm, ss);
        while(now < num && valid[now].time <= time )
        {
            if(!strcmp(valid[now].status, "in"))
            {
                numCar++;
            }
            else
            {
                numCar--;
            }
            now++;
        }
         printf("%d\n", numCar);
    }
    
    map<string, int>::iterator it;
    for(it = parkTime.begin(); it != parkTime.end(); it++)
    {
        if(it->second == maxTime)
        {
            printf("%s ", it->first.c_str());
        }
    }

    printf("%02d:%02d:%02d\n", maxTime/3600, maxTime%3600/60, maxTime%60);

    return 0;
}

//g++ a1095/*.cpp -o a.out && ./a.out
/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00


*/