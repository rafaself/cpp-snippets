#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy.next;
    }
};

int main()
{
    ListNode n3(3);
    ListNode n2(4, &n3);
    ListNode n1(2, &n2);

    ListNode n6(4);
    ListNode n5(6, &n6);
    ListNode n4(5, &n5);

    ListNode *result = Solution::addTwoNumbers(&n1, &n4); // 342 + 465 = 807

    for (ListNode *p = result; p != nullptr; p = p->next)
        std::cout << p->val << (p->next ? " -> " : "\n");

    while (result)
    {
        ListNode *nxt = result->next;
        delete result;
        result = nxt;
    }
}
