#include<iostream>
#include<set>
#include<cstring>
#include<string>
using namespace std;

const int maxstate=1e+7; 
using state = int[9];

const state goal{1,2,3,8,0,4,7,6,5};
state st[maxstate];

set<int> vis;
void init_table()
{vis.clear();}
int insert_table(int cur)
{
    int v = 0;// sheng kong jian
    for(int i=0;i<9;i++) v = v * 10 +st[cur][i];
    if(vis.count(v)) return 0;
    vis.insert(v);
    return 1;
}
//set<int> vis;
//void init_table() { vis.clear(); }
//int insert_table(int s) {
//  int v = 0;
//  for(int i = 0; i < 9; i++) v = v * 10 + st[s][i];
//  if(vis.count(v)) return 0;
//  vis.insert(v);
//  return 1;
//}
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int dis[maxstate];

bool inside(int x,int y)
{
    return x>=0 && x<3 && y>=0 && y<3;
}
int bfs()
{
    init_table();
    int font =1, rear =2;
    while(font < rear)
    {
        state & s = st[font];
 //       for(int i=0;i<9;i++) printf("%d ",s[i]); putchar('\n');
        if(memcmp(goal,s,sizeof(s))==0) return font;
        int i;
        for(i=0;i<9;i++) if(s[i]==0) break;
        int now_x = i/3,now_y = i%3;
        for(int j=0;j<4;j++)
        {
            int move_x = now_x + dx[j],move_y = now_y + dy[j]; 
            int move_z = move_x * 3 + move_y;
            if(inside(move_x,move_y))
            {
                state & t =st[rear];
                memcpy(&t,&s,sizeof(s));
                t[i]=s[move_z];
                t[move_z]=s[i];
                dis[rear] = dis[font] +1;
                if(insert_table(rear))// panchong
                    rear++;
            }
        }
        font++;
    }
    return 0;
}
int main()
{
    char  temp[10];
    while(scanf("%s",temp)==1)
    {
        memset(st,0,sizeof(st));
        memset(dis,0,sizeof(dis));
        for(int i=0;i<9;i++)
        {
           st[1][i]=temp[i]-'0'; 
        }
//        for(auto x:st[1])
//            cout<<x<<" ";
//        cout<<endl;
//
//        cout<<"------\n";
        int id =bfs();
        cout<<dis[id]<<endl;
//        if(id == 0) printf("-1\n"); 
 //       else {
 //           for(auto & x: st[id])
 //               cout<<x<<" ";
 //           cout<<"\n";
 //           cout<<"ans:"<<dis[id]<<endl;
 //       }
    }

    
    return 0;
}
