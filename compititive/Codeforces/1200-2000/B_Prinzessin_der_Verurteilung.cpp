// Link : https://codeforces.com/problemset/problem/1536/B
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
string conv(int n){
	return n == 0 ? "" : conv((n - 1) / 26) + (char) ((n - 1) % 26 + 'a');
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a;
        cin >> n >> a;
        for(int i = 0; ; i++) {
            if(a.find(conv(i)) == -1) {
                cout << conv(i) << endl;
                break;
            }
        }
    }
    return 0;
}