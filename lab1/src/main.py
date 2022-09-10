def height(tree, n):
    d = dict()

    for i in range(n):
        h = 1
        cur = tree[i]
        while cur != -1:
            if cur not in d:
                cur = tree[cur]
                h += 1
            else:
                h += d[cur]
                break

        d[i] = h

    return max(d.values())


def main():
    n = int(input())
    data = [int(i) for i in input().split()]

    print(height(data, n))


if __name__ == '__main__':
    main()

