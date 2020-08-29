#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctype.h>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        string buffer;
        cin>>buffer;
        vector<long long> weight; 
        int depth=0;
        for(int i=0;i<buffer.size();i++)
        {
            if(buffer[i]=='[')
                depth++;
            else if(buffer[i]==']')
                depth--;
            else if(isdigit(buffer[i]))
            {
                int temp  = i;
                while(isdigit(buffer[++i]));
                i--;
                int now=0;
                for(int j=i;j>=temp;j--)
                {
                    now+=pow(10,i-j) * (buffer[j]-'0');
                }
                weight.push_back((long long)now*pow(2,depth));
            }
        }
        if(weight.size()==1) 
        {
            cout<<"0"<<endl;
            continue;
        }
        sort(weight.begin(),weight.end());
        
        int best =-1;
        int first =0;
        int count=0;
        for(int i=0;i<weight.size();i++)
        {
            if(weight[i]==weight[first])
            {
                count++;
            }else {
                best =count>best?count:best;
                count=1;
                first = i;
            }
        }
        best =count>best?count:best;
        cout<<weight.size()-best<<endl;
    }
    return 0;
}
