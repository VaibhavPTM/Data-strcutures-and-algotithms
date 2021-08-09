// this problem is from codechef
#include<iostream>
#include<map>
#define lli long long int
using namespace std;
lli total;
map<lli,lli> pf;
void factorize(lli n){
    total = 1;
    for (lli i = 2; i * i <= n; i++)
    {
        if(n % i == 0){
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            pf[i] = count;
            total *= (count + 1);
        }
    }
    if(n > 1)
    pf[n] = 1, total *= 2;
}
int main()
{
    lli t, n , q , k;
    cin>>n>>q;
    factorize(n); 
    while (q--)
    {
        cin>>t>>k;
        if(t == 1){
            lli res = 1;
            for(pair<lli,lli> p : pf){
                lli count = 0;
                while(k % p.first == 0)
                count++,k/= p.first;
                res *= min(count , p.second) + 1;
            }
            cout<<res<<endl;
        }
        else if(t == 2){
            lli res = 1;
            for(pair<lli, lli> p : pf){
                lli count = 0;
                while(k % p.first == 0){
                    count++;
                    k /= p.first;
                }
                if(count > p.second){
                    res = 0;
                    break;
                }
                res *= (p.second - count + 1);
            }
            if(k > 1)
            res = 0;
            cout<<res<<endl;
        }
        else{
            lli res = 1;
            for(pair<lli, lli> p : pf){
                lli count = 0;
                while(k % p.first == 0){
                    count++;
                    k /= p.first;
                }
                if(count > p.second){
                    res = 0;
                    break;
                }
                res *= (p.second - count + 1);
            }
            if(k > 1)
            res = 0;
            cout<<total - res<<endl;
        }
    }
    
    return 0;
}