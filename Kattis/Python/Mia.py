
def main():

    a1, a2, b1, b2 = input().split()
    a1, a2, b1, b2 = int(a1), int(a2), int(b1), int(b2)

    while a1 != 0:

        p1 = max(a1, a2) * 10 + min(a1, a2)
        p2 = max(b1, b2) * 10 + min(b1, b2)

        if p1 == 21 and p2 == 21:
            print("Tie.")
        elif p1 == 21:
            print("Player 1 wins.")
        elif p2 == 21:
            print("Player 2 wins.")

        elif p1 % 10 == p1 // 10 and p2 % 10 == p2 // 10:
            if p1 > p2:
                print("Player 1 wins.")
            elif p2 > p1:
                print("Player 2 wins.")
            else:
                print("Tie.")

        elif p1 % 10 == p1 // 10:
            print("Player 1 wins.")
        elif p2 % 10 == p2 // 10:
            print("Player 2 wins.")
        elif p1 > p2:
            print("Player 1 wins.")
        elif p2 > p1:
            print("Player 2 wins.")
        else:
            print("Tie.")

        a1, a2, b1, b2 = input().split()
        a1, a2, b1, b2 = int(a1), int(a2), int(b1), int(b2)

if __name__ == "__main__":
    main()
