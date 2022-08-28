// Link : https://codeforces.com/problemset/problem/1539/A
// Topic :   combinatorics    geometry    greedy    math    *1000
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin >> k;
    while(k--) {
        lli n, x, t;
        cin >> n >> x >> t;
        // if(n == x && n == t) {
        //     cout << n-1 << endl;
        // }
        if((n-1) * x <= t) {
            cout << ((n-1) * n) /2 << endl;
        }
        else {
            lli mx = t / x;
            lli rem = n - mx - 1;
            cout << (mx * (mx + 1) /2) + (rem * mx) << endl;
        }
    }
    return 0;
}