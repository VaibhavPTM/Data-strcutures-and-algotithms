// Link : https://codeforces.com/problemset/problem/1526/A
// Topic :  constructive algorithms    sortings    *800
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T>>
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
    cin >> n;
    n *= 2;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0; i < n / 2; i++) {
        if(i != n - i - 1) {
            cout << arr[n-i-1] << " "<< arr[i] << " ";
        }
        else cout << arr[i];
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