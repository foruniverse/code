#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

struct Node{
    int v[3],dis;
    bool operator <(const Node & node) const
    {
        return dis>node.dis;
    }
};

const int maxn = 200 + 5;
int vis[maxn][maxn],cap[3],ans[maxn];

void update_ans(const Node & temp)
{
    for(int i=0;i<3;i++)
    {
        int d = temp.v[i];
        if(ans[d]<0 || temp.dis < ans[d]) ans[d] = temp.dis;
    }
}

void solve(int a,int b,int c,int d)
{
    Node node; node.v[0]=0,node.v[1]=0,node.v[2]=c,node.dis=0;
    cap[0]=a,cap[1]=b, cap[2]=c;
    memset(ans,-1,sizeof(ans));
    memset(vis,0,sizeof(vis));
    priority_queue<Node> que;
    que.push(node);
    vis[0][0]=1;
    while(!que.empty())
    {
        Node u = que.top(); que.pop();
        update_ans(u);
        if(ans[d]>=0) break;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j)
                {
                    if(u.v[i]==0 || u.v[j] == cap[j]) continue;
                    int amount = min(cap[j],u.v[j] + u.v[i]) - u.v[j];
                    Node temp;
                    memcpy(&temp,&u,sizeof(u));
                    temp.v[i] = temp.v[i] - amount;
                    temp.v[j] = temp.v[j] + amount;
                    temp.dis  = u.dis + amount;
                    if(!vis[temp.v[0]][temp.v[1]])
                    {
                        que.push(temp);
                        vis[temp.v[0]][temp.v[1]]=1;
                    }
                }        
    }

    for(int now = d; now >= 0; --now)
    {
        if(ans[now] >= 0)
        {
            printf("%d %d\n",ans[now],now);
            return;
        }
    }
}

int main()
{
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    return 0;
}
