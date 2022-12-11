#!/usr/bin/python3
"""lockboxes"""

def canUnlockAll(boxes):
    """There can be keys that do not have boxes"""
    keys = [0]

    for key in keys:
        for i in boxes[key]:
            if i not in keys and i < len(boxes):
                keys.append(i)
    for i in range(len(boxes)):
        if i not in keys:
            return False
    return True
