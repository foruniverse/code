#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    int k;
    while(cin>>k)
    {
        vector<pair<int,int>> v;
        int ma1=2*k;
        for(int i=k+1;i<=ma1;i++)
        {
            if(!(k*i%(i-k)))
                v.emplace_back((k*i)/(i-k),i);
        }
        cout<<v.size()<<endl;
        for(auto & x:v)
        printf("1/%d = 1/%d + 1/%d\n",k,x.first,x.second);
    }
    return 0;
}
