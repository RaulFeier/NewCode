def main():
    tc = int(input())

    while tc > 0:
        tc -= 1
        
        n = int(input())

        Mihai = 0
        Bianca = 0

        nr = input().split()
        arr = [int(x) for x in nr]

        for i in arr:
            if i % 2 == 0:
                Mihai += i
            else:
                Bianca += i

        if (Mihai > Bianca):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()