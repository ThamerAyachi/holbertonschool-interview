#!/usr/bin/python3
"""
Making Change, task 0. Change comes from within
"""


def makeChange(coins, total):
    """
    Given a set of coin denominations, determines the fewest coins needed to
    meet a given total value.

    Args:
        coins (list of (int)s): list of coin denominations available
        total (int): target total value

    Return:
        total amount of coins needed to meet `total` value

    """
    if type(total) is not int or type(coins) is not list or not all(
            [type(coin) is int for coin in coins]):
        print("Invalid args")
        return 0

    if total <= 0:
        return 0

    coins.sort(reverse=True)

    total_coins = 0
    remainder = total
    for denom in coins:
        if denom <= remainder:
            curr = remainder // denom
            total_coins += curr
            remainder -= curr * denom
        if remainder == 0:
            break

    if total_coins == 0 or remainder != 0:
        return -1

    return total_coins
