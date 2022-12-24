from ChainMethod import ChainMethod
from DoubleHashing import DoubleHashing
from TestMethod import TestMethod, Case
import sys
sys.setrecursionlimit(15000)

# TODO do main with testing classes
def main():
    table_chain = TestMethod(ChainMethod, 10000)
    table_double_hashing = TestMethod(DoubleHashing, 10000)

    # Лучший случай
    table_chain.choose_case(Case.BEST)
    table_double_hashing.choose_case(Case.BEST)

    table_chain.start('Метод цепочек(лучший случай)')
    table_double_hashing.start('Двойное хэширование(лучший случай)')

    # Худший случай
    table_chain.choose_case(Case.WORST)
    table_double_hashing.choose_case(Case.WORST)

    table_chain.start('Метод цепочек(худший случай)')
    table_double_hashing.start('Двойное хэширование(худший случай)')

    # Средний случай
    table_chain.choose_case(Case.MEDIUM)
    table_double_hashing.choose_case(Case.MEDIUM)

    table_chain.start('Метод цепочек(средний случай)')
    table_double_hashing.start('Двойное хэширование(средний случай)')


if __name__ == '__main__':
    main()
