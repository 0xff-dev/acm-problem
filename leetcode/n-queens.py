class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        import json
        array = [0 for i in range(n)]
        res = []
        def generate_answer(array: list, n: int):
            tmp = [['.']*n for i in range(n)]
            _tmp = []
            for index, data in enumerate(array):
                tmp[index][data] = 'Q'
                _tmp.append(''.join(tmp[index]))
            res.append(_tmp)

        def search(row: int):
            if row == n:
                generate_answer(json.loads(json.dumps(array)), n)
            else:
                for i in range(n):
                    flag = True
                    array[row] = i
                    for j in range(row):
                        if (array[row]==array[j]) or (row-array[row]==j-array[j]) \
                            or (row+array[row]==j+array[j]):
                            flag = False
                            break
                    if flag:
                        search(row+1)
        search(0)
        return res
