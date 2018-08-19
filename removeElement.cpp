#include <iostream>
#include <vector>
using namespace std;
/*
Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums
containing 0, 1, 3, 0, and 4
*/
class Solution {
 public:
  int removeElement(vector<int> &nums, int val) {
    int i = 0;
    while (i < nums.size()) {
      if (nums.at(i) == val) {
        nums.erase(nums.begin() + i);
      } else {
        i++;
      }
    }
    return nums.size();
    //
  }
};

int main() {
  Solution s;
  vector<int> case1 = {3, 2, 2, 3};
  cout << "answer: " << s.removeElement(case1, 3) << endl;
  case1 = {0, 1, 2, 2, 3, 0, 4, 2};
  cout << "answer: " << s.removeElement(case1, 2) << endl;
}
