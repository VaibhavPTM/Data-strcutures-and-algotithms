#include<iostream>
using namespace std;

char arr[1000];
string s;

void bitStr(int n){
    if(n < 1){
        cout<<s<<" ";
    }
    else{
        // arr[n-1] = '0';
        s.push_back('0');
        bitStr(n-1);
        s.pop_back();
        s.push_back('1');
        // arr[n-1] = '1';
        bitStr(n-1);
        s.pop_back();
    }
}

int main(){
    bitStr(3);
    return 0;
}