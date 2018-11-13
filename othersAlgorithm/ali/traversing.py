#!/usr/bin/env python
# coding=utf-8


# 请用递归的方式遍历树形数据结构中的每一个节点
datas = [
    {
        'name': 'bj',
        'label': 'bj-label',
        'children': [
            {
                'name': 'haidian',
                'label': 'bj-haidian-label',
                'children':[
                    {
                        'name': 'wudaokou',
                        'label': 'bj-haidian-wudaokou-label',
                    }
                ]
            }
        ]
    },
    {
        'name': 'jiangsu',
        'label': 'jiangsu-label',
        'children': [
            {
                'name': 'nanjing',
                'label': 'jiangsu-nanjing-label',
                'children': [
                    {
                        'name': 'text',
                        'label': 'text'
                    }
                ]
            }
        ]
    }
]

def traversing(datas: list):
    for item in datas:
        print('name: ', item['name'], ' label: ', item['label'])
        try:
            traversing(item['children'])
        except Exception as e:
            return