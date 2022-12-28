from ChainMethod import ChainMethod
from DoubleHashing import DoubleHashing


def check_table(HashTable) -> None:
    n = int(input('Введите размер хэш-таблицы: '))
    table = HashTable(n)

    m = int(input('Введите количество элементов для вставки: '))
    for i in range(m):
        key, data = map(int, input('Введите ключ и значение: ').split())
        table[key] = data
        print('Новая таблица:')
        print(table)

    key = None
    while key != 'q':
        key = input('Введите ключ элемента, который хотите найти(для выхода напишите q): ')
        try:
            key = int(key)
        except ValueError:
            break

        print(table[key]) if table[key] is not None else print('Нет такого элемента в таблице')

    key = None
    while key != 'q':
        key = input('Введите ключ элемента, который хотите удалить(для выхода напишите q): ')
        try:
            key = int(key)
        except ValueError:
            break

        table.remove(key)
        print('Новая таблица:')
        print(table)


def main():
    n = int(input('С каким методом разрешения хэш-таблицу вы хотите тестировать?'
                  '(1 - метод цепочек, в других случаях двойное хэширование): '))
    if n == 1:
        check_table(ChainMethod)
    else:
        check_table(DoubleHashing)


if __name__ == '__main__':
    main()
