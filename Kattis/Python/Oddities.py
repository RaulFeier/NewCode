
def main():
    n = int(input())
    
    for i in range(n):
        a = int(input())
        
        if a % 2 == 0:
            print(a, "is even", end="\n")
        else:
            print(a, "is odd", end="\n")

if __name__ == "__main__":
    main()