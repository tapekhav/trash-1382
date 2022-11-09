from modules.runge4 import Simulation


def main():
    time_lim = int(input('time_lim = '))
    while time_lim < 0:
        print("time_lim must be positive")
        time_lim = int(input('time_lim = '))

    A = Simulation(F, m0, mk, alpha, time_lim)
    A.start()


if __name__ == '__main__':
    main()
