#!/usr/bin/python3
"""Determine if all boxes can be opened."""


def canUnlockAll(boxes):
    """There can be keys that do not have boxes."""
    keys = [0]

    for key in keys:
        for idx in boxes[key]:
            if idx not in keys and idx < len(boxes):
                keys.append(idx)
    for i in range(len(boxes)):
        if i not in keys:
            return False
    return True
