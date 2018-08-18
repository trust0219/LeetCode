#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool notLastIndex(int i, string s) { return i < s.length() - 1; }
  int roman_to_num(int &i, string s) {
    if (notLastIndex(i, s) && s[i] == 'I' && s[i + 1] == 'V') {
      i++;
      return 4;
    } else if (notLastIndex(i, s) && s[i] == 'I' && s[i + 1] == 'X') {
      i++;
      return 9;
    } else if (notLastIndex(i, s) && s[i] == 'X' && s[i + 1] == 'L') {
      i++;
      return 40;
    } else if (notLastIndex(i, s) && s[i] == 'X' && s[i + 1] == 'C') {
      i++;
      return 90;
    } else if (notLastIndex(i, s) && s[i] == 'C' && s[i + 1] == 'D') {
      i++;
      return 400;
    } else if (notLastIndex(i, s) && s[i] == 'C' && s[i + 1] == 'M') {
      i++;
      return 900;
    } else if (s[i] == 'I') {
      return 1;
    } else if (s[i] == 'V') {
      return 5;
    } else if (s[i] == 'X') {
      return 10;
    } else if (s[i] == 'L') {
      return 50;
    } else if (s[i] == 'C') {
      return 100;
    } else if (s[i] == 'D') {
      return 500;
    } else if (s[i] == 'M') {
      return 1000;
    } else {
      cout << "ERROR: Wrong input" << endl;
      return 0;
    }
  }
  //
  int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
      sum += roman_to_num(i, s);
      cout << "i: " << i << endl;
    }
    return sum;
  }
};
int main() {
  Solution s;
  vector<string> testCases = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
  for (auto &casestr : testCases) {
    cout << s.romanToInt(casestr) << endl;
  }
  return 0;
}
