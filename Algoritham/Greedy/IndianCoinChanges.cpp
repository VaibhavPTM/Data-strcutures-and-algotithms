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


int findMiCoins(vector<int> v, int num){
    int ans = 0;
    forj(j,v.size()){
        if(!num) break;
        ans += num / v[j];
        num -= num / v[j] * v[j]; // suppose 2001 then 2001 / 2000 = 1, 1*2000 = 2000;
    }
    return ans;
}
int main()
{
    vector<int> v = {2000,1000,500,200,100,50,20,10,5,2,1};
    int t;
    cin>>t;
    while(t--){
        int money;
        cin>>money;
        cout<<"Min Notes "<<findMiCoins(v,money)<<endl;
    }
    return 0;
}