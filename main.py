import time
from ChainMethod import ChainMethod
from DoubleHashing import DoubleHashing

# TODO do main with testing classes
def main():
    obj = ChainMethod(10000)
    start_time = time.time()
    for i in range(10000):
        obj.insert(i, i + 1)

    print("--- %s seconds ---" % (time.time() - start_time))

    obj = DoubleHashing(10000)
    start_time = time.time()
    for i in range(10000):
        obj.insert(i, i + 1)

    print("--- %s seconds ---" % (time.time() - start_time))


if __name__ == '__main__':
    main()
