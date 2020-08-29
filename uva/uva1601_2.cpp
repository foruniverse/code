// double - BFS 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 20;
const int maxc = 200;
char dataset[maxn][maxn];
int cont[200],turn[maxc][maxc]; // 4<= w,h <=16  total 192 empty spaces

const int dx[] = {1,-1,0,0,0};
const int dy[] = {0, 0,1,-1,0};

int s[3],t[3],dis[maxc][maxc][maxc],dis_1[maxc][maxc][maxc]; // initial ghost , distination ghost ,store distance for each status;


int encode(int a,int b,int c)
{
    return (a<<16) | (b<<8) | c;// each ghost hold 8 bits;
}

bool conflict(int a,int b,int a2,int b2)
{
    if(b2 == a2 || (a2 == b && b2 ==a)) return true;
    return false;
}
int bfs()
{
    //cout<<"destination:"<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
    memset(dis,-1,sizeof(dis));
    memset(dis_1,-1,sizeof(dis_1));

    queue<int> que;
    queue<int> que_1;
    que.push(encode(s[0],s[1],s[2]));
    que_1.push(encode(t[0],t[1],t[2]));
    dis[s[0]][s[1]][s[2]] = 0;
    dis_1[t[0]][t[1]][t[2]] = 0;
    while(!que.empty() || !que_1.empty())
    {
        if(!que.empty()) 
        {
            int now = que.front(); que.pop();
            int a = now >>16 , b = (now >> 8) & 0xff, c =(now) & 0xff;//decode
#ifdef DEBUG
            cout<<"test:";
            cout<<a<<" "<<b<<" "<<c<<endl;
            cout<<cont[a]<<" "<<cont[b]<<" "<<cont[c]<<endl;
#endif
            if(dis_1[a][b][c]!=-1) return dis[a][b][c]+dis_1[a][b][c];
            for(int i=0;i < cont[a];++i)
            {
                int a2 = turn[a][i];
                for(int j = 0;j < cont[b];++j)
                {
                    int b2 = turn[b][j];
#ifdef DEBUG
                    cout<<"a2:"<<a2<<" b2:"<<b2<<endl;
                    cout<<"a:"<<a<<" b:"<<b<<endl;
#endif 
                    if(conflict(a,b,a2,b2)) 
                        continue;
                    for(int k = 0;k < cont[c];++k)
                    {
                        int c2 = turn[c][k];
                        if(conflict(a,c,a2,c2) || conflict(b,c,b2,c2)) continue;
                        if(dis[a2][b2][c2]==-1)
                        {
                            dis[a2][b2][c2] = dis[a][b][c] + 1;
                            que.push(encode(a2,b2,c2));
                        }

                    }
                }
            }
        }
        if(!que_1.empty())
        {
            int now = que_1.front(); que_1.pop();
            int a = now >>16 , b = (now >> 8) & 0xff, c =(now) & 0xff;//decode
#ifdef DEBUG
            cout<<"test:";
            cout<<a<<" "<<b<<" "<<c<<endl;
            cout<<cont[a]<<" "<<cont[b]<<" "<<cont[c]<<endl;
#endif
            if(dis[a][b][c]!=-1) return dis[a][b][c]+dis_1[a][b][c];
            for(int i=0;i < cont[a];++i)
            {
                int a2 = turn[a][i];
                for(int j = 0;j < cont[b];++j)
                {
                    int b2 = turn[b][j];
#ifdef DEBUG
                    cout<<"a2:"<<a2<<" b2:"<<b2<<endl;
                    cout<<"a:"<<a<<" b:"<<b<<endl;
#endif 
                    if(conflict(a,b,a2,b2)) 
                        continue;
                    for(int k = 0;k < cont[c];++k)
                    {
                        int c2 = turn[c][k];
                        if(conflict(a,c,a2,c2) || conflict(b,c,b2,c2)) continue;
                        if(dis_1[a2][b2][c2]==-1)
                        {
                            dis_1[a2][b2][c2] = dis_1[a][b][c] + 1;
                            que_1.push(encode(a2,b2,c2));
                        }

                    }
                }
            }

        }
    }
    return -1;
}

int main()
{
    int w,h,n;
    while(scanf("%d%d%d\n",&w,&h,&n)==3 && w && h && n)
    {
        int no = 0;
        int x[maxc], y[maxc], id[maxn][maxn];
        for(int i=0;i<h;i++)
        {
            fgets(dataset[i],20,stdin);
            for(int j = 0;j<w;++j)
            {
                //                printf("%c",dataset[i][j]);
                if(dataset[i][j] != '#')
                {
                    x[no]=i,y[no]=j; 
                    id[i][j] = no;
                    if(isupper(dataset[i][j])) t[dataset[i][j] - 'A'] = no;
                    else if(islower(dataset[i][j])) s[dataset[i][j] - 'a'] = no;
                    no++;
                }
            }
            //           putchar('\n');
        }
        for(int i =0 ; i < no;i++)
        {
            cont[i] = 0;
            for(int j = 0; j < 5; j++)
            {
                int nx = x[i] + dx[j] , ny = y[i] + dy[j];
                if(dataset[x[i] + dx[j]][y[i] + dy[j]] != '#')
                {
                    turn[i][cont[i]] = id[nx][ny];
                    cont[i] ++;
                }
            }
        }


        if(n<=2) { cont[no]=1 ; turn[no][0] = no; s[2] = t[2] = no++; }
        if(n<=1) { cont[no]=1 ; turn[no][0] = no; s[1] = t[1] = no++; }

        printf("%d\n",bfs());
    }
    return 0;
}
