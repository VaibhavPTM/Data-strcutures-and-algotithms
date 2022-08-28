// Link : https://codeforces.com/problemset/problem/1557/A
// Topic :    brute force    math    sortings    *800
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

double arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        double n;
        cin >> n;
        double sum = 0;
        double mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
            sum += arr[i];
        }
        sum -= mx;
        double res = mx + (sum / (n-1.0));
        printf("%f\n",res);
        // cout << sum << " " << n-1 << endl;
    }
    return 0;
}