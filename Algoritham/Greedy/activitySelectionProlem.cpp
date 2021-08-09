#include<bits/stdc++.h>
using namespace std;
//static int fastio = [](){
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(0);
//    return 0;
//}();

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

int chooseActivity(vector<vector<int> > &v){
    int activity = 1;
    int end = v[0][1]; // minimum end time
    for(int i = 1; i < v.size(); i++){
        if(v[i][0] >= end){
            activity++;
            end = v[i][1];
        }
    }
    return activity;
}
int main()
{
    int n; // number of activity
    vector<vector<int> > v; // all activitys
    cin>>n;
    
    while(n--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});   
    }
    sort(v.begin(), v.end(), [&](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });
    cout<<chooseActivity(v);
    
    return 0;
}
