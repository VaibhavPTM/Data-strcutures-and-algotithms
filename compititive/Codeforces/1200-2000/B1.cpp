// Link : https://codeforces.com/problemset/problem/1/B
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
#define print(x) for(auto it:x) cout << it << " ";
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
int h(string s) {
    if(s[0] != 'R' || (s[0] == 'R' && !isdigit(s[1]))) return 1;
    int i = 1;
    while(i < s.size() && isdigit(s[i])) i++;
    if(i < s.size() && s[i] == 'C') return 0;
    return 1;
}
int conv1(string s) {
    int r = 0;
    for (const auto& c : s) {
        r *= 26;
        r += c  - 'A' + 1;
    }
    return r;
}
string conv(int n){
	return n == 0 ? "" : conv((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');
}
void solve() {
    string s;
    cin >> s;
    // 1 for exel type, 0 for new type
    int w = h(s);
    string res;
    if(w) {
        int i = 1;
        while(!isdigit(s[i])) i++;
        string t = s.substr(0,i);
        res = 'R' + s.substr(i,s.size()-i) + 'C' + to_string(conv1(t));
        cout << res << endl;
    }
    else {
        int i = 1;
        int digitBeforeC = 0;
        while(s[i] != 'C') {
            if(isdigit(s[i])) digitBeforeC++;
            i++;
        }
        i++;
        res = conv(stoi(s.substr(i,s.size()-i))) + s.substr(1,digitBeforeC);
        cout << res << endl;
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