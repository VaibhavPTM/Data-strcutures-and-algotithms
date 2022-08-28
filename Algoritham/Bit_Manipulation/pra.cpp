#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p(int a, int b) {
    if(b == 0) {
        return a;
    }
    return p(++a, b-1);
}

int main(){
    int a, b;
    cin >> a >> b;
    // cout << "\"" << a - (-b) << "\"" << endl;
    // cout << p(a,b) << endl;


    if(!(a ^ b)) {
        cout << "YES" << endl;
    }
    else {
        cout << "No" << endl;
    }
    int x = min(a,b);
    int y = max(a,b);
    cout << "Min number is " << x << endl;
    cout << "Max number is " << y << endl;
    return 0;
}