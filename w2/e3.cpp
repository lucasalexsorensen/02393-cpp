#include <iostream>
#include <math.h>

using namespace std;

double pi(int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        double term = 1. / (1. + 2 * i);
        if (i % 2 == 0)
        { // even number
            s = s + term;
        }
        else
        {
            s = s - term;
        }
    }
    return 4. * s;
}

int main()
{
    int n;
    cin >> n;

    cout << pi(n) << endl;

    return 0;
}