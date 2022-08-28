#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n = 2000000;
    ll sum = 0;
    vector<int> primes(n+1, 1);
    primes[0] = primes[1] = 0;
    for(int i = 2; i * i <= n; i++) {
        if(primes[i]) {
            for(int j = i*2; j <= n; j+=i) {
                primes[j] = 0;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(primes[i]) sum += i;
    }
    cout << sum << endl;
    


    return 0;
}