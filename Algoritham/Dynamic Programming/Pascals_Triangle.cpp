#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, grater<int>>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"
vector<vector<int>> generate(int numRows)
{
    vii res(numRows);
    for (int i = 0; i < numRows; i++){
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for(int j = 1; j < i; j++){
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    return res;
    
}
int main()
{
    int n;
    cin >> n;
    vii res = generate(n);
    for(auto i : res){
        for(auto j : i){
            cout<<j<<" ";
        }
        isalpha
        cout<<endl;
    }
    queue<int> i;
    

    return 0;
}