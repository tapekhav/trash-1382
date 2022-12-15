from ChainMethod import ChainMethod


def main():
    table = ChainMethod(5)
    # print(list('1'))
    # print(sum(list(map(ord, list(map(str, list([1, 2, 3])))))))
    table[(1, 2, 3)] = 24
    table[(12, 3)] = 25
    table[(4, 5)] = 26
    table[(1, 1, 1)] = 27
    table[(2, 1, 5)] = 27

    table.increase_size(20)

    print(table)


if __name__ == '__main__':
    main()
