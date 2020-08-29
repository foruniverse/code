#include<iostream> 
#include<cmath> 
#include<cstring>
#include<vector> 
#include<cstdio>
using namespace std;
const int maxn = 1000+5;
struct Node{
    double x,y,r;
    Node(double x,double y,double r):x(x),y(y),r(r){}
}; //存储障碍物节点 int n;
vector<Node> nodes;
int vis[maxn] ;
double west ;//左边界和有边界最南点
double east;
int n;

bool connect(int,int);//判断两个障碍物是否相交 
bool dfs(int);
bool dis(int i)
{
    return 1000-nodes[i].y<=nodes[i].r; 
}//判断是否和上边界相切、相交，注意是等号

void print_node(int i)
{
   cout<<nodes[i].x<<" "<<nodes[i].y<<" "<<nodes[i].r<<endl; 
}

int main()
{
    cout<<fixed;
    cout.precision(2);
    while(cin>>n)
    {
        west = east =maxn -5;
        int x,y,r;
        memset(vis,0,sizeof(vis));
        nodes.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x,&y,&r);
            nodes.push_back(Node(x,y,r));
        }
        bool flag = false;
        for(int i=0;i<nodes.size();i++)
        {
            if(dis(i) && !vis[i])//
            {
                vis[i]=1;
                if(!dfs(i))
                {
                    flag = true;
                    cout<<"IMPOSSIBLE\n";
                    break;
                }
            }
        }
        if(flag)
            continue;
        cout<<"0.00 "<<west<<" "<<"1000.00 "<<east<<endl;
    }
    return 0;
}

bool dfs(int now)
{
    int y = nodes[now].y, x= nodes[now].x,r = nodes[now].r;
    if(y-r <= 0 && y+r >0)
    {
        return false;
    }//接触到下边界，无解
    if(x-r<=0 && x+r>0)
    {
        double y_1 = y - sqrt(r*r - x*x);
        west = min(y_1,west);
    }//摸到了左边界，注意等号
    if(x-r<1000 && x+r >=1000)
    {
        double y_1 = y - sqrt(r*r - pow((1000-x),2));
        east = min(y_1,east);
    }//摸到了有边界
    for(int i=0;i<nodes.size();i++)
    {
        if(!vis[i] && connect(now,i))
        {
            vis[i]=1;
            if(!dfs(i))
               return false; 
        }
    }
    return true;
}

bool connect(int l,int r)
{
    return pow(nodes[l].x-nodes[r].x,2) + pow(nodes[l].y- nodes[r].y,2) < pow(nodes[l].r+nodes[r].r,2);
}
