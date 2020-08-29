#include<bits/stdc++.h>
using namespace std;
using lint = long long ;
using ldouble = long double;

#define FILES
namespace {
auto fast_io = [] {
#ifndef DEBUG
#  ifndef INTERACTIVE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#  endif // INTERACTIVE
#  ifdef FILES
    freopen("in", "r", stdin);
#  endif // FILES
#endif // DEBUG
  return 0;
};
} // namespace

void err(istream_iterator<string> _it) {}
template<typename T,typename... Args>
void err(istream_iterator<string> _it, T a,Args... args) {cerr<<"\n"<<*_it<<" is "<<a<<endl;err(++_it,args...);}

//#define __debug true; // c++17
const bool _debug = true;
#define cerr if(_debug)cerr
#define eb emplace_back
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << "\n";
#define error(args...) if(_debug){string _s = #args; replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s); istream_iterator<string> _itt(_ss);err(_itt,args);} 

int main()
{
    fast_io();
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n], last[n];
        map<int,int> buffer;
        for (int i = 0; i < n; ++i) { 
            cin >> a[i]; 
            if(buffer.count(a[i]) == 0) last[i] = -1; 
            else last[i] = buffer[a[i]];
            buffer[a[i]] = i;
        }

        int high = 0, low = 0, ans = -1;
        while (high < n)
        {
            while (high < n && last[high] < low) ++high;
            ans = max(ans, high - low);
            ++low;
        }

        cout << ans << endl;
    }
    return 0;
}

