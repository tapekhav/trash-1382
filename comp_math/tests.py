from modules.runge4 import Simulation


def test1() -> None:
    A = Simulation(-1)
    A.two_stages(2, 5000000, 500000, 100000, 10000, 40000000, 250000, 50000, 10000)
    A.start()


def test2() -> None:
    A = Simulation(-1)
    A.two_stages(2, 50000000, 500000, 100000, 10000, 40000000, 250000, 50000, 10000)
    A.start()


def test3() -> None:
    A = Simulation(-1)
    A.three_stages(3, 50000000, 500000, 100000, 10000, 40000000, 250000, 50000, 10000, 30000000, 100000, 10000, 10000)
    A.start()


def test4() -> None:
    A = Simulation(-1)
    A.three_stages(3, 10000000, 500000, 100000, 10000, 10000000, 250000, 50000, 100000, 10000000, 100000, 10000, 10000)
    A.start()


def test5() -> None:
    A = Simulation(-1)
    A.one_stage(1, 10000000, 850000, 200000, 10000)
    A.start()


def main() -> None:
    test5()


if __name__ == '__main__':
    main()
