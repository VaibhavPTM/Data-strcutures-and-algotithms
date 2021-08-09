#include <iostream>
using namespace std;
// count the number of 1's in N's Binary Number
int main()
{
    int n;
    cin >> n;
    int count = 0;
    // algorithm 1
    /*
        while (n > 0)
        {
            if ((n & 1) ==1) // cheak the wather bit is set or not
                count++;
            n = n >> 1; // decresing N and when N = 0 the loop is break
        }
    */
    // algorithm 2
    // This will save the time complexity
    while (n > 0)
    {
        count++;
        n = n & (n-1);
    }
    
    cout << "number of 1's is " << count;
    return 0;
}