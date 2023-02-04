
def last_factorial_digit(n):
    total = 1
    for j in range(1, n + 1):
        total *= j
    return total % 10

def main():

    t = int(input())
    for i in range(t):
        n = int(input())
        print(last_factorial_digit(n))


if __name__ == '__main__':
    main()