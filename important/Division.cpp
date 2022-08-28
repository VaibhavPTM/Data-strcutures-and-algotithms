// Link : 
#include<bits/stdc++.h>
using namespace std;
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
#define print(x) for(auto it:x) cout<<it<<" ";
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

int help(int n) {
    for(int i = 3; i * i <= n; i++) {
        if(n % i == 0) return i;
    }
    return -1;
}

void solve() {
    lli n, a, b, ans = 0;
    cin >> n >> a >> b;
    if(a < 0 && b < 0) {
        cout << (n&1 ? b : a) << endl;
        return;
    }

    vec(p(int,int)) v;
    for(int i = 2 ; i*i <= n; i++) {
        if(n % i == 0) {
            int t = 0;
            while(n % i == 0) {
                n /= i;
                t++;
            }
            if(t > 0) v.push_back({i, t});
        }
    }
    if(n>1){v.push_back({n,1});};
    if(a>=0 && b>=0){
        for (int i = 0; i < v.size(); ++i){
            if(v[i].ff&1)
                ans+=v[i].ss*b;
            else
                ans+=v[i].ss*a;
        }
    }
    else if(a>=0 && b<0) {
        bool ch = 0;
        for (int i = 0; i < v.size(); ++i) {
        if(v[i].ff%2==0){
            ch = 1;
            ans+=v[i].ss*a;
            }
        }
        if(!ch)
            ans+=b;
        }
    else if(a<0 && b>=0) {
        bool ch = 0;
        for (int i = 0; i < v.size() ; ++i) {
            if(v[i].ff&1)
                ans+=v[i].ss*b;
            else
                ch=1;
        }
        if(ch)
            ans+=a;
    }
    cout << ans << endl;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    TEST
    return 0;
}