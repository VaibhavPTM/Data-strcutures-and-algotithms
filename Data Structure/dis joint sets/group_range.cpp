// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/group-range-a6693ae2/

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
#define Max 2*100005
#define endl "\n"
using namespace std;

int par[Max];
int size2[Max];
int _min[Max];
int _max[Max];
int arr[Max];

int find(int n){
    if(par[n] == n) return n;
    return par[n] = find(par[n]);
}
void mearg(int a, int b){
    int x = find(a);
    int y = find(b);
    if(size2[x] < size2[y]){
        par[x] = par[y];
        size2[y] += size2[x];
        _max[y] = max(_max[x],_max[y]);
        _min[y] = min(_min[x],_min[y]);
    }else{
        par[y] = par[x];
        size2[x] += size2[y];
        _max[x] = max(_max[x],_max[y]);
        _min[x] = min(_min[x],_min[y]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        par[i] = i;
        size2[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        _min[i] = arr[i];
        _max[i] = arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        // a = find(a);
        // b = find(b);
        if(find(a) == find(b)){
            cout<<_min[a]<<" "<<_max[b]<<endl;
        }
        else{
            mearg(a,b);
            cout<<_min[find(a)]<<" "<<_max[find(a)]<<endl;  
        }

    }
    return 0;
}