#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1000001];
bool dis[1000001];
int cc[1000001];
int crru_cnt;


void dfs(int node){
    dis[node] = true;
    cc[node] = crru_cnt;
    for(int child : graph[node])
        if(!dis[child])
            dfs(child);
}

int main()
{
    int t, v, e, a, b;
    string op;
    cin>>t;
    while (t--)
    {
        crru_cnt = 0;
        int i1 = 0;
        vector<pair<int,int>> NotMatchNo;
        cin>>v>>e;
        while (e--)
        {
            cin>>a>>op>>b;
            if(op == "=")
                graph[a].push_back(b),graph[b].push_back(a);
            else
                NotMatchNo.push_back({a,b}),i1++;
        }

        for(int i = 1; i <= v; i++)
            if(!dis[i]){
                crru_cnt++;
                dfs(i);
            }
        bool flage = true;
        for (int i = 0; i < i1; i++)
        {
            a = NotMatchNo[i].first;
            b = NotMatchNo[i].second;
            if(cc[a] == cc[b]){
                flage = false;
                break;
            }
        }
        (flage) ? cout << "YES\n" : cout << "NO\n" ;
        if(t == 1){
            continue;
        }
        for(int i = 1; i <= v; i++)
            graph[i].clear(),dis[i] = false;
    }
    return 0;
}