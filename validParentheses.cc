#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Input: "()[]{}"
Output: true

Input: "{[]}()"
Output: true

Input: "([)]"
Output: false
*/
class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;

    for (char& c : s) {
      if (c == '(' || c == '{' || c == '[')
        st.push(c);
      else if (st.empty())
        return false;
      else if ((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') ||
               (c == ']' && st.top() == '['))
        st.pop();
      else
        return false;
    }
    return st.empty();
  }
};

int main() {
  Solution s;
  // cout << boolalpha << s.isValid("()[]{}") << endl;
  //"{[]}"
  // cout << boolalpha << s.isValid("{[]}") << endl;
  // "[([]])"
  // cout << boolalpha << s.isValid("[([]])") << endl;
  // "[({(())}[()])]"
  cout << boolalpha << s.isValid("[({(())}[()])]") << endl;

  return 0;
}
