// Name : PPATH - Prime Path
// Link : https://www.spoj.com/problems/PPATH/


#include<iostream>
#include<vector>
#include<queue>
#define iil long long int
#define vi vector<int>
using namespace std;

vi graph[100001];
vi primes;
bool dis[100001];
int count[100001];

bool isValid(int a, int b){
    int cnt = 0;
    while (a > 0)
    {
        if((a % 10) != (b % 10)) cnt++;

        a /= 10; b /= 10;
    }
    if(cnt == 1)
        return true;
    else{
        return false;
    }
    
}
bool isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void bfs(int node){
    queue<int> q;
    dis[node] = true;
    count[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int crr_node = q.front();
        q.pop();
        for(int i : graph[crr_node]){
            if(!dis[i]){
                q.push(i);
                count[i] = count[crr_node] + 1;
                dis[i] = true;
            }
        }   
    }
}

void bildeGraph(){
    for(int i = 1000; i <= 9999; i++){
        if(isPrime(i))
            primes.push_back(i);
    }
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            int a = primes[i];
            int b = primes[j];

            if(isValid(a,b)){
            graph[a].push_back(b);
            graph[b].push_back(a);
            }
        }   
    }
}

int main()
{
    int t, a, b;
    cin>>t;
    bildeGraph();
    while (t--)
    {
        cin>>a>>b;

        for (int i = 1000; i <= 9999; i++)
        {
            count[i] = -1;
            dis[i] = false;
        }
        bfs(a);

        if(count[b] == -1){
            cout<<"Impossible\n";
        }
        else{
            cout<<count[b]<<"\n";
        }
    }
    return 0;
}