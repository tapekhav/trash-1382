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

    def __hash_func(self, key) -> int:
        return key % self.__size

    def insert(self, key, value) -> None:
        if self.__k < 2/3:
            hash_key = self.__hash_func(key)
            self.__table[hash_key] = Node(key, value, self.__table[hash_key])
            self.__k += 1 / self.__size
        else:
            self.increase_size(self.__size // 2)

    def __setitem__(self, key, value):
        self.insert(key, value)

    def find(self, key):
        hash_key = self.__hash_func(key)
        elem = self.__table[hash_key]

        while elem is not None:
            if key == elem.key:
                return elem.data
            elem = elem.next
        return None

    def __getitem__(self, key):
        return self.find(key)

    def remove(self, key):
        hash_key = self.__hash_func(key)
        cur = self.__table[hash_key]

        if cur is None:
            return None
        elif key == cur.key:
            self.__table[hash_key] = cur.next
            return None

        prev = cur
        cur = cur.next

        while cur is not None:
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
            if self.__table[i] is not None:
                res += f'{i}: {self.__table[i]}\n'

        return res
