#include<bits/stdc++.h>
using namespace std;
using ulint = unsigned long long;
using lint = long long ;
using ldouble = long double;

void err(istream_iterator<string> _it) {}
template<typename T,typename... Args>
void err(istream_iterator<string> _it, T a,Args... args) {cerr<<"\e[91m"<<*_it<<" is "<<a<<"\e[39m"<<endl;err(++_it,args...);}

//#define __debug true; // c++17
const bool _debug = true;
#define cerr if(_debug)cerr
#define eb emplace_back
#define watch(args...) if(_debug){string _s = #args; replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);cerr<<"\n";istream_iterator<string> _itt(_ss);err(_itt,args);} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cont = 0; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if (n == 0)
        { cout << "Case " << ++cont << ": " << "Not possible\n"; continue; }
        int p[n], q[n]; 
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> q[i];
        
        int font = 0, ok = 0, sum = 0, cur = 0;
        
        // 建议死循环 + break 语句 设计循环语句, 容易写，少占用考场时间,
        for (;;)
        {
            sum += p[cur] - q[cur];
            int last = font == 0 ? n - 1 : font - 1;
            if (cur == last && sum >= 0) { ok = 1; break; }
            if ((cur == n -1 || cur <= last && font != 0 || cur == last && font == 0) && sum < 0 ) break;
            cur = cur == n -1 ? 0 : cur + 1; 
            if (sum < 0) { sum = 0; font = cur; }
        }
        if (ok) cout << "Case "  << ++cont << ": Possible from station "<< font + 1  << "\n";
        else cout << "Case " << ++cont << ": Not possible\n";
    }
    return 0;
}



