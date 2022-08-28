// Link : https://codeforces.com/problemset/problem/1525/B
// Topic :  constructive algorithms    greedy    *900
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
#define MAX 100001


void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if(is_sorted(arr, arr+n)){
        cout << 0 << endl;
    }
    else if(arr[0] == 1 || arr[n-1] == n){
        cout << 1 << endl;
    }
    else if(arr[0] == n && arr[n-1] == 1) {
        cout << 3 << endl;
    }
    else 
        cout << 2 << endl;
    
    
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