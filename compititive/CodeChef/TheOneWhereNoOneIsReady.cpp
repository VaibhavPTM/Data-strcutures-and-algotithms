// Link : https://www.codechef.com/FOUR21B/problems/S03E02
#include<bits/stdc++.h>
using namespace std;
#define lli long long
bool prime(int n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
lli POW (lli a, lli p, lli m) { lli res = 1; while (p > 0) { if(p % 2 == 0){ p /= 2; a = ((a%m)*(a%m))%m; } else{ res = ((res%m)*(a%m))%m; p--; }}return res;}
#define TEST int t = 1; cin >> t; while(t--) solve();
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = -1;
    for(char c = 'A'; c <= 'Z'; c++) {
        string t = s;
        int l = -1, f = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                t[i] = '1';
            }
            else {
                t[i] = '0';
                l = i;
                if(f == -1) {
                    f = i;
                }
            }
        }
        int tres = 0;
        if(k == 0 && f != -1) {
            tres = -1;
        }
        else  {
            if(f == -1) {
                tres = n;
            }
            else {
                vec(int) tt;
                int cnt = 0;
                tres = f + (n - l - 1);
                for(int i = f; i <= l; i++) {
                    if(t[i] =='1') cnt++;
                    else {
                        tt.pb(cnt);
                        cnt = 0;
                    }
                }
                if(cnt) tt.pb(cnt);
                sort(allr(tt));
                int ii = 0, kk = k-1;
                while(kk-- && ii < tt.size()) {
                    tres += tt[ii];
                    ii++;
                }
            }
            res = max(res,tres);
        }
    }
    cout << res << endl;
}
int main() {
    SPEED
    TEST
    return 0;
}