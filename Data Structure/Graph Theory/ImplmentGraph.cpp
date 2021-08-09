#include<iostream>
#include<vector>
using namespace std;
int vertex;
int edge;
void impl_graph(vector<int> graph[]){
    
    while (edge--)
    {
        int source, root;
        cin>>source>>root;
        graph[source].push_back(root);
        graph[root].push_back(source);
    }
}

void  print_graph(vector<int> graph[]){
    for (int i = 0; i <= vertex; i++)
    {
        
        cout<<i<<"-->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout<<graph[i][j]<<", ";
        }
        cout<<endl;
    }
}
void dfs(vector<int> graph[], vector<bool>& discoverd, int v){
    discoverd[v] = true;
    cout<<v<<"--->";
    for (int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];
        if (!discoverd[child])
        {
            dfs(graph,discoverd,child);
        }
    }
    
}
int main()
{
    
    cin>>vertex>>edge;
    vector<int> graph[vertex + 1];
    vector<bool> discover(vertex + 1);
    impl_graph(graph);
    print_graph(graph);
    for (int i = 0; i <= vertex; i++)
    {
        if(!discover[i])
        dfs(graph,discover,i);
    }
    return 0;
}