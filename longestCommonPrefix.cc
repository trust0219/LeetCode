#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Input: ["flower","flow","flight"]
Output: "fl"

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

flower
flow
flight
*/
class Solution {
 public:
  int shortest_length(vector<string> &strs) {
    int len = strs[0].length();
    for (auto &s : strs) {
      if (len > s.length()) {
        len = s.length();
      }
    }
    return len;
  }

  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    // shortest_len = column_index
    int ci_max = shortest_length(strs);
    string common_prefix = "";
    for (int j = 0; j < ci_max; ++j) {
      bool pass = true;
      for (int i = 1; i < strs.size(); ++i) {
        if (strs[i][j] != strs[i - 1][j]) {
          pass = false;
          break;
        }
      }
      if (pass) {
        common_prefix += strs[0][j];
      } else {
        break;
      }
    }
    return common_prefix;
  }
};

int main() {
  Solution s;
  vector<string> case1 = {"flower", "flow", "flight"};
  cout << s.longestCommonPrefix(case1) << endl;
  case1 = {"dog", "racecar", "car"};
  cout << s.longestCommonPrefix(case1) << endl;
  //
}
