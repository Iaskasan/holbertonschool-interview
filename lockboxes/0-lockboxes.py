#!/usr/bin/python3
"""lockboxes task"""


def canUnlockAll(boxes):
    """mindbending game of lockboxes"""
    keys = set([0] + boxes[0])
    opened = set([0])
    for j in range(len(boxes)):
        if j in keys:
            opened.add(j)
        for i in range(len(boxes)):
            if i in keys:
                keys.update(boxes[i])
    return len(opened) == len(boxes)
