def max1(a, b):
    if a > b:
        return a
    else:
        return b

def main():
    a = ""
    t = 0
    max1 = 0
    while (True):
        a = input()
        if a == "":
            max1 = max(t, max1)
        else:
            a = int(a)
            t += a
    print(max1)

if __name__ == "__main__":
    main()