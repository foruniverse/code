#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const char  turns[] = "FLR";
const char direction[] = "NESW";
char name[100];
int could_turn[11][11][4][3];
int d[11][11][4];
//转换函数，将 char 类型转换为 int， 便于下文计算
int dir_id(char c) { return strchr(direction,c) - direction; }
int turn_id(char c) { return strchr(turns,c) - turns; }
//各个方向的转向表, 数组的值都恰好是坐标的变换值
int  move_x[] = {-1,0,1,0};
int move_y[] = {0,1,0,-1};
bool inside(int x,int y)
{
    return x>=1 && x<= 9 && y<=9 && y>=1 ;
}
struct Node
{
    int x,y,dir;
    Node(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir) {}
};
//每个节点每个方向
struct Node father[11][11][4];
Node walk(const Node & u, int turn)
{
    int dir = u.dir;
    if(turn == 1) // 左转即逆时针
        dir = (dir + 3 ) %4 ;// 直接减一，数组下标会溢出
    else if( turn == 2) // 右转即顺时针
        dir = (dir + 1) % 4;
    //计算出转向后的节点
    return Node(u.x+move_x[dir],u.y + move_y[dir],dir);
}
int x,y,dx,dy,x_1,y_1;
int dir;
bool read()
{
    char s[10];
    char temp;
    if(scanf("%s%d%d %c%d%d",name,&x,&y,&temp,&dx,&dy)!=6)
        return false;
    memset(could_turn,0,sizeof(could_turn));
    dir = dir_id(temp);
    x_1 = x + move_x[dir];
    y_1 = y + move_y[dir];
    printf("%s\n",name);
    
    for(;;)
    {
        int x,y;
        scanf("%d",&x);
        if(x==0)
            return true;
        scanf("%d",&y);
        while(scanf("%s",s)==1 && s[0]!='*')
        {
            for(int i=1;i<strlen(s);i++)
            {
                could_turn[x][y][dir_id(s[0])][turn_id(s[i])] = 1;
            }
        }
    }
    return true;
}
void print_ans(Node u)
{
    vector<Node> v;

    for(;;)
    {
        v.push_back(u);
        if(d[u.x][u.y][u.dir] ==0 )
            break;
        u = father[u.x][u.y][u.dir];
    }

    v.push_back(Node(x,y,dir));
    int count =0;
    for(auto x=v.rbegin();x!=v.rend();x++)
    {
        if(count  %10 ==0)
            printf(" ");
        printf(" (%d,%d)",x->x,x->y);
        if(++count % 10 ==0)
            printf("\n");
    }
    if(v.size()%10 != 0) putchar('\n');
}
void solve()
{
    memset(d,-1,sizeof(d));
    queue<Node> q;
    Node v(x_1,y_1,dir);
    d[v.x][v.y][v.dir] = 0;
    q.push(v);
    while(!q.empty())
    {
        Node v =q.front();
        q.pop();
        if(v.x == dx && v.y == dy)
        {
            print_ans(v);
            return ;
        }
        for(int i=0;i<3;i++)
        {
            Node u = walk(v,i);
            if(could_turn[v.x][v.y][v.dir][i] && inside(u.x,u.y) && d[u.x][u.y][u.dir]<0)
            {
                q.push(u);
                d[u.x][u.y][u.dir] = d[v.x][v.y][v.dir] + 1;
                father[u.x][u.y][u.dir] =v;
            }
        }
    }
    printf("  No Solution Possible\n");
}
int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    while(read())
    {
        solve();
    }
    return 0;
}
