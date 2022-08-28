#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define ll long long int
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define endl "\n"

int res = 0;

void dfs(int n, int i, int j) {
    if(i == n && j == n) {
        // cout << "yes" << endl;
        res++;
        return;
    }
    // cout << i << " " << j << endl;
    if(i+1 <= n) dfs(n, i+1, j);
    if(j+1 <= n) dfs(n, i, j+1);
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n = 21;
    // dfs(n, 1, 1);
    int1024_t f = 1, f2 = 1;
    for(int i = 2; i <= n * 2; i++) 
    {
        f *= i;
    }
    for(int i = 2; i <= n; i++) {
        f2 *= i;
    }
    cout << f << " " << f2 << endl;
    f /= f2;
    f /= f2;
    cout << f << endl;

    return 0;
}
/*
1 - 2 
2 - 6 - 2 * 4 - 2
3 - 20 - 6 * 4 - 4
4 - 70 - 20 * 4 - 10
5 - 252 - 70 * 4 - 28
6 - 924
7 - 3432
8 - 12870
9 - 48620
10 - 184756

20 = 137846528820
21 - 538257874440

// Method - 1
F(n) = (2n!) / (n!) ^ 2

// Method - 2;
void solve() {
    int n = 21;
    int ar[n][n] = {};
    for(int i = 0; i < n; i++) {
        ar[0][i] = 1;
        ar[i][0] = 1;
    }
    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j <= n-1; j++) {
            ar[i][j] = ar[i-1][j] + ar[i][j-1];
        }
    }
    cout << ar[n-1][n-1] << " ";
}
*/