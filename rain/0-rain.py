#!/usr/bin/python3
"""
rain
"""


def rain(walls):
    """
    Calculates how many square units of water will be retained after it rains.
    Args:
        walls: A list of non-negative integers representing the heights of walls.
    Returns:
        Integer indicating total amount of rainwater retained.
    """
    if not walls:
        return 0

    total_water = 0
    n = len(walls)

    # Initialize left and right arrays to store maximum heights to the left and right of each wall
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water retained above each wall
    for i in range(n):
        total_water += min(left_max[i], right_max[i]) - walls[i]

    return total_water


if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))
