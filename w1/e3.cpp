#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    string s;
    if (x > y)
    {
        s = "bigger than";
    }
    else if (x < y)
    {
        s = "smaller than";
    }
    else
    {
        s = "equal to";
    }

    cout << x << " is " << s << " " << y;

    return 0;
}