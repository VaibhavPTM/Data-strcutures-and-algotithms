// Link : https://atcoder.jp/contests/abc215/tasks/abc215_b
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl "\n"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli n;
    cin >> n;
    lli i = 0;
    while(n) {
        n /= 2;
        i++;
    }
    cout << --i << endl;
    return 0;
}