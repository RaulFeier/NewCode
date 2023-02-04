
def main():

    n = 0
    a = input()
    b = input()
    
    a, b = int(a), int(b)

    while b % a != 0:
        b += 1
        n += 1
    
    c = a - n
    d = b // a

    for i in range(c):
        for j in range(d):
            print("*", end="")
        print()
    
    while n > 0:
        for i in range((b - 1) // a):
            print("*", end="")
        print()
        n -= 1

    return 0

if __name__ == "__main__":
    main()
