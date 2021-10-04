#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    double sum = 0;
    double s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sum += s;
    }

    cout << sum << endl;

    return 0;
}