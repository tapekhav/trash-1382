import matplotlib.pyplot as plt
from enum import Enum
from random import randint
import time

class Case(Enum):
    BEST = 1
    MEDIUM = 2
    WORST = 3

class TestMethod:
    def __init__(self, HashMethod, type_of_case=Case.BEST, count_of_elements=10000):
        self._arr_of_elements = [randint(1, 10000) for _ in range(count_of_elements)]
        self._count_of_elements = count_of_elements

        switch = {
            Case.WORST: HashMethod(1),
            Case.MEDIUM: HashMethod(count_of_elements//2),
            Case.BEST: HashMethod(count_of_elements),
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
    def check_insertion(self) -> list:
        result = list()

        for i in range(self._count_of_elements):
            start_time = time.time_ns()
            self._table[i] = self._arr_of_elements[i]
            end_time = time.time_ns()

            result.append(end_time - start_time)

        return result

    def check_finding(self) -> list:
        result = list()

        for i in range(self._count_of_elements):
            start_time = time.time_ns()
            self._table[i]
            end_time = time.time_ns()

            result.append(end_time - start_time)

        return result

    def check_removing(self) -> list:
        result = list()

        for i in range(self._count_of_elements):
            start_time = time.time_ns()
            self._table.remove(i)
            end_time = time.time_ns()

            result.append(end_time - start_time)

        return result

    def start(self):
        pass