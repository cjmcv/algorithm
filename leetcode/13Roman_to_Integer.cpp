/*!
* \Problem     LeetCode 13. Roman to Integer
* \Difficulty  Easy.
* \Brief       Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
*
*              Symbol       Value
*               I             1
*               V             5
*               X             10
*               L             50
*               C             100
*               D             500
*               M             1000
*             For example, two is written as II in Roman numeral, just two one's added together.
*           Twelve is written as, XII, which is simply X + II. The number twenty seven is written
*           as XXVII, which is XX + V + II.
**            Roman numerals are usually written largest to smallest from left to right. However,
*           the numeral for four is not IIII. Instead, the number four is written as IV. Because
*           the one is before the five we subtract it making four. The same principle applies to
*           the number nine, which is written as IX. There are six instances where subtraction
*           is used:
*
*           I can be placed before V (5) and X (10) to make 4 and 9.
*           X can be placed before L (50) and C (100) to make 40 and 90.
*           C can be placed before D (500) and M (1000) to make 400 and 900.
*           Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
*
* \Example
*          Input: "III"
*          Output: 3
*
*          Input: "LVIII"
*          Output: 58
*          Explanation: C = 100, L = 50, XXX = 30 and III = 3.
*
*          Input: "MCMXCIV"
*          Output: 1994
*          Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <iostream>
#include <vector>

using namespace std;

int romanToInt(string s) {
  const char *sc = s.c_str();
  int ret = 0;
  for (int i = 0; sc[i]; i++) {
    switch (sc[i]) {
    case 'I': ret += sc[i + 1] && (sc[i + 1] == 'V' || sc[i + 1] == 'X') ? -1 : 1; break;
    case 'X': ret += sc[i + 1] && (sc[i + 1] == 'L' || sc[i + 1] == 'C') ? -10 : 10; break;
    case 'C': ret += sc[i + 1] && (sc[i + 1] == 'D' || sc[i + 1] == 'M') ? -100 : 100; break;
    case 'V': ret += 5; break;
    case 'L': ret += 50; break;
    case 'D': ret += 500; break;
    case 'M': ret += 1000; break;
    }
  }
  return ret;
}
int main() {

  string input = "MCMXCIV";
  printf("output = %d\n", romanToInt(input));
}
