// Link : https://atcoder.jp/contests/abc210
// Topic : 
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int> , grater<int> >
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"

int main(){
    int n;
    string s;
    cin>>n>>s;
    bool t = true;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(t) cout<<"Takahashi";
            else cout<<"Aoki";
            break;
        }
        t = !t;
    }
    return 0;
}