class Node:
    def __init__(self, key, data, next):
        self.key = key
        self.data = data
        self.next = next

    def __str__(self):
        table = f'[{self.key}: {self.data}] '

        next_ = self.next
        while next_ is not None:
            table += f'-> [{next_.key}: {next_.data}] '
            next_ = next_.next

        return table


class ChainMethod:
    def __init__(self, size=20):
        self.__size = size
        self.__table = [None] * self.__size
        self.__k = 0
        self.__func = self.__hash_func

    def set_worst_case(self) -> None:
        self.__func = self.__worst_case

    def set_normal_func(self) -> None:
        self.__func = self.__hash_func

    def __worst_case(self, key: int) -> int:
        return 0
    def __hash_func(self, key: int) -> int:
        return key % self.__size

    def insert(self, key: int, value) -> None:
        if self.__k < 2/3:
            hash_key = self.__func(key)
            self.__table[hash_key] = Node(key, value, self.__table[hash_key])
            self.__k += 1 / self.__size
        else:
            self.increase_size(self.__size // 2)
            self.insert(key, value)

    def __setitem__(self, key: int, value):
        self.insert(key, value)

    def find(self, key: int):
        hash_key = self.__func(key)
        elem = self.__table[hash_key]

        while elem:
            if key == elem.key:
                return elem.data
            elem = elem.next

        return None

    def __getitem__(self, key: int):
        return self.find(key)

    def remove(self, key: int) -> None:
        hash_key = self.__func(key)
        cur = self.__table[hash_key]

        if cur is None:
            return None
        elif key == cur.key:
            self.__table[hash_key] = cur.next
            return None

        prev = cur
        cur = cur.next

        while cur:
            if key == cur.key:
                prev.next = cur.next
                return None
            prev = cur
            cur = cur.next

    def increase_size(self, add_size: int) -> None:
        self.__table += [None] * add_size
        self.__size += add_size
        self.__k = 0

    def __str__(self):
        res = ''

        for i in range(len(self.__table)):
            if self.__table[i]:
                res += f'{i}: {self.__table[i]}\n'

        return res
