// Link : https://codeforces.com/problemset/problem/1543/A
// Topic : greedy, math, number theory	
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
    int t;
    cin >> t;
    while(t--) {
        lli a,b;
        cin >> a >> b;
        lli c = abs(a - b);
        if(!c) cout << 0 << " " << 0 << endl;
        else cout << c << " " << min(a % c,c - a % c) << endl;
    }
    return 0;
}