
def main():

    n = int(input())
    sum = 0
    res = 0
    i = 1

    while True:
        
        sum += i * i
        if sum <= n:
            res += 1
            i += 2
        else:
            break

    print(res)

if __name__ == "__main__":
    main()