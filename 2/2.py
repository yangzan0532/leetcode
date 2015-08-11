# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        curr = None
        res = None
        flag = 0
        while (l1 is not None) or (l2 is not None):
            if l1 is None:
                v1 = 0
            else :
                v1 = l1.val
                l1 = l1.next

            if l2 is None:
                v2 = 0
            else:
                v2 = l2.val
                l2 = l2.next
            nv = v1 + v2 + flag
            if curr is None:
                res = ListNode(nv%10)
                curr = res
            else:
                curr.next = ListNode(nv%10)
                curr = curr.next
            flag = nv / 10
        
        if flag != 0:
            curr.next = ListNode(flag)
        return res

if __name__ == "__main__": 
    l1 = ListNode(1)
    l2 = ListNode(1)
    l1.next = ListNode(1)
    s = Solution()
    res = s.addTwoNumbers(l1, l2)
    while res is not None:
        print(res.val)
        res = res.next


