#include<bits/stdc++.h>
using namespace std;
using lint = long long ;
using ldouble = long double;

namespace {
auto fast_io = [] {
#ifndef DEBUG
#  ifndef INTERACTIVE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#  endif // INTERACTIVE
#  ifdef FILES
    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);
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
    freopen("in","r",stdin);
    fast_io();
    int t; cin >> t;
    while(t--)
    {
        int n,l; cin >> n >> l;
        int sum[n];
        char temp; cin >> temp;
        string line; getline(cin,line);
        cerr << line << endl;
        sum[0] = line[0] - '0';
        for (int i = 1; i < n; ++i) sum[i] = sum[i - 1]  + line[i] - '0';
        

        int best = 0, best1 = 1;
        int ans1 , ans2;
        ans1 = n, ans2 = n; 
        for (int i = l - 1; i <= n - l; ++i)
        {
            bool flag = true;
            for (int j = i - l + 1; j >= 0; --j)
            {
                int temp =  sum[i] - j == 0 ? 0 : sum[j - 1];
                int wide = i - j + 1;
                if (best * wide < temp * best1) { flag = false; best = temp, best1 = wide, ans1 = j,ans2 = i; }
                else if(best * wide == temp * best1) { 
                    if(wide < best1 || (wide == best1 && j < ans1)) { flag = false; best = temp, best1 = wide, ans1 = j ,ans2 = i; }
                }
            }
            //if (!flag) continue;

            for (int j = i - 1 + l; j < n; ++j)
            {
                int temp = sum[j] - i == 0 ? 0 : sum[i - 1]; 
                int wide = j - i + 1;
                if (best * wide < temp * best1) { best = temp, best1 = wide, ans1 = i,ans2 = j; }
                else if(best * wide == temp * best1) { 
                    if(wide < best1 || (wide == best1 && i < ans1)) { best = temp, best1 = wide, ans1 = i ,ans2 = j; }
                }
            }
        }
        cout << ans1 << ans2 << "\n";
    }
    return 0;
}

