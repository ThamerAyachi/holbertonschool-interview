#!/usr/bin/python3
""" dertimines minimum number of "copy all"/"paste"
operations to produce `n` number characters starting from 1. """


def minOperations(n):
    if not isinstance(n, int) or n < 1:
        return 0

    minOps = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            minOps += divisor
            n //= divisor
        divisor += 1

    return minOps
