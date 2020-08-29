#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 13;
int n,maxd;
int a[maxn + 1];

bool dfs(int d)
{
    if(a[d] == n) return true;
    if(d == maxd) return false; //ida* 剪枝可选， 如果估价函数没有剪掉支，就必须在这里剪掉
    int maxv = -1;
    for(int i = 0; i<= d;++i) maxv = max(maxv,a[i]);
    if((maxv << (maxd - d)) < n) return false; 
    
    for(int i = d; i>= 0; --i)
    {
        a[d + 1] = a[d] + a[i];
        if(dfs(d+1)) return true;
        a[d + 1] = a[d] - a[i];
        if(dfs(d + 1)) return true;
    }
    return false;
}

int solve(int n)
{
    if(n == 1) return 0;
    a[0] = 1;
    for(maxd = 1;maxd <= maxn;++maxd)
    {
        if(dfs(0)) return maxd;
    }
    return maxn; 
}

int main()
{
    printf("{");
    while(scanf("%d",&n) == 1 && n)
//    for(n = 1; n <= 1000; ++n)
    {
        //printf("%d\n",solve(n));
        printf(",%d",solve(n));
        memset(a,0,sizeof(a));
    }
    printf("}");
    return 0;
}
