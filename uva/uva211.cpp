#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int dx[] = {0,1};
const int dy[] = {1,0};
int board[7][8],vis[7][8];
int pai[7][8],check[30];

bool inside(int x,int y) { return x >=0 && x < 7 && y >=0 && y < 8; }

bool read()
{
    for(int i = 0; i < 7; ++i)
        for(int j = 0; j < 8; ++j) if(scanf("%d",&board[i][j]) != 1) return false; 
    return true;
}
void output()
{
    for(int i = 0; i < 7; ++i)
    { for(int j = 0; j < 8; ++j) printf("  %2d",vis[i][j]); putchar('\n'); }
    putchar('\n');
}
int sum ;
int duo = 0;
void dfs(int d,int x,int y)
{
    if(d == 28) { ++sum; output();return; }
    if(y == 8) x++,y=0;// 防止越界
    if(vis[x][y]) { dfs(d,x,y + 1); return ; } 
    int cur = board[x][y];
    for(int i = 0; i < 2; ++i)
    {
        int xx = x + dx[i] ,yy = y + dy[i];
        if(!inside(xx,yy) || vis[xx][yy]) continue;
        int next = board[xx][yy];
        int val = pai[cur][next];
        if(check[val])  continue;
        vis[xx][yy] = vis[x][y] = val;
        check[val] = 1;
        /*
         *printf("(%d,%d):%d -> (%d,%d):%d = %d\n",x,y,cur,xx,yy,next,val);
         */
        dfs(d + 1,x,y + 1);
        //printf("backtrace\n");
        check[val] = 0;
        vis[xx][yy] = vis[x][y] = 0;
    }
}
void init()
{
    int cont = 0;
    for(int i = 0; i < 7; ++i) for(int j = i; j < 7; ++j) pai[i][j] = pai[j][i]= ++cont;

    /*
     *for(int i = 0; i < 7; ++i)
     *    for(int j = i; j < 7; ++j)
     *        printf("%d,%d:%d\n",i,j,pai[i][j]);
     */
}
int main(){
    int no = 0;
//    freopen("in","r",stdin);
    init();
    while(read())
    {
        if(no != 0) printf("\n\n\n");
        printf("Layout #%d:\n\n",++no);
        for(int i = 0; i < 7; ++i)
        {
            for(int j = 0; j < 8; ++j) printf("  %2d",board[i][j]);
            putchar('\n');
        } //putchar('\n'); 
        printf("\nMaps resulting from layout #%d are:\n\n",no);
        memset(vis,0,sizeof(vis));
        memset(check,0,sizeof(check));
        sum = 0;
        dfs(0,0,0);
        printf("There are %d solution(s) for layout #%d.\n",sum,no);
    }
    return 0;
}
