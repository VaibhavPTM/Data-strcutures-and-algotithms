// Link : https://codeforces.com/problemset/problem/1579/C
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
#define print(x) for(auto it:x) cout<<it;
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

bool c(vec(string) a,vec(string) b){
    for(int i = 0; i  <a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}
void combin(vec(string) &a,vec(string) &b, int n, int m, int k){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(a[i][j] == '*') {
                int t = 0, t1 = 0;
                int x = i - 1, y = j - 1;
                while(x >= 0 && y >= 0 && a[x][y] == '*') {
                    t++;
                    x--;
                    y--;
                }
                int x1 = i - 1, y1 = j + 1;
                while(x1 >= 0 && y1 < m && a[x1][y1] == '*') {
                    t1++;
                    x1--;
                    y1++;
                }
                if(t >= k & t1 >= k){
                    int d = min(t,t1);
                    b[i][j] = '*';
                    x = i-1, y = j-1;
                    for(int i = 0; i < d; i++){
                        b[x][y] = '*';
                        x--;y--;
                    }
                    x = i-1, y = j+1;
                    for(int i = 0; i < d; i++){
                        b[x][y] = '*';
                        x--;y++;
                    }
                }
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vec(string) ar, res;
    string t;
    for(int i = 0; i < m; i++) t.pb('.');
    for(int i = 0; i < n; i++) {
        string ii;
        cin >> ii;
        ar.pb(ii);
        res.pb(t);
    }
    combin(ar,res, n, m,k);
    if(c(ar,res)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    TEST
    return 0;
}