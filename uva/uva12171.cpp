#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int n;

int g[52][52];
int ID(char a1,char a2)
{
    //位运算
    return (a1-'A')*2 + (a2 == '+' ?0:1);
}
void init(char a,char b,char c ,char d)
{
    if(a=='0' || c=='0')
        return;

    int u = ID(a,b)^1 , v= ID(c,d);
    g[u][v]=1;
}
int vis[52];
bool dfs(int now)
{
    vis[now] = -1;
    for(int i=0;i<52;i++)
    {
        if(g[now][i])
        {
            if(vis[i] < 0)
                return false;
            else if(!vis[i] && !dfs(i))
                return false;
        }
    }
    vis[now] = 1;
    return true;
}


bool find_cycle()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<52;i++)
    {
        if(!vis[i])
            if(!dfs(i))
                return true;
    }
    return false;
}
int main()
{   
    string s;
    while(scanf("%d",&n)==1)
    {
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int i=0;i<=3;i++)
                for(int j=0;j<=3;j++)
                {
                    if(i!=j)
                    {
                        init(s[i*2],s[i*2+1],s[j*2],s[j*2+1]);
                    }
                }

        }
        if(find_cycle())
            cout<<"unbounded\n";
        else cout<<"bounded\n";
    }
    return 0;
}
