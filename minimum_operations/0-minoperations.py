#!/usr/bin/python3
"""Minimum operations module."""


def minOperations(n):
    """Return the fewest number of operations to get n H characters.

    Allowed operations are Copy All and Paste. If n is not possible,
    return 0.
    """
    if not isinstance(n, int) or n < 2:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
