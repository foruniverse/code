#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

int board[10][10];
int vis[10][10];

void print()
{
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
            printf("%2d",vis[i][j]);
        putchar('\n');
    }
}
void dfs(int x,int y)
{
    bool flag = false;
    if(x==5 && y>=5 && y<=8)
    {
        printf("(%d,%d)",x,y);
        printf("yse\n");
        flag = true;
    }
    if(x<0 || x>9 || y<0 || y>9)
    {
        if(flag)
            cout<<"outofbound\n";
        return ;
    }
    if(vis[x][y]==1)
    {
        if(flag)
            cout<<"hastra\n";
        return ;
    }

    if(board[x][y]==1  )
    {
        if(flag)
            cout<<"black\n";

        cout<<vis[x][y]<<endl;
        vis[x][y]=-1;
        return ;
    }
    printf("(%d,%d)\n",x,y);
    vis[x][y] =1;
    print();
    putchar('\n');

    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if( i!=0 || j!=0)
            {
                dfs(x+i,y+j);
            }

}
int main()
{
    memset(vis,0,sizeof(vis));
    for(int i=5;i<=7;i++)
        for(int j=5;j<=8;j++)
            board[i][j]=1;

    dfs(0,0);
    print();
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
            printf("%2d",board[i][j]);
        putchar('\n');
    }
    return 0; 
}
