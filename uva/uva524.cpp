#include<iostream>
#include<cstring>
using namespace std;


bool is_prime(int n)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool prime[34];
int n;
int buffer[20];
bool vis[20];
void dfs(int cur)
{
    if(cur==n+1&&prime[buffer[cur-1]+buffer[1]])
    {
        cout<<buffer[1];
        for(int i=2;i<=n;i++)
            cout<<" "<<buffer[i];
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&prime[i+buffer[cur-1]])
        {
            buffer[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }

}
int main()
{
    int cont =0;
    while(cin>>n)
    {
        memset(buffer,0,sizeof(buffer));
        memset(vis,0,sizeof(vis)); 
        if(++cont>1)
            cout<<"\n";
        cout<<"Case "<<cont<<":\n";
        for(int i=1;i<=n*2;i++)
        {
            prime[i]=is_prime(i);
        }
        buffer[1]=1;
        vis[1]=1;
        dfs(2);

    }
    return 0;

}
