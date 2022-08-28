// Link : https://codeforces.com/problemset/problem/1541/A
// Topic :   constructive algorithms    greedy    
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
        v(int) res(n);
        res[0] = n;
        if((n & 1) == 0) {
            for(int i = 2; i <= n; i+= 2){
                cout << i << " " << i-1 << " ";
            }
        }
        else {
            cout << "3 1 2 ";
            for(int i = 5; i <= n; i+= 2){
                cout << i << " " << i-1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}