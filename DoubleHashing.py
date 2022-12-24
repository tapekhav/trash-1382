class DoubleHashing:
    def __init__(self, size=20):
        self.__size = size
        self.__table = [None] * self.__size
        self.__k = 0

        self.__func1 = self.__hash_func1
        self.__func2 = self.__hash_func2

    def get_size(self):
        return self.__size

    def set_worst_case(self) -> None:
        self.__func1 = self.__worst_case1
        self.__func2 = self.__worst_case2

    def set_normal_func(self) -> None:
        self.__func1 = self.__hash_func1
        self.__func2 = self.__hash_func2

    def __hash_func1(self, key) -> int:
        return key % self.__size

    def __hash_func2(self, key) -> int:
        return 11 - (key % 11)

    def __worst_case1(self, key) -> int:
        return 0

    def __worst_case2(self, key) -> int:
        return 1

    def insert(self, key, data, i=0) -> None:
        if i < self.__size and self.__k < 2 / 3:
            idx = (self.__func1(key) + i * self.__func2(key)) % self.__size
            if self.__table[idx] and self.__table[idx] != 'deleted':
                if self.__table[idx][0] == key:
                    self.__table[idx] = [key, data]
                else:
                    i += 1
                    self.insert(key, data, i)
            else:
                self.__table[idx] = [key, data]
                self.__k += 1 / self.__size
        else:
            self.increase_size(self.__size // 2)
            self.insert(key, data)

    def __setitem__(self, key, value):
        self.insert(key, value)

    def find(self, key):
        i1 = self.__func1(key)
        i2 = self.__func2(key)
        i = i1

        k = 0
        while self.__table[i] is not None and k <= self.__size:
            if self.__table[i] != 'deleted':
                if self.__table[i][0] == key:
                    return self.__table[i][1]
            i = (i1 + k * i2) % self.__size
            k += 1

        return None

    def __getitem__(self, item):
        return self.find(item)

    def remove(self, key) -> None:
        i1 = self.__func1(key)
        i2 = self.__func2(key)
        i = i1
        k = 0

        while self.__table[i] is not None and self.__table[i][0] != key:
            i = (i1 + k * i2) % self.__size
            k += 1

        if self.__table[i] is not None:
            self.__table[i] = 'deleted'

    def increase_size(self, add_size) -> None:
        self.__size += add_size
        self.__table += [None] * add_size
        self.__k = 0

    def __str__(self) -> str:
        res = ''

        for i in range(len(self.__table)):
            if self.__table[i] is not None:
                res += f'{i}: {self.__table[i]}\n'

        return res
