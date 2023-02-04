
def main():
    a = int(input())
    sum = 0

    x = input().split()
    x = [int(i) for i in x]

    for i in range(a):
        if x[i] < 0:
           sum += x[i] * -1
    
    print(sum, end="\n")

if __name__ == "__main__":
    main()