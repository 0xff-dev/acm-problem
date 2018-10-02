#!/usr/bin/env python
# coding=utf-8

with open('./data.txt', 'w') as fp:
    for i in range(1, 10):
        data = ' '.join(str(i) for j in range(i))
        fp.write(data+'\n')
