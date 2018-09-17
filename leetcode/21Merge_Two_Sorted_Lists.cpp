/*!
* \Problem     LeetCode 21. Merge Two Sorted Lists.
* \Difficulty  Easy.
* \Brief       Merge two sorted linked lists and return it as a new list.
*          The new list should be made by splicing together the nodes of 
*          the first two lists.
* \Example   
*          Input: 1->2->4, 1->3->4
*          Output: 1->1->2->3->4->4
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;

  // Find the head.
  ListNode *result = l1;
  if (l1->val <= l2->val) {
    result = l1;
    l1 = l1->next;
  }
  else {
    result = l2;
    l2 = l2->next;
  }

  ListNode *curNode = result;
  while (l1 != NULL || l2 != NULL) {
    if (l1 == NULL) {
      while (l2 != NULL) {
        curNode->next = l2;
        curNode = curNode->next;
        l2 = l2->next;
      }
    }
    else if (l2 == NULL) {
      while (l1 != NULL) {
        curNode->next = l1;
        curNode = curNode->next;
        l1 = l1->next;
      }
    }
    else {
      if (l1->val <= l2->val) {
        curNode->next = l1;
        l1 = l1->next;
      }
      else {
        curNode->next = l2;
        l2 = l2->next;
      }
      curNode = curNode->next;
    }
  }
  return result;
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
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *output = mergeTwoLists(l1, l2);
  ListNode *t = output;
  while (t != NULL) {
    printf("%d, ", t->val);
    t = t->next;
  }

  deleteListNode(output);
}
