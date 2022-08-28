// Link : https://cses.fi/problemset/task/1092
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    lli n;
    cin >> n;
    int nn = n;
    lli t = n * (n+1)/2;
    if(t&1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    lli half = t / 2;
    int is_used = -1;
    vector<lli> s1,s2;
    while(half >= 1) {
        if(half >= n) {
            half -= n;
            s1.push_back(n);
            n--;
        }
        else {
            s1.push_back(half);
            is_used = half;
            break;
        }
    }
    cout << s1.size() << endl;
    for(lli &i : s1) cout << i << " ";
    cout << endl << nn - s1.size() << endl;
    for(;n >= 1; n--) {
        if(is_used == n) continue;
        cout << n << " ";
    }

    return 0;
}