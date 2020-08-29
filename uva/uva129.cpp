#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=82;

int n,k,cont;
int s[maxn];
int cur_global=0;
int dfs(int cur)
{
    if(cont++==k)
    {
        putchar(s[0]+'A');
        for(int i=1;i<cur;i++)
        {
            if(i==64)
            {
                putchar('\n');
                cout<<(char)(s[i]+'A');
                continue;
            }
            if(i%4==0)
            {
                putchar(' ');
            }
            cout<<(char)(s[i]+'A');
        }
        cur_global=cur;
        putchar('\n');
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        s[cur]=i;
        int ok=1;
        for(int d=1;d*2<=cur+1;++d)
        {
            int equal =1; 
            for(int now=cur;now>=cur+1-d;--now)
            {
                if(s[now]!=s[now-d])
                {
                    equal=0;
                    break;
                }
            }
            if(equal)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            if(dfs(cur+1))
                return 1;
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d%d",&k,&n)==2 && n && k)
    {
        memset(s,0,sizeof(s));
        cont =0;
        dfs(0);
        cout<<cur_global<<"\n";
    }
}
