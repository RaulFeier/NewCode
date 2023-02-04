
def main():
    t = int(input())
    
    for tc in range(t):
        eep = input()

        eep1 = "MOM"
        eep2 = "OOO"
        eep3 = "OOM"
        eep4 = "MOO"

        beep = []

        if eep1 in eep:
            beep.append(len(eep) - 2)
        if eep2 in eep:
            beep.append(len(eep) - 2)
        if eep3 in eep:
            beep.append(len(eep) - 1)
        if eep4 in eep:
            beep.append(len(eep) - 3)

        beep.sort()

        if len(beep) == 0:
            print(-1)
        else:    
            print(beep[0])

main()