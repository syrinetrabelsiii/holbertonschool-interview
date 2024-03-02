#!/usr/bin/python3
"""
Module for making change problem
"""

def makeChange(coins, total):
    if total < 1:
        return 0

    INF = float('inf')
    dp = [INF] * (total + 1)
    dp[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != INF else -1

if __name__ == "__main__":
    print(makeChange([1, 2, 25], 37))
    print(makeChange([1256, 54, 48, 16, 102], 1453))
