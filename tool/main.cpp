#include<bits/stdc++.h> 
using namespace std;

const int maxn = 1e2;
char buffer[maxn];

int turn(char temp)
{
    if(temp == '+') return 0; 
    if(temp == '-') return 1;
    if(temp == '*') return 2;
    if(temp == '/') return 3;
    if(temp == '(') return 4;
    if(temp == ')') return 5;
    if(temp == '#') return 6;
}


int cmp[7][7]={
    /* #  + - * / ( ) */
    {  -1,-1,-1,1,1,1,-1   },
    {  -1,-1,-1,1,1,1,-1   },
    {  -1,-1,-1,-1,-1,1,-1 },
    {  -1,-1,-1,-1,-1,1,-1 },
    {  -1, 1,1,1,1,1,0 },
    {  -1, -1,-1,-1,-1,-1,-1 },
    {  1,1,1,1,1,1,1 },
};
double cal(char op,double a,double b)
{
    switch(op)
    {
        case '+':
            return a + b;
        case '-':
            return  a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}
double solve()
{
    stack<double> opnd;
    stack<char> optr;
    int len = strlen(buffer);

    optr.push('#');

    for(int i = 0; i < len; ++i)
    {
        char now = optr.top();
        char  cur = buffer[i];
        if(isdigit(cur)) { opnd.push(cur - '0'); continue; }

        switch(cmp[turn(now)][turn(cur)])
        {
            case -1:
                {
                    double b = opnd.top(); opnd.pop();
                    double a = opnd.top(); opnd.pop();
                    opnd.push(cal(optr.top(),a,b)); optr.pop(); optr.push(cur);
                    break;
                } 
            case 0:
                optr.pop();
                break;
            default:
                optr.push(cur);
        }

    }
    return opnd.top();

}
int main()
{
    freopen("in","r",stdin);
    while(fgets(buffer,maxn,stdin) != NULL)    
    {
        fputs(buffer,stdout);
        printf("%.4lf\n",solve());
    }
    return 0;
}
