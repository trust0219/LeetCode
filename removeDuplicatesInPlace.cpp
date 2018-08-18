#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  void printlist(vector<int> &nums) {
    std::cout << "myvector contains:";
    for (auto it = nums.begin(); it != nums.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  // remove duplicates for sorted array
  int removeDuplicates(vector<int> &nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
  }
};

int main() {
  Solution s;
  vector<int> case1 = {0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << "answer: " << s.removeDuplicates(case1) << endl;
  //
}
