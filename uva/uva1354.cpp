#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring> 
using namespace std;
const int maxn = 6;
struct Tree{
    double l,r;
    Tree(double l=0,double r=0):l(l),r(r) {}
};
vector<Tree> tree[1<<maxn];
bool vis[1<<maxn];
double buffer[maxn];
double r,sum[1<<maxn];

void dfs(int subset)
{
    if(vis[subset]) return ;
    vis[subset]  = true;
//    cout<<"subset:"<<subset<<endl;
    if(((subset-1)&subset)==0)// 
    {
        tree[subset].push_back(Tree{});
        return ;
    }
    for(int left = (subset - 1)& subset;left;left=(left-1)&subset)//
    {
       int right = left ^ subset; 
       dfs(left); dfs(right);
       double dis_left =sum[right]/sum[subset];
       double dis_right = sum[left]/sum[subset];
       for(auto tl:tree[left])
           for(auto tr: tree[right])
           {
               Tree t;
               t.l = max(tl.l+dis_left,tr.l-dis_right);
               t.r = max(tr.r+dis_right,tl.r-dis_left);

               if(t.l+t.r<r) tree[subset].push_back(t);
           }
    }
}
int main()
{
    int c;cin>>c;
    while(c--)
    {
        int n;
        cin>>r>>n;
        memset(vis,0,sizeof(vis));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++) cin>>buffer[i];
        for(int i=0;i<(1<<n);++i)  
        {
            tree[i].clear();
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    sum[i]+=buffer[j];
            }
        }

        int root = (1 << n) - 1;
        dfs(root);
        double ans = -1;
        //cout<<"size:"<<tree[root].size()<<endl;
        for(int i=0;i<tree[root].size();++i)
        {
         //   cout<<"I:"<<i<<" "<<tree[root][i].l<<" "<<tree[root][i].r<<endl;
            ans=max(tree[root][i].l+tree[root][i].r,ans);
        }
        if(ans==-1)
            cout<<"-1\n";
        else printf("%.16lf\n", ans);
    }
    return 0;
}
