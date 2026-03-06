# Palindrome Integer

Check whether a given unsigned integer is a palindrome.

## Prototype

```c
int is_palindrome(unsigned long n);
```

## Return

- `1` if `n` is a palindrome
- `0` otherwise

## Constraints

- No dynamic memory allocation (`malloc`, `calloc`, etc.)

## Approach

- Reject numbers ending in `0` (except `0` itself).
- Reverse only half of the digits.
- Compare first half and reversed second half.
- Works for even and odd digit counts in `O(d)` time and `O(1)` space.

## Build example

```bash
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
./palindrome 12321
```
