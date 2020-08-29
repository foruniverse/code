#include<iostream>
#include<cstdio>
using namespace std;
using lint = long long;
const int maxn = 5000;
const int INF = -1e+10;
int p[maxn + 1],c[maxn + 1],g[maxn][maxn];
int n,k;

lint  ans[1e+4 +1];
int score;
void dfs(int cur, int tar,int d)
{
    if(cur == tar) { return; }
    int next = p[cur];
    temp += 
    ans[d] = max(ans[d],temp);
    dfs(next[cur],tar);

}
int main(){
    scanf("%d%d",&n,&k);        
    for(int i = 1; i <= n; ++i) scanf("%d",&p[i]);
    for(int i = 1; i <= n; ++i) scanf("%d",&c[i]);
    for(int i = 0; i <= 1e+4 + 1; ++i) ans[i] = INF;
    for(int i = 1; i <= n; ++i) 
    {
        score = -1e+10;
        lint score = 0;
        int cont = 0;
        int next  = i;
        do{
            next = p[next];
            score += c[next];
            ++cont;
            ans[cont] = max(ans[cont] + score);
        }while(next != i);
    }
    return 0;

}
