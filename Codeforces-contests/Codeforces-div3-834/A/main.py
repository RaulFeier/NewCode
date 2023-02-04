
def main():
    n = int(input())

    a = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes"

    for i in range(n):
        t = input()
        anw = False
        if t in a:
            anw = True
        if anw:
            print("Yes")
        else:
            print("NO")
        anw = False

if __name__ == "__main__":
    main()