// Link : https://codeforces.com/problemset/problem/71/A
// Topic : strings
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

int main() {
    int n;
    cin>>n;
    while (n--){
        string i;
        cin>>i;
        if(i.size() < 11) cout<<i<<endl;
        else{
            cout<<i[0] << i.size() - 2 << i[i.size()-1]<<endl;
        }
    }
    
    
    return 0;
}