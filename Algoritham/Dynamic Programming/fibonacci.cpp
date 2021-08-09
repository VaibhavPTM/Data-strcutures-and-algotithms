#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"

void fibonacci(int n){
    int fib[n+1];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout<<fib[n];
    return;
}
int fect(int n){ return (n == 1 || n == 0)? 1 : n * fect(n-1); }
int main()
{
    int n;
    cin>>n;
    cout<<n<<"! = "<<fect(n);
    return 0;
}