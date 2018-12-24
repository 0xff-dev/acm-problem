#!/usr/bin/env python
# coding=utf-8


loc_map = {
    'U': [0, 1],
    'D': [0, -1],
    'L': [-1, 0],
    'R': [1, 0]
}


def can_return_site(ops: str) -> bool:
    loc = [0, 0]
    for char in ops:
        loc = list(map(lambda x: sum(x), zip(loc, loc_map[char])))
    if loc == [0, 0]:
        return True
    return False

print(can_return_site('URDL'))
