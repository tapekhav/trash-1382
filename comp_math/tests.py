from modules.runge4 import Simulation


def test1():
    F =     10000000
    m0 =    1000000
    mk =    500000
    alpha = 10000
    return F, m0, mk, alpha, 15


def test2():
    F =     10000000
    m0 =    1000000
    mk =    500000
    alpha = 10000
    return F, m0, mk, alpha, -1


def test3():
    F =     20000000
    m0 =    2000000
    mk =    500000
    alpha = 10000
    return F, m0, mk, alpha, -1


def test4():
    F =     15000000
    m0 =    1250000
    mk =    200000
    alpha = 5000
    return F, m0, mk, alpha, 30


def test5():
    F =     10000000
    m0 =    1250000
    mk =    200000
    alpha = 5000
    return F, m0, mk, alpha, -1


def test6():
    F =     25000000
    m0 =    2000000
    mk =    200000
    alpha = 5000
    return F, m0, mk, alpha, 100


def main():
    A = Simulation(*test6())
    A.start()


if __name__ == '__main__':
    main()
