// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/classic-task-39656dbf/
#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>

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
using namespace std;


int find(int n,vi par){
    if(par[n] < 0){
        return n;
    }
    return par[n] = find(par[n],par);
}

int main()
{
    int _min = 100000000;
    int _max = -100000000;
    int n,m;
    cin>>n>>m;
    vi par(n+1,-1);
    while(m--){
        int a,b;
        cin>>a>>b;
        if(_min < a && _max > b) continue;
        for(int i = a,j = b;i < j ;i++,j--){
            int x = find(i,par);
            int y = find(j,par);
            if(x == y) continue;
            else{
                par[x] = y;
                n--;
            }
        }
        if(a < _min && b > _max) _min = a,_max = b;
    }

    cout<<n;
    
    return 0;
}