from modules.runge4 import Simulation


def main():
    A = Simulation(30)
    A.init_rocket()

    A.start()


if __name__ == '__main__':
    main()
