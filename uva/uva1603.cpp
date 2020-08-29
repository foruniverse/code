/*
 *uva 1603 
 *难度: 省选
 *描述： 给定一个嵌套正方形的图，可以通过移除边来消除图中地正放心，找出最少地操作次数
 *难点： 枚举题的难点向来是两个： 1. 如何正确方便的枚举，暴力 2. 如何正确的剪枝
 * 1. 怎么枚举，这是一个问题，枚举所有当前正方形，枚举其所有的边，这样每条边最少消除了一个正方形，
 *    然后从正方形中减去一个，肯定不能直接减，太麻烦，所以下一个问题，整么确定当前的正方形，怎么去维护正方形的增添
 *    刘汝佳用的当前边数是否等于初始边数判断
 *
 *
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 61;
int n,edge[maxn],size[maxn],fullsize[maxn],total,contain[maxn][maxn];
int maxcont,best;

vector<int> ans;

inline int find_row(int x,int y)
{
    return (2 * n + 1) * x + y; 
}

inline int find_col(int x,int y)
{
    return (2 * n + 1) * x + y + n;
}

int find_square()
{
    for(int i = 0; i < total; ++i)
    {
        if(size[i] == fullsize[i]) return i;
    }
    return -1;
}
void init()
{
    total = 0;
    memset(size,0,sizeof(size));
    memset(contain,0,sizeof(contain));
    for(int i = 1; i <= n; ++i)
    {
        for(int x = 0; x <= n - i; ++x)
        {
            for(int y = 0; y <= n - i; ++y)
            {
                fullsize[total]  = 4 * i;
                for(int j = 0; j < i; ++j)
                {
                    int a = find_row(x, y + j); // up
                    int b = find_row(x + i, y + j); // downj
                    int c = find_col(x + j, y);//left
                    int d = find_col(x + j, y + i); // right
 //                   printf("no.%d square a:%d b:%d c:%d d:%d\n",total,a+1,b+1,c+1,d+1);
                    contain[total][a] = 1;
                    contain[total][b] = 1;
                    contain[total][c] = 1;
                    contain[total][d] = 1;
                    size[total] += edge[a] + edge[b] + edge[c] + edge[d];
                }
               ++total; 
            }
        }
    }
}

void dfs(int d)
{
    //find current square
    if(d >= best) return;
   int cur = find_square();
    if(cur == -1)  { 
//        for(int now : ans) printf("%d ",now); putchar('\n'); printf("success %d\n",d);
        best = d; return; } 
    //try all edge of current square;
    for(int i = 0; i < maxcont; ++i)
    {
        if(contain[cur][i]) {
            for(int j = 0; j < total; ++j) if(contain[j][i])  size[j]-- ;   // delete all square which own this edge 
//            printf("remove %d\n",i + 1);ans.push_back(i + 1);
            dfs(d + 1);
//            ans.pop_back(); printf("putback %d\n",i + 1);
            for(int j = 0; j < total; ++j) if(contain[j][i])  size[j]++;// backtrace
        }
    }
}
int main()
{
    int t,m; scanf("%d",&t);
    while(t--)
    {
        memset(edge,0,sizeof(edge));
        scanf("%d%d",&n,&m);
        int temp;
        maxcont = 2 * n * (n + 1);// max edge correspnds to current 'n'
        for(int i = 0; i < maxcont; ++i) edge[i] = 1;
        for(int i = 1; i <= m; ++i) scanf("%d",&temp), edge[temp - 1] = 0; 
        init();
        best = 10000;
        dfs(0);
        printf("%d\n",best);
    }
}
