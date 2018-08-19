#include <iostream>
using namespace std;
class Solution {
 public:
  /*
  Stairs: 1
  (1)
  Stairs: 2
  (1,1) (2)
  Stairs: 3
  1) 1 + 2 : (1,1,1) (1,2)
  2) 2 + 1 : (2,1)
  Stairs: 4
  1) 1 + 3 : (1,1,1,1) (1,1,2) (1,2,1)
  2) 2 + 2 : (2,1,1) (2,2)
  Stairs: 5
  1) 1 + 4 : (1,1,1,1,1) (1,1,1,2) (1,1,2,1) (1,2,1,1) (1,2,2)
  2) 2 + 3 : (2,1,1,1) (2,1,2) (2,2,1)

  1 2 3 5 8
  */
  // if (n == 1)
  //   return 1;
  // else if (n == 2)
  //   return 2;
  // else
  //   return climbStairs(n - 1) + climbStairs(n - 2);
  int climbStairs(int n) {
    int one = 1, two = 2;
    if (n == 1)
      return 1;
    else if (n == 2)
      return 2;
    else {
      for (int i = 3; i <= n; ++i) {
        int two_copy = two;
        two = two + one;
        one = two_copy;
      }
      return two;
    }
  }
};

int main() {
  Solution s;
  cout << s.climbStairs(44) << endl;
  return 0;
}
