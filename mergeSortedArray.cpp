#include <iostream>
#include <vector>
using namespace std;

/*
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
nums1 , nums2

1,2,2,3,0

*/

class Solution {
public:
  /*
     The number of elements initialized in nums1 and nums2 are m and n
 respectively. You may assume that nums1 has enough space (size that is greater
 or equal to m + n) to hold additional elements from nums2.
     */
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = 0, j = 0;
    while (j < n) {
      if (i == m) {
        while (j < n) {
          nums1[i] = nums2[j];
          i++;
          j++;
        }
        break;
      }
      if (nums1[i] > nums2[j]) {
        nums1.insert(nums1.begin() + i, nums2[j]);
        nums1.pop_back();
        i++;
        j++;
        m++;
      } else {
        i++;
      }
    }

    //
  }
  void printnl(vector<int> &nl) {
    for (auto &n : nl) {
      cout << n << " ";
    }
    cout << endl;
  }
};

int main() {
  Solution s;
  vector<int> l1 = {1, 2, 3, 0, 0, 0}, l2 = {2, 5, 6};
  s.merge(l1, 3, l2, 3);
  s.printnl(l1);

  //
}
