#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 100+5;
int n,node[maxn];

struct Edge{
    int in[maxn];
    int ou[maxn];
};
vector<Edge> edges;

int main()
{
    int count =0;
    while(cin>>n && n)
    {
        edges.clear();
        memset(node,0,sizeof(node));
        for(int i=1;i<=n;i++) cin>>node[i];
        int m;cin>>m;getchar();
        for(int i=1;i<=m;i++)
        {//这里脑袋进水了，用了stringstream，实际可以不用，懒得改了
            string line;
            getline(cin,line); 
            stringstream ss(line);
            int temp;
            Edge edge; 
            memset(edge.in,0,sizeof(edge.in));
            memset(edge.ou,0,sizeof(edge.ou));
            while(ss>>temp)
            {
                if(temp==0)
                    break;
                else if(temp<0)
                    edge.in[abs(temp)]++;
                else edge.ou[temp]++;
            }
            edges.push_back(edge);
        }
        int num; cin>>num;
        int tran=0;
        bool flag =false;
        for(;;)
        {
            flag =false;
            if(num==0) break;
            for(auto e:edges)
            {//遍历所有的门找出可以走的
                bool all=true;
                for(int i=1;i<=n;i++)
                {
                    if(node[i]<e.in[i])
                    {
                        all=false;
                        break;
                    }
                }//简单的查找就完事
                if(!all) continue;
                for(int i=1;i<=n;i++) node[i]=node[i]-e.in[i];
                flag=true;
                for(int j=1;j<=n;j++) node[j]+=e.ou[j];// 更新节点值
                ++tran;
                break;
                //这道题的坑点在这，题面没有说多个门可用时应该先选哪一个，实际上应该每次都从第一个门找起
            }
            if(!flag)
                break;
            if(tran==num)
                break;
        } 
        if(num==0)
        {
            flag= true;
            tran=0;
        }
        cout<<"Case "<<++count<<": ";
        if(!flag)
            cout<<"dead after "<<tran<<" transitions\n";
        else cout<<"still live after "<<tran<<" transitions\n";
//        sort(node+1,node+n+1,[](const int a,const int b)-> bool{return a>b;}); 
        cout<<"Places with tokens:";
        for(int i=1;i<=n;i++)
        {
            if(node[i]==0)
                continue;
            cout<<" "<<i<<" "<<"("<<node[i]<<")";
        }
        cout<<"\n\n";
    }
    return 0;
}
