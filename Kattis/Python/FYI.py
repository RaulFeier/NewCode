
def main():
    n = int(input())

    if(n < 5550000 or n > 5559999):
        print(0, end="\n")
    else:
        print(1, end="\n")

if __name__ == "__main__":
    main()