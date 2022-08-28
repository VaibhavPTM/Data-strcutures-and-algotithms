// Link : https://codeforces.com/contest/1462/problem/D
#include<bits/stdc++.h>
using namespace std;
bool prime(int n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
#define TEST int t = 1; cin >> t; while(t--) solve();
#define lli long long
#define p(A,B) pair<A,B>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define vec(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vec(int) ar(n);
    lli sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    for(int i = n; i >= 1; i--) {
        if(sum % i != 0) continue;
        int need = sum / i;
        int curr_sum = 0;
        bool ok = true;
        for(int j = 0; j < n; j++) {
            curr_sum += ar[j];
            if(curr_sum > need) {
                ok = false;
                break;
            }
            else if(curr_sum == need) {
                curr_sum = 0;
            }
        }
        if(ok) {
            cout << n-i << endl;
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
    TEST
    return 0;
}