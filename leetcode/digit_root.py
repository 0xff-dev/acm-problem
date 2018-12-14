"""
134 = 1+3+4= 8
456 = 4+5+6= 1+5 = 6
"""

def digit_root(n: int):
    while n>=10:
        n = n//10+n%10
    return n
