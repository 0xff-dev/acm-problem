#!/usr/bin/env python
# coding=utf-8

from time import sleep
import threading


sort_datas = [15, 10, 7, 30]


def deal_func(num):
    sleep(num)
    print(num)


if __name__ == '__main__':
    for data in sort_datas:
        th = threading.Thread(target=deal_func, args=(data,))
        th.start()

