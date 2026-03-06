# Linked List Palindrome

Check whether a singly linked list is a palindrome.

## Prototype

```c
int is_palindrome(listint_t **head);
```

## Return

- `1` if the list is a palindrome
- `0` if it is not
- An empty list is considered a palindrome

## Approach

- Use two pointers (`slow`, `fast`) to find the middle.
- Reverse the second half of the list in place.
- Compare first half and reversed second half node by node.
- Restore the second half to keep the original list structure.

This runs in `O(n)` time and `O(1)` extra space.
