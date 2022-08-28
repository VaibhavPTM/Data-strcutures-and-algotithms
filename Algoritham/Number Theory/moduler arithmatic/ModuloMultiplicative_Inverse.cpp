/*There are tow ways to find modulo multiplicative inverse efficiently
1. Using Fermat's littele theorem
2. Using Extened Euclidean Algorithem
here is code of Fermat's littele theorem
*/
#include<iostream>
using namespace std;
int power(int a, int n,int mod){
    int res = 1;
    while (n > 0) {
        if(n % 2){
            res = (res * a) % mod;
            n--;
        }
        else{
            a = (a * a) % mod;
            n /= 2;
        }
    }
    return res;
}
int main() {
    int t,num1,num2,mod,modulo_invrse;
    cin >> t;
    while (t--) {
        cout<<"Enter number 1, number 2 and modulo : ";
        cin>>num1>>num2>>mod;
        modulo_invrse = power(num2 , mod - 2,mod);
        // The way to find (num1 / num2) % n using modulo exponatitioantion
        // answer = ((num1 % n) * ((num2^-1) % n)) % n
        int answer = ((num1 % mod) * (modulo_invrse % mod)) % mod;
        cout<<"num1 / num 2 = "<<answer;
    }
    return 0;
}