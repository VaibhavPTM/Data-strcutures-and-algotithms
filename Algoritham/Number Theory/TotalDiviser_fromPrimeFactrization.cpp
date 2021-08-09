#include <iostream>
#include<vector>
using namespace std;
vector <int> PowerFact;
void findPowerOfPrimeFact(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if(n % i == 0){
            int count = 0;
            while(n % i == 0){
                count++;
                n /= i;
            }
            PowerFact.push_back(count);
        }
    }
    if(n > 1){
        PowerFact.push_back(1);
    }
}
int main()
{
    int n;
    cin >> n;
    findPowerOfPrimeFact(n);
    int answer = 1;
    for (int i = 0; i < PowerFact.size(); i++)
    {
        answer = answer * (PowerFact[i] + 1);
    }
    cout<<"The Total diviser of number is : "<<answer;
    return 0;
}