// Link : https://codeforces.com/problemset/problem/1530/B
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
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(i == 1){
                if(w & 1) {
                    cout << (j&1 ? "1" : "0");
                }
                else {
                    cout << (j&1 ? "0" : "1");
                }
            }
            else if(i != h) {
                if(i&1){
                    cout << (j == 1 || j == w ? "1" : "0");
                }else cout << "0";
            }
            else {
                if(h&1 || (j > 2 && j < w-1)) {
                    if(w & 1) {
                        cout << (j&1 ? "1" : "0");
                    }
                    else {
                        cout << (j&1 ? "0" : "1");
                    }
                }
                else {
                    cout << "0";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
    
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