class DoubleHashing:
    def __init__(self, size=20):
        self.__size = size
        self.__table = [None] * self.__size
        self.__k = 0

    def get_size(self):
        return self.__size

    def __cast_obj(self, obj) -> int:
        res = list(map(str, list(obj)))
        s = ''.join(res)
        res = sum(list(map(ord, s)))

        return res

    def __hash_func1(self, key) -> int:
        return key % self.__size

    def __hash_func2(self, key) -> int:
        return ((key << 1) * 3) % self.__size

    def insert(self, key, data, i=0) -> None:
        if i < self.__size and self.__k < 2 / 3:
            idx = (self.__hash_func1(key) + i * self.__hash_func2(key)) % self.__size
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
        i1 = self.__hash_func1(key)
        i2 = self.__hash_func2(key)
        i = i1

        k = 0
        while self.__table[i] is not None and k <= self.__size:
            if self.__table[i] != 'deleted':
                if self.__table[i][0] == key:
                    return i
            i = (i1 + k * i2) % self.__size
            k += 1

        return

    def __getitem__(self, item):
        self.find(item)

    def remove(self, key, k=0) -> None:
        if k < self.__size:
            i = (self.__hash_func1(key) + k * self.__hash_func2(key)) % self.__size
            if self.__table[i] is not None:
                if self.__table[i][0] == key:
                    self.__table[i] = 'deleted'
                else:
                    k += 1
                    self.find(key, k)
            else:
                return

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
