class Matrix:
    __dimension__ = 0
    __matrix__ = []
    __sum__ = 0
    __index__: int = -1

    def __init__(self, index):
        self.__index__ = index
        self.__dimension__ = int(input())
        self.__matrix__ = [[0] * self.__dimension__] * self.__dimension__
        self.fillMatrix()

    def fillMatrix(self):
        for h in range(self.__dimension__):
            self.__matrix__[h] = list(map(int, input().split(' ')))
        self.__calcSum()

    def __calcSum(self):
        for i in range(self.__dimension__):
            self.__sum__ += self.__matrix__[i][i]

    def getSum(self):
        return self.__sum__

    def getIndex(self):
        return self.__index__


class ReadData:
    __n__ = 0
    __data__ = []

    def __init__(self):
        self.__n__ = int(input())
        self.read()


    def read(self):
        self.__data__ = [] * self.__n__
        for i in range(self.__n__):
            curMatrix = Matrix(i)
            self.__data__.append(curMatrix)

    def getData(self):
        return self.__data__


class MergeSort:

    def sort(self, arr):
        if (len(arr) == 1): return arr
        midIndex = len(arr) // 2
        arr1 = self.sort(arr[:midIndex])
        arr2 = self.sort(arr[midIndex:])
        return self.__merge(arr1, arr2)

    def __merge(self, arr1, arr2):
        len1 = len(arr1)
        len2 = len(arr2)
        pointer1 = pointer2 = 0
        res = []
        while pointer1 < len1 and pointer2 < len2:
            if int(arr1[pointer1].getSum()) <= int(arr2[pointer2].getSum()):
                res.append(arr1[pointer1])
                pointer1 += 1
            else:
                res.append(arr2[pointer2])
                pointer2 += 1
        if pointer1 == len1:
            res.extend(arr2[pointer2:])
        else:
            res.extend(arr1[pointer1:])
        print(' '.join(str(matrix.getIndex()) for matrix in res))
        return res


def main():
    data = ReadData()
    mergeSort = MergeSort()

    arr = data.getData()
    res = mergeSort.sort(arr)
    print(' '.join(str(cur.getIndex()) for cur in res))


if __name__ == '__main__':
    main()
