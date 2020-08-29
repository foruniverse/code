#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 10;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,w,h,cont;
vector<int> ans;
set<vector<int>> buffer;

inline int convert(int x,int y) {return x * 10 + y;}

int board[maxn][maxn];
bool inside(int x,int y)
{
    return x >=0 && x <h && y >= 0 && y <w;
}

void print_ans()
{
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j) if(board[i][j]) printf("*"); else printf("+");
        putchar('\n');
    } 
    putchar('\n');
}
bool check()
{
    vector<int> temp(ans);
    sort(temp.begin(),temp.end());
//    for(auto x: temp) printf("%d,%d ",x/10,x%10); putchar('\n');
   if(buffer.insert(temp).second ) return true; 
 //   cout<<"false\n";
   return false;
}

void dfs(int d)
{
    if(d == n)  { if(check()) {++cont; print_ans();} return ; }
    for(auto cur : ans)
    {
        int x = cur/10, y = cur % 10;
        for(int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if(inside(xx, yy) && board[xx][yy] == 0)
            {
                board[xx][yy] = 1;
                ans.push_back(convert(xx,yy));
                dfs(d + 1); 
                ans.pop_back();
                board[xx][yy] = 0;
            }
        }
    }

}
void solve()
{
    cont = 0;
    ans.clear();
    buffer.clear();
    memset(board,0,sizeof(board));
    board[0][0] = 1;
    ans.push_back(convert(0,0));
    dfs(1);
    printf("%d\n",cont);
}
int main(){
    while(scanf("%d%d%d",&n,&w,&h) == 3) 
    {
        solve();
    }
    return 0;
}
