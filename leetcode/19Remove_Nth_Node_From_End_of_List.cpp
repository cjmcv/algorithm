/*!
* \Problem     LeetCode 19: Remove Nth Node From End of List
* \Difficulty  Medium.
* \Brief       Given a linked list, remove the n-th node from
*          the end of list and return its head.
* \Example   
*          Given linked list: 1->2->3->4->5, and n = 2.
*              After removing the second node from the end, 
*          the linked list becomes 1->2->3->5.
* \Note
*          Given n will always be valid.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *first = head;
  ListNode *second = head;

  // 1. Make the spacing between first and second be n.
  while (n--) {
    second = second->next;
  }

  // 2. (if) To facilitate the removal of node in step 4.
  //    (else) For the case that remove the head node.
  if (second != NULL)
    second = second->next;
  else
    return head->next;

  // 3. Loop to the target node.
  while (second != NULL) {
    first = first->next;
    second = second->next;
  }

  // 4. Skip.
  first->next = first->next->next;
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  ListNode *a = new ListNode(2);
  ListNode *b = new ListNode(3);
  ListNode *c = new ListNode(4);
  ListNode *d = new ListNode(5);

  head->next = a;
  a->next = b;
  //b->next = c;
  //c->next = d;

  ListNode *result = removeNthFromEnd(head, 1);

  while (result != NULL) {
    printf("%d, ", result->val);
    result = result->next;
  }

}
