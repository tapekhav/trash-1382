class Node:
    __data = 0
    __prev__ = None
    __next__ = None

    def __init__(self, data, prev=None, next=None):
        self.__data = data
        self.__prev__ = prev
        self.__next__ = next

    def get_data(self):
        return self.__data if self else None

    def __str__(self):
        return "data: {}, prev: {}, next: {}".format(self.get_data(),
                                                     Node.get_data(self.__prev__),
                                                     Node.get_data(self.__next__))


class LinkedList:
    __length__ = 0
    __first__ = None
    __last__ = None

    def __init__(self, first=None, last=None):
        if first is None and last is not None:  # - +
            raise ValueError("invalid value for last")
        elif first is not None and last is None:  # + -
            self.append(first)
        elif first is not None:  # + +
            self.append(first)
            self.append(last)
        else:  # - -
            pass

    def __len__(self):
        return self.__length__

    def __str__(self):
        if (len(self) == 0): return "LinkedList[]"
        return "LinkedList[length = {}, [".format(len(self)) + self.__listSting__() + "]]"

    def clear(self):
        self.__last__ = None
        self.__first__ = None
        self.__length__ = 0

    def __listSting__(self):
        res = ""
        if (len(self) > 0):
            current = self.__first__
            res += str(current)
            while (current.__next__ != None):
                current = current.__next__
                res += "; " + str(current)
        else:
            return ""
        return res

    def append(self, element):
        if self.__len__() == 0:
            self.__first__ = Node(element)
            self.__last__ = self.__first__
        else:
            newNode = Node(element, self.__last__)
            self.__last__.__next__ = newNode
            self.__last__ = self.__last__.__next__
        self.__length__ += 1

    def pop(self):
        if len(self) == 0:
            raise IndexError("LinkedList is empty!")
        elif len(self) == 1:
            self.clear()
            return
        self.__last__.__prev__.__next__ = None
        self.__last__ = self.__last__.__prev__
        self.__length__ -= 1

    def popitem(self, element):
        cur = self.__first__

        while cur is not None:
            if cur.get_data() == element:
                if cur.__next__ is not None and cur.__prev__ is not None:  # mid
                    cur.__next__.__prev__ = cur.__prev__
                    cur.__prev__.__next__ = cur.__next__
                    self.__length__ -= 1
                    return
                elif cur.__next__ is not None and cur.__prev__ is None:  # first
                    cur.__next__.__prev__ = cur.__prev__
                    self.__first__ = cur.__next__
                    self.__length__ -= 1
                    return
                elif cur.__next__ is None and cur.__prev__ is not None:  # last
                    cur.__prev__.__next__ = cur.__next__
                    self.__last__ = cur.__prev__
                    self.__length__ -= 1
                    return
                else:  # only one
                    self.clear()
                    return

            cur = cur.__next__

        raise KeyError("{} doesn't exist!".format(element))


def main():
    linked_list = LinkedList()
    print(linked_list)  # LinkedList[]
    print(len(linked_list))  # 0

    linked_list.append(10)
    print(linked_list)  # LinkedList[length = 1, [data: 10, prev: None, next: None]]
    print(len(linked_list))  # 1

    linked_list.append(20)
    print(linked_list)
    # LinkedList[length = 2, [data: 10, prev: None, next: 20; data: 20, prev: 10, next: None]]
    print(len(linked_list))  # 2

    linked_list.pop()
    print(linked_list)
    print(linked_list)  # LinkedList[length = 1, [data: 10, prev: None, next: None]]
    print(len(linked_list))  # 1

if __name__ == '__main__':
    main()
