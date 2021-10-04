#include <iostream>

using namespace std;

int main()
{
    int n;

    int counts[1000] = {0};

    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        else if (n > 0 && n <= 1000)
        {
            cout << counts[n - 1] << endl;
            counts[n - 1]++;
        }
        else
        {
            // unspecified
        }
    }

    return 0;
}