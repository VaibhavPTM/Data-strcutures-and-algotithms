// Link : 
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
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        bool flg = true;
        v(int) irs;
        v(int) drs;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]) continue;
            else {
                if(a[i] > b[i]) {
                    int r = a[i] - b[i];
                    while(r--) irs.push_back(i+1);
                }
                else if(b[i] > a[i]) {
                    int r = b[i] - a[i];
                    while(r--) drs.push_back(i+1);
                }
                flg = false;
            }
        }
        if(irs.size() != drs.size()) cout << -1 << endl;
        else if(flg) cout << 0 << endl;
        else {
            cout << drs.size() << endl;
            for(int i = 0; i < drs.size(); i++) {
                cout << irs[i] << " " << drs[i] << endl;
            }
        }
    }
    return 0;
}