def luckiest_starship(l, r):
    max_luckiness = 1000000000000000000
    luckiest_starship = -1
    
    for i in range(l, r+1):
        digits = [int(d) for d in str(i)]
        max_digit = max(digits)
        min_digit = min(digits)
        if max_digit == min_digit:
            return i
            
        luckiness = max_digit - min_digit
        if luckiness < max_luckiness:
            max_luckiness = luckiness
            luckiest_starship = i
    
    return luckiest_starship


t = int(input())

for _ in range(t):
    l, r = map(int, input().split())
    print(luckiest_starship(l, r), end='\n')