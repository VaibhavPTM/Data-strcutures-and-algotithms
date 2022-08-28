// Link : https://codeforces.com/problemset/problem/1494/A
// Topic :  bitmasks    brute force    implementation    *900
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
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for(char &x : s) {
        if(x == 'A') a++;
        else if (x == 'B') b++; 
        else if(x == 'C') c++;
    }
    unordered_map<char,char> mp;
    vector<pair<int,char>> t = {{a,'A'},{b,'B'},{c,'C'}};
    sort(t.begin(),t.end());
    if(t[2].first != t[0].first + t[1].first) cout << "NO" << endl;
    else {
        if(s[0] == t[2].second) {
            mp[t[2].second] = '(';
            mp[t[0].second] = mp[t[1].second] = ')';
        }
        else {
            mp[t[2].second] = ')';
            mp[t[0].second] = mp[t[1].second] = '(';
        }
        stack<int> st;
        st.push(mp[s[0]]);
        for(int i = 1; i < s.size(); i++) {
            if(mp[s[i]] == ')') {
                if(st.empty()) {
                    cout << "NO" << endl;
                    return;
                }
                else st.pop();
            }
            else st.push('(');
        }
        cout << (st.empty() ? "YES" : "NO") << endl;
    }
    return;
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