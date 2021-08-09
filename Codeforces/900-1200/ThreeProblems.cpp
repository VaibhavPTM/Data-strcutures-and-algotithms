// Link : https://codeforces.com/problemset/problem/1211/A?csrf_token=4f2f949ad70832f3ddbf7bb33871c4eb (1000)
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
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"

int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >  pq;
    int arr[n+1];
    for (int i = 1; i <= n; i++){
        cin>>arr[i];
        if(mp.size() < 3 && mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = 1;
            pq.push({arr[i],i});
        }
    }
    if(mp.size() == 3){
        while (!pq.empty())
        {
            cout<<pq.top().second<<" ";
            pq.pop();
        }
    }
    else{
        cout<<-1<<" "<<-1<<" "<<-1;
    }
    return 0;
}