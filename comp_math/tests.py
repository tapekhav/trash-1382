from modules.runge4 import Simulation


def test1():
    F = 10**12
    m0 = 2*10**10
    mk = 2000
    alpha = 100000
    return F, m0, mk, alpha


def test2():
    F = 10**12
    m0 = 2*10**5
    mk = 1.5 * 10**5
    alpha = 100000
    return F, m0, mk, alpha


def main():
    A = Simulation(*test1())
    A.start()


if __name__ == '__main__':
    main()
