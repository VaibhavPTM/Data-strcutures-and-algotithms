#include<iostream>
#define lli long long int
using namespace std;

lli mulmod(lli a, lli b, lli mod)
{
    lli x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2LL) % mod;
        b /= 2;
    }
    return x % mod;
}
lli binpower(lli a, lli n, lli mod)
{
    lli res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = mulmod(res, a, mod);
        }
        n >>= 1; // this line devide n by 2
        a = mulmod(a, a, mod);
    }
    return res % mod;
}


bool Check_com(lli n, lli a, lli d, int s){
    lli x = binpower(a,d,n);
    if(x == 1 || x == n - 1)
        return false;
    for(int r = 1; r < s; r++){
        x = (lli)x * x % n;
        if(x == n-1)
            return false;
    }
    return true;
} 

bool isPrime(lli n,int iter = 5){
    if(n < 4)
        return n == 2 || n == 3;
    int s = 0;
    lli d = n - 1;
    // here you need to calculate a ^ ((2 ^ s) * d)
    while((d & 1) == 0){
        d >>= 1;
        s++;
    }
    for(int i = 0; i < iter; i++){
        int a = 2 + rand() % (n - 3);
        if(Check_com(n,a,d,s))
        return false;
    }
    return true;
}

int main(){
    lli t, n;
    cin>>t;
    while(t--){
        cin>>n;
        if(isPrime(n))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}