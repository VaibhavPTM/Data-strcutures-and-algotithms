// Name : Social Networking Graph
// Link : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
// Using bfs

#include<iostream>
#include<vector>
#include<queue>

#define iil long long int
using namespace std;
vector<int> ar[1000001];
bool dis[1000001];
int count[1000001];

void bfs(int node){
    dis[node] = true;
    count[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int crr_node = q.front();
        q.pop();
        for(int child : ar[crr_node]){
            if(!dis[child]){
                dis[child] = true;
                q.push(child);
                count[child] = count[crr_node] + 1;
            }
        }
    }
}

int main()
{
    int t,v,e,a,b,t1,t2;
    cin>>v>>e;
    while (e--)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    cin>>t;
    while (t--)
    {
        cin>>t1>>t2;
        for(int i = 0; i <=v ;i++) dis[i] = false,count[i] = 0;
        bfs(t1);
        int ans = 0;
        for(int i = 0; i <= v ; i++){
            if(count[i] == t2)
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
