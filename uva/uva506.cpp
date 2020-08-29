#include<string>
#include<list>
#include<sstream>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

const int maxn =100000;

vector<string> buffer;
map<string,int> pool;
vector<int> depend[maxn];
vector<int> depend1[maxn];
list<string> installed;
int status[maxn];

int insert_item(string temp)
{
    if(pool.count(temp))
        return pool[temp];
    buffer.push_back(temp);
    int no = buffer.size()-1;
    pool[temp]=no;
//    cout<<endl<<temp<<" "<<no<<endl;
    return no;
}
void add_depend(string temp,int father)
{
    int no= insert_item(temp); 
    depend[father].push_back(no);
    depend1[no].push_back(father);
}

bool needed(int now)
{
    for(auto x:depend1[now])
        if(status[x])
            return true;
    return false;
}
void remove(string temp,bool flag)
{
    int no =insert_item(temp);
    if(!status[no])
    {
        if(flag)
        cout<<"   "<<temp<<" is not installed.\n";
        return ;
    }
    if(needed(no))
    {
        if(flag)
        cout<<"   "<<temp<<" is still needed.\n";
        return ;
    }
    if(status[no]==2 && !flag)
        return;
    cout<<"   "<<"Removing "<<temp<<endl;
    installed.remove(temp);
    status[pool[temp]]=0;
    for(int next : depend[no])
    {
        remove(buffer[next],false);
    }
}
void install(string temp,bool flag)
{
    if(pool.count(temp) && status[pool[temp]] )
    {
        if(flag)
            cout<<"   "<<temp<<" is already installed.\n";
         return ;
    }
    for(auto next: depend[pool[temp]])
    {
        install(buffer[next],false);
    }
    if(flag)
        status[pool[temp]]=2;
    else status[pool[temp]]=1;
    installed.push_back(temp);
    cout<<"   Installing "<<temp<<endl;
}
void show()
{
    auto ite = installed.begin();
    for(;ite!= installed.end();++ite)
        cout<<"   "<<*ite<<endl;
}
void read(string line)
{

    string temp;
    stringstream ss(line);
    ss>>temp;
    int no;
    switch(temp[0])
    {
        case 'D':
            cout<<line<<endl;
            ss>>temp;
            no = insert_item(temp);
            while(ss>>temp)
            {
                add_depend(temp,no);
            }
            break;
        case 'R':
            ss>>temp;
            cout<<"REMOVE "<<temp<<"\n";
            remove(temp,true);
            break;
        case 'I':
            cout<<"INSTALL ";
            ss>>temp;
            cout<<temp<<"\n";
            install(temp,true);
            break;
        case 'L':
            cout<<"LIST\n";
            show();
            break;
    }
}
int main()
{
    string line;
    while(getline(cin,line))
    {
        if(line=="END")
        {
            cout<<"END\n";
            memset(status,0,sizeof(status));
            installed.clear();
            continue;
        }
        read(line);
    }

    return 0;

}
