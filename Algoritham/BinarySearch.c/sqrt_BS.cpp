#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter your number : ";
    cin >> num;
    int start = 0;
    int end = num;
    int result;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid * mid == num)
        {
            result = mid;
            break;
        }
        else if ((mid * mid) > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            result = mid;
        }
    }
    cout<<endl<<"Your squar root is : "<<result;
    return 0;
}