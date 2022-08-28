// Link : https://codeforces.com/problemset/problem/1520/A
// Topic : 
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
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == s[i+1]) continue;
        for(int j = i+1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }   
    cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}