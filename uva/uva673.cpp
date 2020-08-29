#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int n;
string temp;

stack<char> buffer;
void solve()
{
    for(int i=0;i<temp.size();i++)
    {
        char now =temp[i];
        if(now == '(')
            buffer.push('(');
        else if(now =='[')
            buffer.push('[');
        else{
            if( buffer.empty())
            {
                cout<<"No\n";
                return ;
            }
            if(now==']' && buffer.top()!='[')
            {
                    cout<<"No\n";
                    return;
            }
            else if(now==')' && !buffer.empty() && buffer.top()!='(')
            {
                cout<<"No\n";
                return ;
            }
            buffer.pop();
        }
    }
    if(buffer.empty())
    cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
    cin>>n;
    getchar();
    while(n--)
    {
       while(!buffer.empty()) 
           buffer.pop();
       getline(cin,temp);
       if(temp=="")
       {
           cout<<"Yes\n";
           continue;
       } 
       solve();
    }
    return 0;
}


