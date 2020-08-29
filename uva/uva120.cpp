#include<bits/stdc++.h>
using namespace std;

const int maxn = 31;
int buffer[maxn];

const bool debug = false;
#define cerr if(debug) cerr

void turn(int k) {
    int fake[maxn];
    memcpy (fake, buffer, 4 * (k + 1));
    for (int i = 0; i <= k; ++i) cerr << fake[i] << " \n"[i == k];
    for(int i = k; i >=0; --i) buffer[i] = fake[k - i];
    for (int i = 0; i < 5; ++i) cerr << buffer[i] << " \n"[i == 4];
    cerr << "turn end\n";
}

int main()
{
    string line;
    while(getline(cin, line))
    {
        stringstream ss(line);
        int temp, cont = 0;
        while(ss >> temp)
        {
            buffer[cont++] = temp; 
            cout << temp << " ";
        }
        cout << "\n";
        int sorted[cont]; 
        memcpy (sorted, buffer, cont * 4);
        sort (sorted, sorted + cont);
        vector<int> ans;
        for (int i = cont - 1; i > 0; --i)
        {
            int cur = buffer[i];
            if (cur == sorted[i]) continue;
            for (int j = i - 1; j >= 0; --j)
            {
                if(buffer[j] != sorted[i]) continue;
                if(j != 0) {
                    cerr << "fuck\n";
                    turn (j); ans.push_back (cont - j);
                }
                turn (i); ans.push_back (cont -i);
                cerr << "buffer: ";for (int i = 0; i < cont; ++i) cerr << buffer[i] << " \n"[i == cont - 1];
            }
        }
        for(auto & x : ans) cout << x << " "; cout << "0\n";
    }
}
