#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 2;
    while (n >= i * i)
    {
        if (n % i == 0)
        {
            cout << i << " * ";
            n = n / i;
        }
        else
        {
            i++;
        }
    }
    cout << n << endl;

    return 0;
}