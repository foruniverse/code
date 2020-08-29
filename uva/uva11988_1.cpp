#include<list>
#include<iostream>
#include<string>
using namespace std;


/*
 *list 的成员函数
 list.insert(list<typename>::iterator ite,insert_count,insert_value);
 list.insert(list<typename>::iterator ite,insert_value); insert_count默认为1
 list.push_back(value);
 list.push_front(value);
 */
int main()
{
    string s;
    while(cin>>s)
    {
        list<char> buffer;
        list<char>::iterator cur;
        cur=buffer.begin();
        for(int i=0;i<s.size();i++) 
        {
            if(s[i]=='[')
            {
                cur=buffer.begin();
            }
            else if(s[i]==']')
                cur=buffer.end();
            else 
                buffer.insert(cur,s[i]);
        }
        for(auto ite=buffer.begin();ite!=buffer.end();ite++)
            cout<<*ite;
        cout<<endl;
    }    
    return 0;
}
