#include <math.h>

#include <iostream>

using namespace std;

int main() {
  int l, n;
  cin >> l;
  cin >> n;

  int m = 0;
  int *dataset = new int(n);
  for (int i = 0; i < n; i++) {
    cin >> dataset[i];
    if (dataset[i] > m) m = dataset[i];
  }

  double k = ceil((double)m / (double)l);

  int *bins = new int(l);
  for (int i = 0; i < n; i++) {
    int index = floor((double)dataset[i] / k);
    // cout << index << ", " << bins[index]++ << endl;
    cout << dataset[i] << endl;
    // bins[index] = 1337;
    // bins[0] = 1337;
  }

  // for (int i = 0; i < l; i++) {
  //   cout << i * k << ": " << bins[i] << endl;
  // }

  return 0;
}
