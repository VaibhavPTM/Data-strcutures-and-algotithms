#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ar[1001];
int main()
{
    int n, m, a,b,w;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b>>w;
        ar[a].push_back(make_pair(b , w));
        ar[b].push_back(make_pair(a , w));
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> dis(n+1,INT_MAX);
    pq.push(make_pair(0 , 1));
    dis[1] = 0;
    vector<bool> vis(n+1,false)
    while(!pq.empty()){
        int crr_node = pq.top().second;
        int crr_d = pq.top().first;
        pq.pop();
        if(vis[crr_node] == true) continue; // keep track of outdated nodes
        for(auto edge : ar[crr_node]){
            if(vis[crr_node] == true) continue;
            if(crr_d + edge.second < dis[edge.first]){
                dis[edge.first] = crr_d + edge.second;
                pq.push({dis[edge.first],edge.first});
            }
        }
        vis[crr_node] = true;
    }
    for(int i = 1; i <= n; i++){
        cout<<dis[i]<<" ";
    }
    
    return 0;
}
