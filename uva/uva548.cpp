#include<cstdio>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

const int maxn = 10000 +5;
int inOrder[maxn];
int postOrder[maxn];
int lch[maxn], rch[maxn];
int best_sum = 1000000000;
int best;

int n;
//由sstream 提取输入的字符串中的字符、数字
bool readLine( int * temp )
{
    string s;
    if(!getline(cin,s))
        return false;
    //string liu
    stringstream ss(s);
    n=0;
    int x;
    while(ss>>x)
        temp[n++]=x;
    return n>0;
}

int build(int ll,int lr,int rl, int rr)
{
    if(ll>lr)
        return 0;
    //边界分析
    int root = postOrder[rr];
    int p=ll;
    while(inOrder[p]!=root) p++;

    int cnt = p-ll;
    //递归
    lch[root]=build(ll,p-1,rl,rl+cnt-1);
    rch[root]=build(p+1,lr,rl+cnt,rr-1);

    return root;
}

void dfs(int u, int sum)
{
    sum += u;
    if(!lch[u] && !rch[u])
    {
        if(( sum < best_sum &&  u< best) || sum < best_sum )
        {
            best = u;
            best_sum = sum;
        }
    }
    if(lch[u])
        dfs(lch[u],sum);
    if(rch[u])
        dfs(rch[u],sum);
}

int main()
{
    while(readLine(inOrder))
    {
        readLine(postOrder);
        build(0,n-1,0,n-1);
        best=1000000;
        best_sum=100000000;
        dfs(postOrder[n-1],0);
        printf("%d\n",best);
    }
    return 0;
}
