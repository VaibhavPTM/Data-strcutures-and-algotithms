#include<iostream>
using namespace std;
string swap(string str, int left, int right){
    if(left == right){
        return str;
    }
    char t;
    t = str[left];
    str[left] = str[right];
    str[right] = t;
    return str;
}
void findPermutations(string str, int left, int right){
    if(left == right){
        cout<<str<<" ";
    }
    else{
        for (int i = left; i <= right; i++){
            // do
            str = swap(str , left , i);
            // recure
            findPermutations(str,left + 1,right);
            // undo
            str = swap(str , left , i);
        }
    }
}
int main(){
    string str;
    cin>>str;
    cout<<"Permutation...."<<endl;
    findPermutations(str,0,str.length()-1);
    return 0;
}