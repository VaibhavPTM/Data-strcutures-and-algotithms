// Name : Sum of power
// Link : https://www.hackerrank.com/challenges/the-power-sum/problem
#include <cmath>
#include <iostream>

using namespace std;

int findPowerSum(int total, int power, int num);
int main() { 
    int total;
    int power;
    cin >> total;
    cin >> power;
    int x =  findPowerSum(total, power, 1);
    cout << x;
    return 0;
}

int findPowerSum(int total, int power, int num)
{
    int value = static_cast<int>(total - pow(num, power));
    
    if(value < 0) return 0;
    else if(value == 0) return 1;

    
    else return findPowerSum(value , power, num + 1) +
    			findPowerSum(total, power, num+1);
}