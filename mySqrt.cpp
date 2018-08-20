#include <iostream>
using namespace std;
class Solution {
public:
  /*
  Input: 4
 Output: 2

 Input: 8
 Output: 2
 Explanation: The square root of 8 is 2.82842..., and since
              the decimal part is truncated, 2 is returned.
  */
  int mySqrt(int x) {
    if (x <= INT_MAX && x >= 2147395600) {
      return 46340;
    }
    int retval = 1;
    int sqr = retval * retval;
    while (sqr <= x) {
      if (sqr == x) {
        return retval;
      }
      retval++;
      sqr = retval * retval;
    }
    return retval - 1;
  }
};

int main() {
  Solution s;
  cout << INT_MAX << endl;
  cout << s.mySqrt(INT_MAX) << endl;
  // for (int n = 0; n <= 10; n++) {
  //   printf("sqrt(%d): %d\n", n, s.mySqrt(n));
  // }
}
