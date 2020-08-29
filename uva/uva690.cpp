/* *uva690. 暴力搜索版本
 *TLE版本
 */
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 21;
const int INF = 220;
int table[5][INF];
int n;

int maxd;
vector<int> pos[maxn];
int best;

void print_t()
{
    for(int i = 0;  i < 5; ++i)
    {
        for(int j = 0; j < 49; ++j)
            printf("%d ",table[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

bool check(int cur)
{
    for(int i = cur; i < cur + n; ++i)
        for(const auto now: pos[i-cur])
         if(table[now][i] != 0){ /*cout<<"false\n";*/ return false; } 
//    cout<<"check true;\n";
    return true;
}

void go(int cur,int val)
{
     for(int i = cur; i < cur + n; ++i)
        for(const auto now: pos[i-cur])
            table[now][i] = val;
}
int minstep;
void dfs(int d,int cur)
{
    if(d == maxd + 1 ) { best = min(cur - 1,best); /*printf("best:%d\n",best);*/ return ; }

    for(int i = cur; i <= best; ++i)
    {
        if(i + (maxd - d) * minstep >= best) return;
        //print_t();
        //cout<<"cur:"<<i<<"\n";
        if(!check(i)) continue;
        go(i,d);
        //cout<<"cur:"<<i<<" inside\n";
        dfs(d + 1,i + 1);
        //cout<<"backtrace\n";
        go(i,0);

    }
}

int main(){
//    freopen("in","r",stdin);
    while(scanf("%d",&n) == 1  && n)
    {
        getchar();
        memset(table,0,sizeof(table));
        for(auto && temp: pos) temp.clear();
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < n; ++j) 
            {
                char temp; scanf("%c",&temp);
                if(temp == 'X')  { table[i][j] = 1; pos[j].push_back(i); }
            }
            getchar();
        }
        // 最后一段坐标范围 [(maxd - 1) * n, maxd * n -1]

        for(int i = 1; i <= n; ++i) if(check(i)) { minstep = i; break; } 
//        cout<<"minstep "<<minstep<<endl;
        best = 9 * n ;
        maxd = 10;        
        dfs(2,1);
        printf("%d\n",best + n );
    } 
    return 0;
}
