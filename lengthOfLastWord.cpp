#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  /*
  Input: "Hello World"
  Output: 5
  */
  int lengthOfLastWord(string s) {
    int word_len = 0;
    bool found_space = false;
    for (int i = 0; i < s.length(); i++) {
      if (!found_space) {
        if (s[i] != ' ')
          word_len++;
        else
          found_space = true;
      } else {
        if (s[i] != ' ') {
          word_len = 1;
          found_space = false;
        }
      }
    }
    return word_len;
  }
};

class Solution2 {
public:
  int lengthOfLastWord(string s) {
    int len = 0, tail = s.length() - 1;
    while (tail >= 0 && s[tail] == ' ')
      tail--;
    while (tail >= 0 && s[tail] != ' ') {
      len++;
      tail--;
    }
    return len;
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLastWord("HelloWorld") << endl;
  cout << s.lengthOfLastWord("HelloWorld   ") << endl;
  cout << s.lengthOfLastWord("HelloWorld   AA") << endl;
  cout << s.lengthOfLastWord("Hello World") << endl;
  cout << s.lengthOfLastWord("Hello World ") << endl;
  cout << s.lengthOfLastWord("Hello World Lala") << endl;
  cout << s.lengthOfLastWord("        ") << endl;
  //
}
