def main():
    a = input()
    t = 0

    t += int(a[0]) * 4
    t += int(a[1]) * 3
    t += int(a[2]) * 2
    t += int(a[3]) * 7
    t += int(a[4]) * 6
    t += int(a[5]) * 5
    t += int(a[7]) * 4
    t += int(a[8]) * 3
    t += int(a[9]) * 2
    t += int(a[10]) * 1

    if t % 11 == 0:
        print(1)
    else:
        print(0)


main()
