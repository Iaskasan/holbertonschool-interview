#!/usr/bin/python3
"""Can it unlocks all boxes?"""


def canUnlockAll(boxes):
    """determine if all the boxes can be opened"""
    keys = set([0])
    to_visit = [0]

    while to_visit:
        current_box = to_visit.pop()
        for key in boxes[current_box]:
            if key not in keys and key < len(boxes):
                keys.add(key)
                to_visit.append(key)
    return len(keys) == len(boxes)
