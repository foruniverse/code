#include<iostream> 
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

const int maxn = 65;

int board[maxn][maxn];
int n;
vector<int> ans;

vector<int> buffer;

void print_board(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(board[i][j])
                cout<<"*";
            else cout<<".";
        }
        cout<<endl;
    }
}
int cont=0;
bool check_black(int x,int y,int wide)
{
    for(int i=x;i<=x+wide-1;i++)
        for(int j=y;j<=y+wide-1;j++)
            if(board[i][j]==0)
                return false;
    return true;
}
void to_tree(int x,int y,int wide,int depth,double dir)
{

    if(check_black(x,y,wide))
    {
        ++cont;
    //    cout<<"in"<<endl;
        ans.push_back(dir); 
        //        printf("(%d,%d),width:%d depth:%d,dir:%d\n",x,y,wide,depth,(int)dir);
        return;
    }
    if(wide==1)
        return ;
    to_tree(x,y,wide/2,depth+1,dir+1*pow(5,depth));
    to_tree(x+wide/2,y,wide/2,depth+1,dir+3*pow(5,depth));
    to_tree(x,y+wide/2,wide/2,depth+1,dir+2*pow(5,depth));
    to_tree(x+wide/2,y+wide/2,wide/2,depth+1,dir+4*pow(5,depth));
}
int total(int n)
{
    int sum =0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(board[i][j]==1)
                sum++;
    return sum;
}
void read_pixel()
{
    memset(board,0,sizeof(board));
    string line;
    for(int i=1;i<=n;i++)
    {
        getline(cin,line);
        for(int j=1;j<=n;j++)
        {
            board[i][j]=line[j-1]-'0';
        }
    }
    //print_board(n);
    cont=0;
    ans.clear();
    to_tree(1,1,n,0,0);
    if(ans.size()) 
    {
        sort(ans.begin(),ans.end());
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)
        {

            if((i)%12==0)
            {
                cout<<endl;
                cout<<ans[i];
                continue;
            }
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    //cout<<total(n)<<endl;
    cout<<"Total number of black nodes = "<<cont<<endl;
    //   print_board(n);
}
void paint_board(int x,int y,int wide)
{
    for(int i=x;i<x+wide;i++)
        for(int j=y;j<y+wide;j++)
            board[i][j]=1;
}

void to_pixel(int now )
{
    int x=1,y=1,wide=-n; 
    if(now==0)
    {
        paint_board(1,1,-n);
        return ;
    }
    for(;;)
    {

        int turn = now%5  ;
        wide=wide/2;
        switch(turn)
        {
            case 2:
                y+=wide;
                break;
            case 3:
                x+=wide;
                break;
            case 4:
                x+=wide;
                y+=wide;
                break;
        }
        now=now/5;  
        // cout<<"chushu"<<now<<" yushu:"<<turn<<endl;
        if(now==0)
            break;
    }
    paint_board(x,y,wide);
}
void read_tree()
{
    int temp;
    buffer.clear();
    // print_board(-n);
    while(cin>>temp)
    {
        if(temp<0)
            break;
        buffer.push_back(temp);
    }
    for(auto x:buffer)
        to_pixel(x);
    // cout<<endl;
    
        print_board(-n);
    //to_pixel();
}
int main()
{
    int nmsl=0;
    cin>>n;
    while(true)
    {
        memset(board,0,sizeof(board));
        getchar();
        cout<<"Image "<<++nmsl<<endl;
        if(n>0)
        {
            read_pixel();
        }
        else 
        {
            read_tree();
        }
        cin>>n;
        if(n==0)
            break;
        else {

            cout<<endl;
        }
    }
    return 0;
}

