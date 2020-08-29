#include<bits/stdc++.h>
using namespace std;
using lint = long long ;
using ldouble = long double;

void err(istream_iterator<string> _it) {}
template<typename T,typename... Args>
void err(istream_iterator<string> _it, T a,Args... args) {cerr<<"\n"<<*_it<<" is "<<a<<endl;err(++_it,args...);}

//#define __debug true; // c++17
const bool _debug = true;
#define cerr if(_debug)cerr
#define eb emplace_back
#define error(args...) if(_debug){string _s = #args; replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s); istream_iterator<string> _itt(_ss);err(_itt,args);} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char temp;
    lint ans = 0;
    while(cin >> temp)
    {
        ans += temp - '0';
    }
    if(ans % 9 == 0) cout << "Yes\n";
    else cout << "No" << "\n";
    
    return 0;
}

