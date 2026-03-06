# Minimum Operations

Given a text file that starts with a single `H`, find the minimum number of
operations needed to reach exactly `n` `H` characters using only:

- Copy All
- Paste

## Function

`def minOperations(n)`

- Returns the fewest number of operations.
- Returns `0` if `n` is impossible to achieve.

## Idea

The optimal strategy decomposes `n` into its prime factors.
The minimum number of operations is the sum of those factors.

Examples:

- `n = 4` -> `2 + 2 = 4` operations
- `n = 12` -> `2 + 2 + 3 = 7` operations
- `n = 9` -> `3 + 3 = 6` operations
