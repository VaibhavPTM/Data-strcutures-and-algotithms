// The proble is from SPOJ and the name of this problme is Prime generator 
// This is the practice problem for segment sieve
#include<iostream>
#include<vector>
using namespace std;

vector <int> primes;
int prime[100001];


void sieve(int maxN){
    vector <int> arr(maxN+1,0);
    arr[1] = 1;
    for (int i = 2; i <= maxN; i++)
    {
        if(arr[i] == 0){ // 0 means prime and 1 means composite
            for (int j = 2 * i; j <= maxN; j+=i)
            {
                arr[j] = 1;
            }
        }
    }
    for (int i = 1; i <= maxN; i++)
    {
        if(arr[i] == 0)
        primes.push_back(i);
    }
    
}
void init(int l , int r){
    if(l == 1){
        l++;
    }
    int maxn = r - l + 1;
    vector <int> arr(maxn , 0);
    for (long long int p : primes)
    {
        if(p*p <= r){
            int i = (l / p) * p;
            if(i < l)
            i += p;

            for(;i <= r; i += p){
                if(i != p)
                arr[i - l] = 1;
            }
        }
        // else break;
    }
    for (int i = 0; i < maxn; i++)
    {
        if(arr[i] == 0)
        cout<<l + i<<endl;
    }
}
int main()
{
    sieve(100000);
    int t,l,r;
    cin>>t;
    while(t--){
        cin >> l >> r;
        init(l , r);
        cout<<endl;
    }
    return 0;
}