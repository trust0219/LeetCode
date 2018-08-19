#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  int strStr(string haystack, string needle) {
    //
    size_t found = haystack.find(needle);
    return static_cast<int>(found);
  }
};

int main() {
  Solution s;
  cout << s.strStr("hello", "ll") << endl;
  cout << s.strStr("aaaaa", "bba") << endl;
  //
}
