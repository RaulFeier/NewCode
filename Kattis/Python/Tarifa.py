
def main():
    
    a = int(input())
    b = int(input())

    sum = 0
    for i in  range(b):
        x = int(input())
        sum += x

    print(a * (b + 1) - sum, end="\n")

if __name__ == '__main__':
    main()
