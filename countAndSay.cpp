#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  void printvec(vector<int> &v) {
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  /*
  1.     1
  2.     11
  3.     21
  4.     1211
  5.     111221
  */

  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    //
    vector<int> retstr = {1};
    int tracker_n = 1;
    while (tracker_n < n) {
      vector<int> new_retstr;
      int curr_num = retstr[0];
      int count = 0;
      for (int i = 0; i < retstr.size(); ++i) {
#ifdef DEBUG
        cout << "retstr[i]: " << retstr[i] << endl;
        cout << "retstr.size(): " << retstr.size() << endl;
#endif
        if (curr_num == retstr[i]) {
          count++;
#ifdef DEBUG
          cout << "count: " << count << endl;
#endif
          if (i == retstr.size() - 1) {
            new_retstr.emplace_back(count);
            new_retstr.emplace_back(curr_num);
            break;
          }
        } else {
          new_retstr.emplace_back(count);
          new_retstr.emplace_back(curr_num);
          curr_num = retstr[i];
          count = 1;
          if (i == retstr.size() - 1) {
            new_retstr.emplace_back(count);
            new_retstr.emplace_back(curr_num);
            break;
          }
        }
      }
#ifdef DEBUG
      cout << "new_retstr: ";
      printvec(new_retstr);
#endif
      retstr.swap(new_retstr);
      tracker_n++;
    }
    string s;
    for (auto num : retstr) {
      s += to_string(num);
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.countAndSay(1) << endl;
  cout << s.countAndSay(2) << endl;
  cout << s.countAndSay(3) << endl;
  cout << s.countAndSay(4) << endl;
  cout << s.countAndSay(5) << endl;
}
