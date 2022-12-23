import matplotlib.pyplot as plt
from ChainMethod import ChainMethod
from TestMethod import TestMethod

# TODO method start
class TestChainMethod(TestMethod):
    def __init__(self, type_of_case=1, count_of_elements=10000):
        super().__init__(ChainMethod, type_of_case, count_of_elements)

    def start(self):
        pass

# TODO delete main
def main():
    obj = TestChainMethod
    obj.build_graph('zxc', 'green')
    #obj.build_graph()
    #plt.title('Исследование сложности операций')
    #plt.xlabel('Количество элементов')
    #plt.ylabel('Время, нс')
    plt.show()


if __name__ == '__main__':
    main()
