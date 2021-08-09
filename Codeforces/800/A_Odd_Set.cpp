// Link : https://codeforces.com/problemset/problem/1542/A
// Topic : math
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
        int n;
        cin >> n;
        int odd = 0, even = 0;
        for(int i = 0; i < n * 2; i++) {
            int w;
            cin >> w;
            if((w & 1) == 1) odd++;
            else even++;
        }
        if(odd == even) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
    
}