import matplotlib.pyplot as plt
from ChainMethod import ChainMethod
from DoubleHashing import DoubleHashing
from enum import Enum
from random import randint
import time

class Case(Enum):
    BEST = 1
    MEDIUM = 2
    WORST = 3

class TestMethod:
    def __init__(self, count_of_elements=10000):
        self._table = None
        self._arr_of_random_elements = [randint(1, 10000) for _ in range(count_of_elements)]
        self._arr_of_elements = [int(i) for i in range(count_of_elements)]
        self._count_of_elements = count_of_elements

    def choose_case(self, HashMethod, type_of_case: Case):
        switch = {
            Case.WORST: HashMethod(1),
            Case.MEDIUM: HashMethod(self._count_of_elements // 2),
            Case.BEST: HashMethod(self._count_of_elements),
        }

        self._table = switch[type_of_case]

    @staticmethod
    def build_graph(title: str) -> None:
        plt.title(title)
        plt.xlabel('Количество элементов')
        plt.ylabel('Время')
        plt.grid()

    def draw_graph(self, color: str, data: list):
        plt.scatter(self._arr_of_elements, data, s=5, color=[color])
    def check_insertion(self, arr: list) -> list:
        result = list()

        start_time = time.time_ns()
        for i in range(self._count_of_elements):
            self._table[i] = arr[i]
            end_time = time.time_ns()

            result.append(end_time - start_time)

        return result

    def check_finding(self) -> list:
        result = list()

        start_time = time.time_ns()
        for i in range(self._count_of_elements):
            self._table[i]
            end_time = time.time_ns()

            result.append(end_time - start_time)

        return result

    def check_removing(self) -> list:
        result = list()

        start_time = time.time_ns()
        for i in range(self._count_of_elements):
            self._table.remove(i)
            end_time = time.time_ns()

            result.append(end_time - start_time)

        return result

    def start(self):
        pass


def main():
    pass


if __name__ == '__main__':
    main()
