#include<iostream>
#include<cmath>
#include<cstring> 
#include<string> 
using namespace std;
const int maxn =8;
int node[maxn];
int leaf[300];
int turn[maxn];
int main()
{
    int n,m,count=0;
    while(cin>>n && n!=0)
    {
        memset(leaf,0,sizeof(leaf));
        string temp;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            node[i]=temp[1]-'0';
        }
        //        for(int i=1;i<=n;i++)
        //           cout<<node[i]<<endl;
        getchar();
        getline(cin,temp);
        for(int i=0;i<temp.size();i++)
        {
            leaf[i]=temp[i]-'0';
       //     cout<<leaf[i];
        }

        //cout<<endl;
        cin>>m;
        //cout<<m<<endl;
        cout<<"S-Tree #"<<++count<<":\n";
        for(int i=1;i<=m;i++)
        {
            cin>>temp;
            for(int i=1;i<=n;i++)
            {
                turn[i]=temp[i-1]-'0';
            }
            //for(int i=1;i<=n;i++)
            //{
            //    cout<<turn[node[i]];
            //}
            //cout<<endl;
            int sum =0;
            for(int i=n-1;i>=1;i--)
            {
               sum+=pow(2,i)*turn[node[n-i]]; 
            //cout<<sum<<endl;
            }
            //cout<<"out"<<endl;
            sum+=turn[node[n]];
         //   cout<<"sum="<<sum<<" leaf="<<leaf[sum]<<endl;
            cout<<leaf[sum];
        }
        cout<<endl<<endl;



    }
    return 0;
}
