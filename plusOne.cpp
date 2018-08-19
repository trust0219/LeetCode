#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void printList(vector<int> &list_num) {
    for (auto &n : list_num) {
      cout << n;
    }
    cout << endl;
  }
  vector<int> plusOne(vector<int> &digits) {
    digits[digits.size() - 1] += 1;
    // printList(digits);
    vector<int> retvec;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] >= 10) {
        if (i == 0) {
          digits[i] = digits[i] % 10;
          digits.insert(digits.begin(), 1);
          break;
        } else {
          digits[i] = digits[i] % 10;
          digits[i - 1] += 1;
        }
      }
    }
    for (auto &n : digits) {
      retvec.emplace_back(n);
    }
    // printList(retvec);
    return retvec;
  }
};

int main() {
  //
  Solution s;
  vector<int> case1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  s.plusOne(case1);
}
