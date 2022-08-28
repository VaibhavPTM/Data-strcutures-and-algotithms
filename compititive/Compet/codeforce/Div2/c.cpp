// Link : 
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define v(T) vector<T>
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
/*
1
4
1 2
0
2 1 4
1 2
*/
void solve() {
    int n;
    cin >> n;
    vector<int> v[n];
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 0; j < x; j++) {
            int t; cin >> t;
            v[i].push_back(t);
        }
    }
    cout << "start" << endl;
    unordered_map<int,int> mp;
    queue<int> q;
    int i = 0, res = 0;
    while(1) {
        bool hua = false;
        for(int i = 0; i < n; i++) {
            if(v[i].empty()) {
                q.push(i+1);
                mp[i+1]++;
                hua = true;
            }
            else {
                bool t = false;
                for(int j = 0; j < v[i].size(); j++) {
                    if(mp.find(v[i][j]) == mp.end()) {
                        t = true;
                        break;
                    }
                }
                if(!t){
                    q.push(i+1);
                    mp[i+1]++;
                    hua = true;
                }
            }
            
            res++;
        }
        if(q.size() == n) {
            cout << res << endl;
            return;
        }
        else if(hua == false) {
            cout << "-1" << endl;
            return;
        }
    }
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