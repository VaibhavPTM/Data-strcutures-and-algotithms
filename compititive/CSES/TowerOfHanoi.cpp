// Link : https://cses.fi/problemset/task/2165
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
void solve(int n, int s, int d, int h) {
    if(n == 1) {
        cout << s << " " << d << endl;
        return;
    }
    solve(n-1,s,h,d);
    cout << s << " " << d << endl;
    solve(n-1,h,d,s);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(n, 1, 3, 2);
    
    return 0;
}