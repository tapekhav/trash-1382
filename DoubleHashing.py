# TODO class DoubleHashing
class DoubleHashing:
    def __init__(self, size=20):
        self.__size = size
        self.__table = [None] * self.__size

    def __cast_obj(self, obj) -> int:
        res = list(map(str, list(obj)))
        s = ''.join(res)
        res = sum(list(map(ord, s)))

        return res

    def __hash_func1(self, key) -> int:
        key = self.__cast_obj(key)

        return (key << 5) % self.__size

    def __hash_func2(self, key) -> int:
        key = self.__cast_obj(key)

        return ((key << 12) % 1_000_000_007 % (self.__size * 1234)
                % 1_000_000_007) % 1_000_000_007
