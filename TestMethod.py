import matplotlib.pyplot as plt
from random import randint
from enum import Enum
import time
import gc

class Case(Enum):
    BEST = 1
    MEDIUM = 2
    WORST = 3

class TestMethod:
    def __init__(self, hash_table, count_of_elements=10000):
        self.__table = hash_table(count_of_elements)
        self.__arr_of_elements = [int(i) for i in range(count_of_elements)]
        self.__count_of_elements = count_of_elements

    def choose_case(self, type_of_case: Case) -> None:
        if type_of_case == Case.WORST:
            self.__table.set_worst_case()
        elif type_of_case == Case.BEST:
            self.__table.set_normal_func()
        else:
            self.__table.set_normal_func()
            self.__arr_of_elements = [randint(i, self.__count_of_elements * 2) for i in range(self.__count_of_elements)]


    def check_insertion(self) -> list:
        result = list()

        gc.disable()
        start_time = time.time_ns()
        for i in range(self.__count_of_elements):
            self.__table[i] = self.__arr_of_elements[i]
            end_time = time.time_ns()

            result.append(end_time - start_time)
        gc.enable()

        return result

    def check_finding(self) -> list:
        result = list()

        gc.disable()
        start_time = time.time_ns()
        for i in range(self.__count_of_elements):
            self.__table[i]
            end_time = time.time_ns()

            result.append(end_time - start_time)
        gc.enable()

        return result

    def check_removing(self) -> list:
        result = list()

        gc.disable()
        start_time = time.time_ns()
        for i in range(self.__count_of_elements):
            self.__table.remove(i)
            end_time = time.time_ns()

            result.append(end_time - start_time)
        gc.enable()

        return result

    def start(self, title: str) -> None:
        plt.title(title)

        f1 = plt.subplot(3, 1, 1)
        f1.set_xlabel('Кол-во элементов')
        f1.set_ylabel('Время')

        f2 = plt.subplot(3, 1, 2)
        f2.set_xlabel('Кол-во элементов')
        f2.set_ylabel('Время')

        f3 = plt.subplot(3, 1, 3)
        f3.set_xlabel('Кол-во элементов')
        f3.set_ylabel('Время')

        f1.grid()
        f2.grid()
        f3.grid()

        f1.scatter(self.__arr_of_elements, self.check_insertion(), s=0.2, color=["red"])
        f2.scatter(self.__arr_of_elements, self.check_finding(), s=0.2, color=["green"])
        f3.scatter(self.__arr_of_elements, self.check_removing(), s=0.2, color=["blue"])

        f1.legend(['Вставка'])
        f2.legend(['Поиск'])
        f3.legend(['Удаление'])

        plt.show()