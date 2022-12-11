#!/usr/bin/python3
"""Determines if all boxes can be opened."""


def canUnlockAll(boxes):
    keys = [0]

    for key in keys:
        for x in boxes[key]:
            if x not in keys and x < len(boxes):
                keys.append(x)
    for i in range(len(boxes)):
        if i not in keys:
            return False
    return True
