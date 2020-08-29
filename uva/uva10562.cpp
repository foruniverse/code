#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
//string类真jb蛋疼
using namespace std;
const int maxn=200+5;
string buffer[maxn];
int n;
int count ;

void print(int nn)
{
    for(int i=1;i<=nn;i++)
        cout<<buffer[i]<<endl;
}

void dfs(int line,int now)
{
    if(line==count)
        return; 
    if(buffer[line+1][now]!='|')
        return;
    int  le = now;
    int ri = now;
    //cout<<buffer[line+2];
    //if(buffer[line+2][3]=='-')
    //   cout<<"yes";
    while(buffer[line+2][--le]=='-');
    le = le +1;
    while(buffer[line+2][++ri]=='-');
    ri=ri-1;
    //cout<<le<<" - "<<ri;
    for(int i=le;i<=ri;i++)
    {
        char temp = buffer[line+3][i];
        //数据真jb坑
        if(temp!='-' && temp!=' ' && (int)temp != 0  && temp !='|')
        {
            //    cout<<"zifu:"<<temp<<" digit: "<<(int)temp<<endl;
            //            printf("(%d,%d):%c",line+3,i,buffer[line+3][i]);
            printf("%c(",buffer[line+3][i]);
            dfs(line+3,i);
            printf(")");
        }
    }
}
void solve()
{
    char temp;
    int now=0;
    for(;;)
    {
        char temp=buffer[1][now];
        if(temp !=' ' && temp != '|' && temp != '-' && (int)temp !=0)
            break;
        now++;
    }
    if(now>=buffer[1].size())
    {
        printf("()\n");
        return;
    }
    //    cout<<buffer[1][now]<<endl;
    temp = buffer[1][now]; 
    // printf("(%c",temp);
    printf("(%c(",buffer[1][now]);
    dfs(1,now);
    printf("))\n");
}
int main()
{

    string line;
    scanf("%d",&n); 
    getchar();
    while(n--)
    {
        count =0 ;
        while(getline(cin,buffer[++count]))
        {
            if(buffer[count][0]=='#')
            {
                count--;
                break;
            }
        }
        if(count!=0)
        {
            solve();
        }
        else printf("()\n");
    }
    return 0;
}
