# Linked List Cycle

Check whether a singly linked list contains a cycle.

## Prototype

```c
int check_cycle(listint_t *list);
```

## Return

- `1` if the list has a cycle
- `0` if the list has no cycle

## Approach

Uses Floyd's cycle detection algorithm (tortoise and hare):

- Move `slow` by one node.
- Move `fast` by two nodes.
- If they ever meet, a cycle exists.
- If `fast` reaches `NULL`, there is no cycle.

## Complexity

- Time: `O(n)`
- Extra space: `O(1)`

## Build example

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
./cycle
```
