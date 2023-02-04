
def main():
    x,y,n = input().split()

    x = int(x)
    y = int(y)
    n = int(n)

    for i in range(1,n+1):
        if i % x == 0 and i % y == 0:
            print("FizzBuzz", end="\n")
        elif i % x == 0:
            print("Fizz", end="\n")
        elif i % y == 0:
            print("Buzz", end="\n")
        else:
            print(i, end="\n")

if __name__ == "__main__":
    main()