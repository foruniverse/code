#include<bits/stdc++.h>
using namespace std;
using lint = long long ;
using ulint = unsigned long long ;
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
    ulint ans = 0;
    int n; cin >> n;
    int last = 0;
    int temp;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        int cha = temp - last;
        if (cha < 0) ans += -cha;
        else last = temp;
    }
    cout << ans << "\n";
    return 0;
}

