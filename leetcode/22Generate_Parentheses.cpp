/*!
* \Problem     LeetCode 22: Generate Parentheses
* \Difficulty  Medium.
* \Brief       Given n pairs of parentheses, write a function to 
*          generate all combinations of well-formed parentheses.
* \Example   
*          Given n = 3, a solution set is:
*          [
*           "((()))",
*           "(()())",
*           "(())()",
*           "()(())",
*           "()()()"
*          ]
* \Note
*          Given n will always be valid.
*/

#include <iostream>
#include <vector>

using namespace std;

// Recursive
void generate(vector<string> &result, int left, int right, string s, int n) {
  if (right == n) {
    result.push_back(s);
  }
  else {
    if (left < n) {
      generate(result, left + 1, right, s + "(", n);
    }
    if (right < left) {
      generate(result, left, right + 1, s + ")", n);
    }
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  generate(result, 0, 0, "", n);
  return result;
}

int main() {

  vector<string> result = generateParenthesis(2);

  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i].c_str() << std::endl;
  }

}
