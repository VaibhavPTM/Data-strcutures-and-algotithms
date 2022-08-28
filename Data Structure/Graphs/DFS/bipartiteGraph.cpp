#include<iostream>
#include<vector>
#define max 90000
using namespace std;

vector<int> graph[max];
bool discover[max];
int color[max];

// 0 - red;
// 1 - green
bool DFS(int v, int c){
    discover[v] = true;
    color[v] = c;
    for(int i : graph[v]){
        if (!discover[i])
        {
            if (DFS(i,c ^ 1) == false)
            {
                return false;
            }
        }
        else if(color[i] == color[v]){
            return false;
        }
    }
    return true;
}
int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    int source,root;
    while (edge--)
    {
        cin>>source>>root;
        graph[source].push_back(root);
        graph[root].push_back(source);
    }
    if(DFS(1,0)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }    
    return 0;
}