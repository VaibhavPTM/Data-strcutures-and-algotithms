// Link : https://codeforces.com/problemset/problem/1512/D
// Topic :  constructive algorithms    data structures    greedy    *1200
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
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int n;
    unordered_map<lli,lli> mp;
    cin >> n;
    vector<lli> arr(n+2);
    for(int i = 0; i < n+2; i++){
    	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    lli sum = 0;
    for(int i = 0; i < n; i++) {
    	sum += arr[i];
        mp[arr[i]]++;
	}
    if(sum == arr[n] || sum == arr[n+1]) {
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else {
        lli t = sum - (arr[n+1] - arr[n]);
        if(mp.find(t) == mp.end()) cout << -1 << endl;
        else {
            mp[t]--;
            for(auto & i : mp) {
                for(int j = 0; j < i.second; j++) {
                    cout << i.first << " ";
                }
            }
            cout << arr[n] << endl;
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
