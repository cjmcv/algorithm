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
  ListNode *temp = first->next;
  first->next = first->next->next;
  delete temp;

  return head;
}

void deleteListNode(ListNode* list) {
  ListNode *t;
  while (list) {
    t = list;
    list = list->next;
    delete t;
  }
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = removeNthFromEnd(head, 1);

  while (result != NULL) {
    printf("%d, ", result->val);
    result = result->next;
  }

  deleteListNode(head);
  return 0;
}
