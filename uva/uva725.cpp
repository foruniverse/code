#include<iostream>
#include<cstring>
using namespace std;


bool vis[10];

int check_count(int n)
{
    if(n==0)
        return 0;
    else return check_count(n/10)+1; 
}

bool check(int n)
{
    int cont = check_count(n);
    if(cont!=5)
        return false;
    bool vis1[10];
    memcpy(vis1,vis,sizeof(vis));
    while(n)
    {
        if(vis1[n%10])
            return false;
        vis1[n%10]=true;
        n/=10;  
    }
    return true;
}
int main()
{
    int n;
    int num=0;
    while(cin>>n && n)
    {
        if(++num>1)
            cout<<"\n";
        memset(vis,0,sizeof(vis));
        int cont = 0;
        for(int i=0;i<=9;i++)
            if(vis[i]) continue;
            else {
                vis[i]=true;
                for(int j=0;j<=9;j++)
                    if(vis[j]) continue;
                    else {
                        vis[j]=true;
                        for(int k=0;k<=9;k++)
                            if(vis[k]) continue;
                            else {
                                vis[k]=true;
                                for(int h=0;h<=9;h++)
                                    if(vis[h]) continue;
                                    else {
                                        vis[h]=true;
                                        for(int l=0;l<=9;l++)
                                            if(vis[l]) continue;
                                            else {
                                                vis[l]=true;
                                                int now = ((((i*10+j)*10+k)*10+h)*10+l);
                                                if(check(now*n))
                                                {
                                                    ++cont;
                                                    cout<<((now*n)/10000==0?"0":"")<<now*n<<" / "<<(i==0?"0":"")<<now<<" = "<<n<<endl;
                                                }
                                                vis[l]=false;
                                            }
                                        vis[h]=false;
                                    }
                                vis[k]=false;
                            }
                        vis[j]=false;
                    }
                vis[i]=false;
            }
        if(cont==0)
            cout<<"There are no solutions for "<<n<<".\n";
    }
    return 0;
}
