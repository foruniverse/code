#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> temp;
//1. 统计10进制数位
void digit_count(int n)
{
    temp.clear();
    int count=0;
    while(n)
    {
        ++count;
        temp.push_back(n%10);
        n/=10;
    }
}

//2.permutation
void permutation()
{
    vector<int> v{1,2,3,4};
    sort(v.begin(),v.end());
    do{
        for(auto &x: v) cout<<x<<" ";
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
}
//3. 位视图法找子集
void print_subset(int n,int *b,int cur)
{
    if(cur == n)
    {
        for(int i=0;i<n;i++)
        {
            if(b[i]==1)
                cout<<i<<" ";

        }
        cout<<endl;
        return ;
    }
    b[cur]=1;
    print_subset(n,b,cur+1);
    b[cur]=0;
    print_subset(n,b,cur+1);

}
//4.二进制数位找子集
void print_subset(int n,int s)
{
    for(int i=0;i<n;i++)
    {
        if(s&(1<<i))
            cout<<i<<" ";

    }
    cout<<endl;

}
int main()
{


}
}
}
int main()
{
//    no.1
        // int a[5]={0};
        //print_subset(5,a,0);
        //no.2
        int n=3;
    for(int i=0;i<(1<<n);i++)
    {
        print_subset(n,i);
    }

    permutation();
    return 0;

}
