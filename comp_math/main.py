from modules.runge4 import Simulation


def main():
    F = int(input('F = '))
    while F <= 0:
        print("F must be positive")
        F = int(input('F = '))
    #F = 10000000

    m0 = int(input('m0 = '))
    while m0 <= 0:
        print("m0 must be positive")
        m0 = int(input('m = '))
    #m0 = 20000000

    while m0 * 9.8 > F * 1.5:
        print('the thrust of the rocket is too small to lift')
        print('minimum lifting forse = ', m0 * 9.9)
        F = int(input('F = '))

    mk = int(input('mk = '))
    while mk <= 0 or mk >= m0:
        print("mk must be positive and < m0")
        mk = int(input('F = '))
    #mk = 5000000


    alpha = int(input('alpha = '))
    while alpha <= 0:
        print("alpha must be positive")
        alpha = int(input('alpha = '))
    #alpha = 100000

    time_lim = int(input('time_lim = '))
    while time_lim < 0 and time_lim != -1:
        print("time_lim must be positive or -1 if no limits")
        time_lim = int(input('time_lim = '))

    A = Simulation(F, m0, mk, alpha, time_lim)
    A.start()


if __name__ == '__main__':
    main()
