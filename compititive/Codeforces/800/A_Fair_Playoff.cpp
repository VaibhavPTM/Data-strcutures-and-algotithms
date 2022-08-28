// Link : https://codeforces.com/problemset/problem/1535/A
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
#define MAX 100001

int arr[MAX];

void solve() {
    int p1,p2,p3,p4;
    cin >> p1 >> p2 >> p3 >> p4;
    maxhp(int) mx;
    mx.push(p1);
    mx.push(p2);
    mx.push(p3);
    mx.push(p4);
    int mx1 = mx.top();
    mx.pop();
    int mx2 = mx.top();
    if((mx1 == p1 || mx1 == p2) && (mx2 == p3 || mx2 == p4)) cout << "YES" << endl;
    else if((mx1 == p3 || mx1 == p4) && (mx2 == p1 || mx2 == p2)) cout << "YES" << endl;
    else cout << "NO" << endl;
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