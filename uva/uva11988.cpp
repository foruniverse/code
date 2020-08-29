#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int maxn=100000 + 5;
int next[maxn];
int main()
{
    //为什么从1开始，因为用数组模拟，起始是0，如果从0开始，那么首位（最左边的字符）无法用数组模拟
    string s;
    while(cin>>s)
    {
        int now=0, last=0;
        next[0]=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
               now=0;
            else if(s[i]==']')
                now=last;
            else {
                next[i+1]=next[now];
                next[now]=i+1;
                if(now == last) last=i+1;
                now=i+1;
            }
        }
        for(int i=next[0];i!=0;i=next[i])
            cout<<s[i-1];
        cout<<endl;
    }
    return 0;
}
