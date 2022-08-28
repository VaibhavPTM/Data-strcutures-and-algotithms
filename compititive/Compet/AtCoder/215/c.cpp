#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<string> s;
void swap(string &str, int left, int right){
    if(left == right){
        return;
    }
    char t;
    t = str[left];
    str[left] = str[right];
    str[right] = t;
}
void findPermutations(string str, int left, int right, int k){
    // if(s.size() == k) return;
    if(left == right){
        // cout<<str<<" ";
        s.insert(str);
    }
    else{
        for (int i = left; i <= right; i++){
            // do
            swap(str , left , i);
            // recure
            findPermutations(str,left + 1,right,k);
            // undo
            swap(str , left , i);
        }
    }
}
int main(){
    string str;
    int k;
    cin >>str >> k;
    sort(str.begin(),str.end());
    findPermutations(str,0,str.length()-1,k);
    auto it = s.begin();
    while (--k) {
        it++;
        if(it == s.end()) break;
    }
    
    cout << *it << endl;
    return 0;
}