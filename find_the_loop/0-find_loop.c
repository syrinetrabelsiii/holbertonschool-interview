#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the list
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // Loop detected
        {
            slow = head; // Move one pointer to the head

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow; // Both pointers meet at the start of the loop
        }
    }

    return NULL; // No loop found
}
