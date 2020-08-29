#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int cont =0;
    int n;
    while(cin>>n)
    {
        int temp;
        vector<long long> buffer;
        vector<int> now;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            now.push_back(temp);
        }
        long long best = -1;
        for(int i=0;i<n;i++)
        {
            long long sum=1;
            for(int j=i;j<n;j++)
            {
                sum*=now[j];
                best=max(sum,best);
            }
        }
       cout<<"Case #"<<++cont<<": The maximum product is "; 
        cout<<(best<=0?0:best)<<".\n\n";
    }
    return 0;
}
