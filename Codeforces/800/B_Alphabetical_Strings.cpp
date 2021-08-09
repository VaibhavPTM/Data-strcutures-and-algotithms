// Link : https://codeforces.com/problemset/problem/1547/B
// Topic : greedy, implementation, strings
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int> , greater<int> >
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
        string s;
        cin >> s;
        bool flg = false;
        int n = s.size();
        int i = 0, j = 0;
        for(int ii = 0; ii < n; ii++){
            if(s[ii] == 'a') {
                flg = true;
                i = ii-1;
                j = ii+1;
                break;
            }
        }
        char c = 'b';
        for(int ii = 1; ii < n; ii++,c++) {
            if(i >= 0 && s[i] == c) {
                i--;
            }
            else if(j < n && s[j] == c) {
                j++;
            }
            else {
                flg = false;
                break;
            }
        }
        if(flg) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}