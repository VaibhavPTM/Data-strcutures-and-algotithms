#include<iostream>
#include<vector>
#include<array>
#define iil long long int
#define vi vector<int>
using namespace std;

vi graph[10001];
bool dis[10001];
int count[10001];

// This function will return sunsize of rootnode
int dfs(int root){
    dis[root] = true;
    int crr_size = 1;
    for(int child : graph[root]){
        if(!dis[child]){
            crr_size += dfs(child);  // This will give us the size of childerns and add them to main root
        }
    }
    count[root] = crr_size;
    return crr_size;
}

int main()
{
    int v, e, s, r;
    cin>>v;
    e = v - 1;
    while (e--)
    {
        cin>>s>>r;
        graph[s].push_back(r);
        graph[r].push_back(s);
    }
    dfs(4); // Give root node as a argument
    for (int i = 1; i <= v; i++)
    {
        cout<<"Size of subtree " << i << " is "<<count[i]<<endl;
    }
    

    return 0;
}