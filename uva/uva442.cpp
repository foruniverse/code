#include<stack>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;


struct Matrix{
    int x,y;
    Matrix(int x=0,int y=0):x(x),y(y) {}
} matrix[30];

stack<Matrix> buffer;
// 栈放外面防止报栈

int suan()
{
    int x_1=buffer.top().x;
    int y_1=buffer.top().y;
    buffer.pop();
    int x_2=buffer.top().x;
    int y_2=buffer.top().y;
    buffer.pop();
    if(y_1!=x_2)
    {
        cout<<"error\n" ;
        return 0;
    }
    buffer.push(Matrix(x_2,y_1));
    return  x_2 * y_2 * y_1;
}
int main()
{
    int n;
    scanf("%d",&n);
    char temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        cin>>matrix[temp-'A'].x>>matrix[temp-'A'].y;
    }
    // for(int i=0;i<sizeof(matrix)/sizeof(Matrix);i++)
    // {
    //     if(matrix[i].x)
    //     {
    //         cout<<char(i+'A')<<" "<<matrix[i].x<<","<<matrix[i].y<<endl;
    //     }
    // }
    // input above
    string cal;

    while(cin>>cal)
    {
        int count=0;
        bool error=false;
        //      cout<<cal<<" "<<cal.length()<<endl;
        for(int i=0;i<cal.length();i++)
        {
            //问题的关键是这个表达式太简单了。没有任何优先级的问题，直接一股脑算就完事了
            //l            cout<<cal[i]<<" : ";
            //唯一需要注意的是括号会改变运算顺序
            if(isalpha(cal[i]))  buffer.push(matrix[cal[i]-'A']);
            else if(cal[i]==')')
            {
                int x_1=buffer.top().x;
                int y_1=buffer.top().y;
                buffer.pop();
                int x_2=buffer.top().x;
                int y_2=buffer.top().y;
                buffer.pop();
                if(y_2!=x_1)
                {
                    error=true;
                    cout<<"error\n" ;
                    break;
                }
                buffer.push(Matrix(x_2,y_1));
                count += x_2 * y_2 * y_1;
            }
        }
        //        if(!buffer.empty() && buffer.size()!=1 && !error)
        //        {
        //            while(!buffer.empty())
        //            {
        //                count+=suan();
        //            }
        //        }
        if(!error) cout<<count<<endl; 
    }
    return 0;
}
