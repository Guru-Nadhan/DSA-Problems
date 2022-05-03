// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
// https://leetcode.com/problems/sort-list/
// Normal Merge Sort logic. TC- O(NlogN) where N is the size of LinkedList
class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *mid = middle(head);
        Node *head2 = mid->next;
        mid->next = NULL;

        Node *first = mergeSort(head);
        Node *second = mergeSort(head2);
        return merge(first, second);
    }
    // Have to handel some edge cases when finding middle
    Node *middle(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (slow->next != NULL && (fast != NULL && fast->next != NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *first, Node *second)
    {
        Node *ans = new Node(-1);
        ans->next = NULL;
        Node *temp = ans;
        while (first != NULL && second != NULL)
        {
            if (first->data <= second->data)
            {
                temp->next = first;
                first = first->next;
                temp = temp->next;
            }
            else
            {
                temp->next = second;
                second = second->next;
                temp = temp->next;
            }
        }
        while (first != NULL)
        {
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }
        while (second != NULL)
        {
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
        return ans->next;
    }
};