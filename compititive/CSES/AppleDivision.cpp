// Link : https://cses.fi/problemset/task/1623
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    lli ar[n];
    for(lli &i : ar) {
        cin >> i;
    }
    lli diff = INT_MAX;
    // 1 << n - size of power set
    for(int i = 0; i < 1 << n ; i++) {
        lli sum1 = 0, sum2 = 0;

        for(int j = 0; j < n; j++) {
            // (i & 1<<j) chack that jth bit in i is set or not ans get the value of setbits in one set ans other int second set 
            if(i & 1<<j) {
                sum1 += ar[j];
            }
            else sum2 += ar[j];
        }
        diff = min(diff,abs(sum1-sum2));
    }
    cout << diff;
    
    return 0;
}