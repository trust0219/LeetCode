#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    //
    int retval = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (target <= nums[i]) {
        retval = i;
        break;
      } else if (i == nums.size() - 1) {
        retval = i + 1;
        break;
      }
    }
    return retval;
  }
};

int main() {
  Solution s;
  vector<int> case1 = {1, 3, 5, 6};
  cout << s.searchInsert(case1, 5) << endl;
  cout << s.searchInsert(case1, 2) << endl;
  cout << s.searchInsert(case1, 7) << endl;
  cout << s.searchInsert(case1, 0) << endl;
  //
}
