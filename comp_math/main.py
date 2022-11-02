from modules.runge4 import Simulation


def main():
    F = int(input('F = '))
    F = 10000000

    m0 = int(input('m0 = '))
    # m0 = 20000000

    mk = int(input('mk = '))
    # mk = 500000

    if m0 * 9.8 > F:
        F = m0 * 9.8 + 10000

    alpha = int(input('alpha = '))
    # alpha = 100000

    A = Simulation(F, m0, mk, alpha)
    A.start()


if __name__ == '__main__':
    main()
