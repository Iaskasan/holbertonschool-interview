# Sandpiles Sum

Compute the sum of two `3x3` sandpiles and stabilize the result.

## Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

## Rules

- `grid1` and `grid2` are individually stable at input.
- A sandpile is stable when every cell is `<= 3`.
- Add `grid2` into `grid1`.
- While `grid1` is unstable:
  - print `=` and the current grid,
  - topple all unstable cells simultaneously.
- No dynamic memory allocation is used.

## Toppling

For each cell with value `> 3`:

- subtract `4` from that cell,
- add `1` to each valid neighbor (up, down, left, right).

## Build example

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
./0-sandpiles
```
