#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    const int sum = 1000;
    int a;
    lli res = 1;
    for (a = 1; a <= sum/3; a++)
    {
        int b;
        for (b = a + 1; b <= sum/2; b++)
        {
            int c = sum - a - b;
            if ( a*a + b*b == c*c ){
               cout << a << ' ' << b << ' ' << c << endl;
                res = a * b * c;
            }
        }
    }
    cout << res << ' ';
    
    return 0;
}