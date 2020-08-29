#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x,y;
    Node(int x,int y):x(x),y(y){}
    bool operator < (const Node & cur) const{
        return x < cur.x;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;

        int a[n], f[n], g[n];
        for (int i = 0;  i < n;++i) cin >> a[i];
        int le = 0, ri = 0;
        set<Node> buffer;
        int best = -1;
        if (n == 1) {
            cout << "1\n";
            continue;
        } 
        while(ri < n)
        {
            while (++ri < n)
            {

                if (a[ri] <= a[ri - 1]) break;
            }
            for (int i = le; i < ri; ++i)
            {
                f[i] = i - le + 1;
                g[i] = ri - i - 1;

                Node cur(a[i], f[i]);
                if (buffer.size() == 0) { buffer.insert(cur); best = max(best, f[i] + g[i]); continue;}
                auto ite = buffer.lower_bound(cur);
                bool update = false;
                
                // 1.| cur( 3 ), lower()| size = 1
                // 2. | lower(4) cur(5) | size = 1;
                // 3. | lower = cur = 4 | 

                int ans;
                if (ite == buffer.end()) { 
                    auto itee = ite;
                    if ((--itee) ->y >= f[i]) {
                        best = max(best, itee -> y + g[i]  + 1);
                        continue;
                    }else{
                        buffer.insert(cur); best = max(best, g[i] + f[i]); continue;
                    }
                }else
                {
                    if (ite -> x == a[i]) {
                        if (ite -> y >= f[i]) {
                            ans = ite -> y;
                        }else{
                            ite = buffer.erase(ite);
                            update = true;
                        }
                    }else{
                        auto itee = ite;
                        if (ite == buffer.begin())  update = true;
                        else{
                            --ite;
                            if (ite -> y >= f[i]) ans = ite -> y + 1;
                            else update = true;
                            ite = itee;
                        }
                    }
                }
                if (update)
                {
                    buffer.insert(cur); ans = f[i];
                    while (ite != buffer.end()){
                        if (ite -> y <= f[i]) {
                            ite = buffer.erase(ite);
                        }else break;
                    }
                }
                best = max(best, ans  + g[i]);
            }
            le = ri;
        }
        cout << best << "\n";
    }
    return 0;
}
