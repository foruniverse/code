//#define LOCAL
//#define DEBUG1
//直接暴力就能过，我吐了
#include<iostream>
#include<cstdio>
#include<set>
#include<string>
#include<cstring>
using namespace std;
const int maxn=27;
int best = 100;
int node[maxn][maxn];
int vis[maxn];
using pa = pair<int,int>;
set<pa> buffer;
int ans[10];
int fake[10]; 
int  check(pa fat,int cur,int now_max)
{
    //找到所有的入边和出边
    set<int> temp;
    for(int i=0;i<maxn;i++) 
    {
        if(node[fat.first][i] || node[i][fat.first])
        {
            temp.insert(i);
        }
    }
    for(int i=0;i<cur;i++)
    {
        if(temp.count(fake[i]))
        {
            int now = abs(i-cur);
            if(now>best)
                return -1;
            now_max=max(now_max,now);
        }
    }
    return now_max;
}
void dfs(int cur,int now_max)
{
    if(cur==buffer.size())
    {
        if(now_max>=best)
            return; 
        best = now_max;
        memcpy(ans,fake,sizeof(fake));
#ifdef DEBUG1 
        cout<<"best:"<<endl;
        for(int i=0;i<buffer.size();i++)
        {
            cout<<(char)(ans[i]+'A')<<" ";
        }
        cout<<"->"<<best<<endl;
#endif
        return ;
    }
    for(auto ite=buffer.begin();ite!=buffer.end();++ite)
    {
        if(!vis[ite->first])
        {
            int temp = check(*ite,cur,now_max);
 //           cout<<"cur:"<<cur<<" value:"<<(char)(ite->first+'A')<<" now_max:"<<temp<<endl;
            if(temp!=-1)
            {
                vis[ite->first]=1;
                fake[cur]=ite->first;
                dfs(cur+1,temp);
                vis[ite->first]=0;
            }
        }
    }
}

int main(){
    string temp;
#ifdef LOCAL
    freopen("i","r",stdin);
#endif
    while(getline(cin,temp)&& temp[0]!='#')
    {
        buffer.clear();
        memset(node,0,sizeof(node));
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        int fat=temp[0]-'A';
        buffer.emplace(temp[0]-'A',1);
        for(int i=2;i<temp.size();i++)
        {
            if(temp[i]==';')
            {
                fat=temp[++i]-'A';
                buffer.emplace(fat,1);
                i=1+i;
                continue;
            }
            buffer.emplace(temp[i]-'A',1);
            node[fat][temp[i]-'A']=1; 
        }
#ifdef DEBUG
        for(int i=0;i<maxn;++i)
        {
            for(int j=0;j<maxn;++j)
            {
                if(node[i][j])
                {
                    printf("(%c,%c) ",i+'A',j+'A');
                }
            }
            putchar('\n');
        }
        cout<<buffer.size()<<endl;
        for(auto now:buffer)
            cout<<(char)(now.first+'A')<<" ";
#endif
        dfs(0,0);
        for(int i=0;i<buffer.size();i++)
        {
            cout<<(char)(ans[i]+'A')<<" ";
        }
        cout<<"-> "<<best<<endl;       
        best=100;
    }
}
