#include<string>
#include<iostream>
using namespace std;

string pre,in;

void build(int l1,int r1,int l2,int r2)
{
    int root=in.find(pre[l1]);
    if(root>l2) build(l1+1,l1+root-l2,l2,root-1);
    if(root<r2) build(r1-r2+root+1,r1,root+1,r2);
    cout<<in[root];
}
int main()
{
    while(cin>>pre>>in)
    {
        build(0,pre.size()-1,0,in.size()-1);
        cout<<endl;
    }
    return 0;
}
