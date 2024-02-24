def optimal_winner(S):
    if S % 10 == 0:
        return 'E'
    return "B"


T = int(input())
for _ in range(T):
    S = int(input())
    print(optimal_winner(S))
