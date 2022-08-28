// Link : https://cses.fi/problemset/task/1090
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, x;
    cin >> n >> x;
    int ar[n], i = 0, j = n-1;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar,ar+n);
    while(i < j) {
        if(ar[i]+ar[j] <= x) {
            n--;
            i++;
        }
        j--;
    }
    cout << n << endl;
    return 0;
}