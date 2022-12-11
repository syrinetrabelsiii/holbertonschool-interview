#!/usr/bin/python3
"""lockboxes"""
def canUnlockAll(boxes):
    boxOne = [0]
    for key in boxOne:
        for keyBox in boxes[key]:
            if keyBox not in boxOne:
                if keyBox < len(boxes):
                    boxOne.append(keyBox)
    if len(boxOne) == len(boxes):
        return True
    return False
