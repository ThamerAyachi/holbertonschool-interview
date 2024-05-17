#!/usr/bin/python3
""" 0-prime_game module"""


def isWinner(x, nums):
    """find the winnner between Ben and Maria"""
    if not nums or x < 1:
        return None
    n = max(nums)
    filter = [True for element in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not filter[i]:
            continue
        for j in range(i * i, n + 1, i):
            filter[j] = False

    filter[0] = filter[1] = False
    c = 0
    for i in range(len(filter)):
        if filter[i]:
            c += 1
        filter[i] = c

    first_player = 0
    for n in nums:
        first_player += filter[n] % 2 == 1
    if first_player * 2 == len(nums):
        return None
    if first_player * 2 > len(nums):
        return "Maria"
    return "Ben"
