#include<iostream>
#include<set>
#include<cstring>
#include<list>
#include<queue>
using namespace std;

typedef deque<int> pile;
bool isvalid(int x,int y,int a)
{
//    cout<<"world\n";
    int temp = x+y+a;
    return temp==10  || temp ==20 || temp==30;
}

int main()
{
    while(true)
    {
        queue<int> que;
        int temp;
        cin>>temp;
        if(!temp)
            break;
        que.push(temp);
        for(int i=1;i<52;i++) 
        {
            cin>>temp; que.push(temp);
        }
        list<deque<int>> pool;
        for(int i=0;i<7;i++)
        {
            pool.push_back(pile {que.front()});
            que.pop();
        }
        set<pair<queue<int>,list<pile>>> exam;
        exam.emplace(que,pool);
        int win=0,draw=0,idx=7;
        for(auto pos = pool.begin();que.size();)
        {
            idx++;
            pos->push_back(que.front());
            que.pop(); 

  //          cout<<pos->size()<<endl;
 //           cout<<"nmsl"<<endl;
            while(pos->size()>=3)
            {
   //             cout<<"in"<<endl;
    //            cout<<pos->size()<<endl;
                pile & cur=*pos;

     //           cout<<"hello"<<endl;
      //          cout<<cur[0]<<endl;
                if(isvalid(cur[0],cur[1],cur[cur.size()-1]))
                {
       //             cout<<"1"<<endl;
                    que.push(cur[0]);
                    que.push(cur[1]);
                    que.push(cur[cur.size()-1]);
                    cur.pop_front();
                    cur.pop_front();
                    cur.pop_back();
                }
                else if(isvalid(cur[0],cur[cur.size()-2],cur[cur.size()-1]))
                {
        //            cout<<"2"<<endl;
                    que.push(cur[0]);
                    que.push(cur[cur.size()-2]);
                    que.push(cur[cur.size()-1]);
                    cur.pop_front();
                    cur.pop_back();
                    cur.pop_back();
                }else if(isvalid(cur[cur.size()-1],cur[cur.size()-2],cur[cur.size()-3]))
                {
         //           cout<<"3"<<endl;
                    que.push(cur[cur.size()-3]);
                    que.push(cur[cur.size()-2]);
                    que.push(cur[cur.size()-1]);
                    cur.pop_back();
                    cur.pop_back();
                    cur.pop_back();
                }else break;
            }
          //  cout<<"fuck"<<endl;
            auto pre= pos;
            pos++;
            if(pos==pool.end())
            {
           //     cout<<"pos->end->begin\n";
                pos=pool.begin();
            }
            if(pre->empty())
            {
                pool.erase(pre);
                if(pool.empty())
                {
                    win=1;
                    break;
                }
            }
            if(!exam.emplace(que,pool).second)
            {
                win=-1;
                break;
            }

        }
        if(win==-1) cout<<"Draw: "<<idx<<endl;
        else if(win) cout<<"Win : "<<idx<<endl;
        else cout<<"Loss: "<<idx<<endl;
    }
    return 0;
}
