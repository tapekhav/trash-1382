import matplotlib.pyplot as plt
from random import randint
from enum import Enum
import time
import gc
from ChainMethod import ChainMethod
from DoubleHashing import DoubleHashing


class Case(Enum):
    BEST = 1
    MEDIUM = 2
    WORST = 3

class TestMethod:
    def __init__(self, hash_table, count_of_elements=10000):
        self.__table = hash_table(count_of_elements)
        self.__arr_of_elements = None
        self.__count_of_elements = count_of_elements
        self.__type = None

    def choose_case(self, type_of_case: Case) -> None:
        if type_of_case == Case.WORST:
            self.__table.set_worst_case()
            self.__arr_of_elements = [randint(i, self.__count_of_elements) for i in range(self.__count_of_elements)]
        elif type_of_case == Case.BEST:
            self.__table.set_normal_func()
            self.__arr_of_elements = [int(i) for i in range(self.__count_of_elements)]
        else:
            self.__table.set_normal_func()
            self.__arr_of_elements = [randint(i, self.__count_of_elements) for i in range(self.__count_of_elements)]

        self.__type = type_of_case


    def check_insertion(self) -> list:
        result = list()

        gc.disable()
        start_time = time.time_ns()

        if type(self.__table) == ChainMethod and self.__type == Case.WORST:
            arr = list(reversed(self.__arr_of_elements))
        else:
            arr = self.__arr_of_elements

        for i in range(self.__count_of_elements):
            self.__table[arr[i]] = i
            end_time = time.time_ns()

            result.append(end_time - start_time)
        gc.enable()

        return result

    def check_finding(self) -> list:
        result = list()

        gc.disable()
        start_time = time.time_ns()
        for i in range(self.__count_of_elements):
            self.__table[self.__arr_of_elements[i]]
            end_time = time.time_ns()

            result.append(end_time - start_time)
        gc.enable()

        return result

    def check_removing(self) -> list:
        result = list()

        if type(self.__table) == ChainMethod and self.__type == Case.WORST:
            arr = list(reversed(self.__arr_of_elements))
        else:
            arr = self.__arr_of_elements

        gc.disable()
        start_time = time.time_ns()
        for i in range(self.__count_of_elements):
            self.__table.remove(arr[i])
            end_time = time.time_ns()

            result.append(end_time - start_time)
        gc.enable()

        return result

    def start(self, title: str) -> None:
        f1 = plt.subplot(3, 1, 1)
        f1.set_xlabel('Кол-во элементов')
        f1.set_ylabel('Время')
        plt.title(title)

        f2 = plt.subplot(3, 1, 2)
        f2.set_xlabel('Кол-во элементов')
        f2.set_ylabel('Время')

        f3 = plt.subplot(3, 1, 3)
        f3.set_xlabel('Кол-во элементов')
        f3.set_ylabel('Время')

        f1.grid()
        f2.grid()
        f3.grid()

        arr = [int(i) for i in range(self.__count_of_elements)]

        f1.scatter(arr, self.check_insertion(), s=0.2, color=["red"])
        f2.scatter(arr, self.check_finding(), s=0.2, color=["green"])
        f3.scatter(arr, self.check_removing(), s=0.2, color=["blue"])

        f1.legend(['Вставка'])
        f2.legend(['Поиск'])
        f3.legend(['Удаление'])

        plt.show()

    def compare_structures(self):
        table_chain = TestMethod(ChainMethod, self.__count_of_elements)
        table_chain.choose_case(self.__type)

        table_double = TestMethod(DoubleHashing, self.__count_of_elements)
        table_double.choose_case(self.__type)

        f1 = plt.subplot(1, 1, 1)
        f1.set_xlabel('Кол-во элементов')
        f1.set_ylabel('Время')
        plt.title('Метод цепочек vs Двойное хэширование')

        f1.grid()

        arr = [int(i) for i in range(self.__count_of_elements)]

        f1.scatter(arr, table_chain.check_insertion(), s=0.2, color=["red"])
        f1.scatter(arr, table_double.check_insertion(), s=0.2, color=["blue"])

        f1.legend(['Вставка(Метод цепочек)', 'Вставка(Двойное хэширование)'])

        plt.show()
