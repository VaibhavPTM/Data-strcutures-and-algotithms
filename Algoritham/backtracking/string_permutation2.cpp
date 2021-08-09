// number - 1234__ and use any other two number form 1,2,3,4
// make 10,000 permutations
#include<iostream>
#include<set>
#define vi set<string>
using namespace std;
// Backtracking
vi container;
void findPermutations(string str,string ans){
    if(container.size() == 10000)return;
    if(ans.length() == str.length()){
        container.emplace(ans);
    }
    else{
        for (int i = 0; i < str.length(); i++)
        {
            // do 
            ans.push_back(str[i]);
            // recur
            findPermutations(str,ans);
            // undo
            ans.pop_back();
        }
    }
}

int main(){

    int n;
    string str = "1234";
    char c;
    for (char c = '1'; c <= '5'; c++)
    {
        for (char c2 = '1'; c2 <= '5'; c2++)
        {
            if(container.size() == 10000)break;
            string str = "1234";
            str.push_back(c), str.push_back(c2);
            findPermutations(str,"");
        }
    }
    int i = 1;
    for (const auto &e : container)
        cout << e << " ", i++;
    return 0;
}