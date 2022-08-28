// Link : https://codeforces.com/problemset/problem/1536/A
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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        bool t = false;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x < 0) t = true;
        }
        if(!t) {
            cout << "YES\n101\n";
            for(int i = 100; i >= 0; i--) {
                cout << i << " ";
            }
            cout << endl;
        }
        else cout << "NO" <<endl;
    }
    return 0;
}