/*!
* \Problem     LeetCode 2: Add Two Numbers.
* \Difficulty  Medium.
* \Brief       You are given two non-empty linked lists representing
*          two non-negative integers. The digits are stored in reverse
*          order and each of their nodes contain a single digit. Add 
*          the two numbers and return it as a linked list. You may assume
*          the two numbers do not contain any leading zero, except the 
*          number 0 itself.
* \Example 
*          Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*          Output: 7 -> 0 -> 8
*          Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *result = new ListNode(0);
  ListNode *current = result;
  ListNode *p1 = l1;
  ListNode *p2 = l2;

  int carry = 0;
  while (p1 != NULL || p2 != NULL) {
    int a = (p1 != NULL) ? p1->val : 0;
    int b = (p2 != NULL) ? p2->val : 0;

    int sum = a + b + carry;

    carry = sum / 10;
    sum = sum % 10;

    current->next = new ListNode(sum);

    current = current->next;
    if (p1 != NULL) p1 = p1->next;
    if (p2 != NULL) p2 = p2->next;
  }

  if (carry != 0)
    current->next = new ListNode(carry);

  return result->next;
}

int main() {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode *res = addTwoNumbers(l1, l2);

  while (res != NULL) {
    printf("%d, ", res->val);
    res = res->next;
  }
}
