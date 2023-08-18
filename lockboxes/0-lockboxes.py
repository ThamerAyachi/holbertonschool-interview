#!/usr/bin/python3
"""
_summary_

"""


def canUnlockAll(boxes):
    """_summary_

    Args:
        boxes (_type_): _description_

    Returns:
        _type_: _description_
    """
    n = len(boxes)
    visited = set()
    stack = [0]  # Start with the first box

    while stack:
        current_box = stack.pop()
        visited.add(current_box)

        # Check the keys in the current box
        for key in boxes[current_box]:
            if key not in visited:
                stack.append(key)

    # If all boxes have been visited, return True
    return len(visited) == n
