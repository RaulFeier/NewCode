
def main():
    n = int(input())

    start = 0
    end = 0
    temp = 0

    t = bool(False)

    while n > 0:
        a = int(input())
        t = not t
        if t:
            start = a
        else:
            end = a
            temp += end - start
        n -= 1
    if(t):
        print("still running\n")
    else:
        print(temp, end="\n")

if __name__ == '__main__':
    main()
