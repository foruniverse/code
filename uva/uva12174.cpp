/*
 *暴力过了，笑死我了
 */
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
    int t; cin >> t;
    while(t--)
    {
        int s, n; cin >> s >> n;
        int a[n], g[s + 1];
        int ans = 0, cont = 0;
        memset(g, 0, sizeof(g));
        bool flag = true;
        for (int i = 0; i < n; ++i) { 
            cin >> a[i]; 
            if (i <= s) { if (g[a[i]] && flag) cont = i, flag = false; else g[a[i]] = 1; }
        }
        if ( n <= s && cont == 0 )
        {
            cout << s << "\n";
            continue;
        }
        int temp = 0;
        for (int i = 1; i <= cont; ++i)
        {
            memset(g, 0, sizeof(g));
            int id = 0, ok  = 1;
            for (int j = i; j < n; ++j)
            {
                ++id;
                if (g[a[j]]) { ok = 0; break; } 
                else g[a[j]] = 1;
                if (id == s) {
                    memset(g, 0, sizeof(g));
                    id = 0;
                }
            }
            if (ok) ans++;
        }
        cout << ans << "\n";

    }

    return 0;
}



