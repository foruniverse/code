#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e2;

int buffer[maxn];
void init()
{
    for(int i = 1; i <= maxn; ++i)  buffer[i - 1]  = i;
}

int binSearch(int le ,int ri, int tar)
{
    sort(buffer, buffer + maxn);
    while(le < ri)
    {
        int m = le + (ri - le) / 2;
        if(buffer[m] == tar)  return m;
        if(buffer[m] > tar)  ri = m;
        else le = m + 1;
    }
    return -1;
}

int lowerBound(int le, int ri ,int tar)
{
    sort(buffer,buffer + maxn);
    while(le < ri)
    {
        int m = le + (ri -le) / 2;
        if(tar <= buffer[m]) ri = m;
        else le = m + 1;
    }
    return le;
}

int upperBound(int le, int ri ,int tar)
{
    sort(buffer, buffer + maxn);
    while(le < ri)
    {
        int m = le + (ri -le) / 2;
        if(buffer[m] <= tar) le = m + 1;
        else ri = m;
    }
    return ri;
}
int main()
{
   init(); 
   int tar ; 
   while(cin >> tar)
    cout << binSearch(0, maxn, tar) << "\n"  << "uppder:" << upperBound(0, maxn, tar) << "\n lower:" << lowerBound(0, maxn, tar) << "\n";
   return 0;

}
