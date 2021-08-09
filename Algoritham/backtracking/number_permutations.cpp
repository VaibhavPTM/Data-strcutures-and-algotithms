#include<iostream>
#include<vector>
using namespace std;
// Backtracking
void findPermutations(string str,string ans , vector<string>& st){
    if(ans.length() == str.length()){
        st.push_back(ans);
    }
    else{
        for (int i = 0; i < str.length(); i++)
        {
            // do 
            ans.push_back(str[i]);
            // recur
            findPermutations(str,ans,st);
            // undo
            ans.pop_back();
        }
    }
}
void removeAccurance(vector<string>& st){
    int count = 0;
    for (int k = 0; k < st.size(); k++){
        for (int i = 0; i < st[k].length(); i++){
            count = 0;
            for (int j = 0; j < st[k].length(); j++){
                if (j == i)
                    continue;
                if (st[k][i] == st[k][j])
                    count++;
                if (count >= 2)
                    st.erase(st.begin()+k);
            }
        }
    }
}
void printVec(vector<string> st){
    for (int i = 0; i < st.size(); i++)
    {
        cout<<st[i]<<endl;
    }
}
int main(){
    vector<string> st;
    int n;
    string str;
    char c;
    printf("How many elemnts do you want to insert? : ");
    scanf("%d",&n);
    printf("Enter your elements (0 - 9): ");
    for (int i = 0; i < n; i++){
        cin>>c;
        str.push_back(c);
    }
    cout<<"Permutation...."<<endl;
    findPermutations(str,"",st);
    printVec(st);
    removeAccurance(st);
    return 0;
}