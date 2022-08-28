// Link : https://cses.fi/problemset/task/1622
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
set<string> s;

void permut(string str, int l, int r) {
    if(l == r) {
        s.insert(str);
    }
    for(int i = l; i <= r; i++) {
        swap(str[l],str[i]);
        permut(str,l+1,r);
        swap(str[l],str[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string str;
    cin >> str;
    permut(str,0,str.size()-1);
    cout << s.size() << endl;
    for(auto &i : s) {
        cout << i << endl;
    }
    return 0;
}