#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  /*
  Input: a = "1", b = "1"
  Output: "10"
    1
  + 1
   10

  Input: a = "111", b = "1"
  Output: "1000"

  Input: a = "1", b = "111"
  Output: "1000"

  Input: a = "1010", b = "1011"
  Output: "10101"
  1010
+ 1011

  */
  char bin_add(char a, char b, bool& carry) {
    if (a == '1' && b == '1') {
      if (carry) {
        return '1';
      } else {
        carry = true;
        return '0';
      }
    } else if (a == '1' || b == '1') {
      if (carry) {
        return '0';
      } else {
        return '1';
      }
    } else {  // both 0
      if (carry) {
        carry = false;
        return '1';
      } else {
        return '0';
      }
    }
  }

  string addBinary(string a, string b) {
    if (a == "0")
      return b;
    else if (b == "0")
      return a;
    //
    bool carry = false;
    string small, big;
    if (a.length() < b.length()) {
      small = a;
      big = b;
    } else {
      small = b;
      big = a;
    }
    string retstr;
    int diff = big.size() - small.size();
    for (int i = big.size() - 1; i >= 0; i--) {
      int j = i - diff;
      if (j >= 0) {
        retstr = bin_add(big[i], small[j], carry) + retstr;
      } else {
        retstr = bin_add(big[i], '0', carry) + retstr;
      }
      if (carry && i == 0) {
        retstr = '1' + retstr;
      }
    }
    // 1010
    //    1
    return retstr;
  }
};

int main() {
  Solution s;
  cout << s.addBinary("1", "1") << endl;
  cout << s.addBinary("11", "1") << endl;
  cout << s.addBinary("1", "11") << endl;
  cout << s.addBinary("1010", "1011") << endl;  // Output: "10101"
  cout << s.addBinary("1111", "1") << endl;     // Output: "10101"
  string a = "11001000011101111111010011101001111111110000110101000";
  string b =
      "101011001110001000011010001100110111000111100100101000110000010001111101"
      "1011111";
  cout << s.addBinary(a, b) << endl;
  /*
  Output:
"10001110001110110010110100110010110001111111000011101110110000100010000010000111"
Expected:
 "101011001110001000011010011001011000111111100001110111011000010001000001000011"
  */
  string output = s.addBinary(a, b);
  string expected =
      "101011001110001000011010011001011000111111100001110111011000010001000001"
      "000011";
  if (output == expected) {
    cout << "pass" << endl;
  }
}
