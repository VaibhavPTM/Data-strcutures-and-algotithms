// Link : https://codeforces.com/problemset/problem/1538/B
// Topic : math
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
#define MAX 100001 * 2

int arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum +=arr[i];
        }
        if((sum % n) != 0) cout << -1 << endl;
        else {
            int ave = sum / n;
            int res = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] > ave) res++;
            }
            cout << res << endl;
        }
    }
    return 0;
}