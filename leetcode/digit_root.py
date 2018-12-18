"""
134 = 1+3+4= 8
456 = 4+5+6= 1+5 = 6
"""

def digit_root(n: int):
    m = n
    while n>=10:
        n = n//10+n%10
    print('{} -> {}'.format(m, n))

from random import randint
for i in range(5):
    digit_root(randint(1000, 3000))
