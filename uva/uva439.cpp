#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
int vis[10][10];
int dis[10][10];
const int turn[4]={-2,-1,1,2};
using pos = pair<int,int>;
pos father[10][10];

bool inside(int x,int y)
{
    return x>=1 && x<=8 && y>=1 && y<=8;
}
void print_ans(int,int);
bool bfs(pair<int,int> x,pair<int,int> y)
{
    queue<pair<int,int>> que;
    que.push(x);
    vis[x.first][x.second]=1;
    dis[x.first][x.second]=0;
    while(!que.empty())
    {
        pos u = que.front(); 
        que.pop();
        if(u.first==y.first && y.second == u.second)
        {
            cout<<"To get from "<<(char)(x.first-1+'a')<<x.second<<" to "<<(char)(y.first-1+'a')<<y.second<<" takes "<<dis[y.first][y.second]<<" knight moves.\n";
            return true;
        }
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                if(abs(turn[i])==abs(turn[j]))
                    continue;
                int now_x=u.first+turn[i];
                int now_y=u.second + turn[j];
                if(!vis[now_x][now_y] &&  inside(now_x,now_y))
                {
                    dis[now_x][now_y]=dis[u.first][u.second]+1;
                    father[now_x][now_y]=u;
                    vis[now_x][now_y]=1;
                    que.push(make_pair(now_x,now_y));
                }
            }
    }
    return false;
}

void print_ans(int x,int y)
{
    vector<pos> ans;
    pos now(x,y);
    for(;;)
    {
        ans.push_back(now);
        if(dis[now.first][now.second]==0)
            break;
        now = father[now.first][now.second]; 
    }
    for(auto temp=ans.rbegin();temp!=ans.rend();temp++)
    {
        cout<<"{"<<temp->first<<","<<temp->second<<"}\n";
    }
    cout<<endl;
}

int main()
{
    string x,y;
    while(cin>>x>>y)
    {
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        bfs(make_pair(x[0]-'a'+1,x[1]-'0'),make_pair(y[0]-'a'+1,y[1]-'0'));
    }
    return 0;
}
