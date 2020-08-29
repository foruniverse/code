#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

const int maxn = 500; // max step-length is 20 ,consider a straight move, max move_length should be 1 + 2 + ... + 20 = 210;
const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};
const int turn[4] = {12,30,30,12};
const char conv[] ={'e','n','s','w'};

int board[maxn][maxn];
int ans[21];
int maxlen;

struct Node{
    int x,y;
    Node(int x,int y):x(x),y(y) {}
    bool operator =(Node temp)
    {
        return x == temp.x && y == temp.y;
    }
};
void print_b()
{
    for(int i = 260; i >= 240; i--)
    {
        for(int j = 240; j <= 260; ++j)
            if(i == 250 && j == 250)
                printf("f");
            else if(board[j][i] == 1)
                printf("*");
            else printf("_");

        putchar('\n'); 
    }
    putchar('\n'); 
}

int cont,fir;
void dfs(int d,int last,Node cur)
{
    int x = cur.x, y = cur.y;
    if(cur.x == 250 && cur.y == 250 && d == maxlen + 1) 
    {
 //       if(fir != turn[last]/10 && fir != turn[last]%10) return ;
        ++cont;
//        print_b();
        for(int i = 0; i < d - 1; ++i) printf("%c",ans[i]); putchar('\n');
        return;
    }
    if(d > maxlen) return;

    for(int i = 0; i < 4; ++i)
    {
        if(turn[last]/10 == i || turn[last]%10 == i)
        {
            int xx = x + dx[i] * d; 
            int yy = y + dy[i] * d; 
            if(board[xx][yy] == 2) continue;
            int ok = 0;
            if(dx[i] == 0)
            {
                if(dy[i] == 1)
                {
                    for(int i = y + 1; i <= yy; ++i)
                        if(board[xx][i] == 1) { ok = 1; break; }
                }else{
                    for(int i = yy; i < y; ++i)
                        if(board[xx][i] == 1) { ok = 1; break; }
                }
            }else{
                if(dx[i] == 1)
                {
                    for(int i = x + 1; i <= xx; ++i)
                        if(board[i][yy] == 1) { ok = 1; break; }
                }else{
                    for(int i = xx; i <= x - 1; ++i)
                        if(board[i][yy] == 1) { ok = 1; break; }
                }
            }
            if(ok) continue;
            ans[d - 1] = conv[i];
            board[x][y] = 2;
            dfs(d + 1, i ,Node(xx,yy));
            board[x][y] = 0;
        }
    }
}
int main()
{
    int t,m; scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&maxlen,&m); 
//        printf("maxlen:%d m:%d\n",maxlen,m);
        memset(board,0,sizeof(board));

        memset(ans,0,sizeof(ans));
        cont = 0;
        for(int i = 1; i <= m; ++i) 
        {
            int a,b;
            scanf("%d%d",&a,&b);
            board[250 + a][250 + b] = 1;
        }
//        print_b();
        for(int i = 0; i < 4; ++i)
        {
            int xx = 250 + dx[i] , yy = dy[i] + 250;
            if(board[250 + dx[i]][dy[i] + 250] == 1) continue; 
            ans[0] = conv[i];
            board[xx][yy] = 2;
            dfs(2,i,Node(250 + dx[i],250 + dy[i]));
            board[xx][yy] = 0;
        }
        printf("Found %d golygon(s).\n\n",cont); 
    }
    return 0;
}
