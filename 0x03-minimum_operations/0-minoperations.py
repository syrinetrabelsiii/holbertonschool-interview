#!/usr/bin/python3
"""minoperations function"""


def minOperations(n):
    """calculates"""
    operations = 0
    summation = 1
    carrier = 0

    while summation < n:
        if n % summation == 0:  # Copy when summation is a multiple of n
            carrier = summation
            summation *= 2
            operations += 1
        else:
            summation += carrier
        operations += 1  # Always paste

    return operations
