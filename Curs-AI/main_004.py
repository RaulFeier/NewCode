def solve(a):
    sum1 = 0
    for i in range(a):
        sum1 += (i + 1) ** 3
    return sum1

def main():
    a = input()
    a = int(a)
    print(solve(a))

if __name__ == "__main__":
    main()