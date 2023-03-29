def excitement_levels(S):
    n = len(S)
    F_indices = [i for i in range(n) if S[i] == 'F']
    k = len(F_indices)
    
    counts = set()
    for i in range(2**k):
        T = list(S)
        for j in range(k):
            if i & (1 << j):
                T[F_indices[j]] = 'B'
            else:
                T[F_indices[j]] = 'E'
        T = ''.join(T)
        count = T.count('BB') + T.count('EE')
        counts.add(count)
    
    counts = sorted(counts)
    print(len(counts))
    for count in counts:
        print(count)

n = int(input())
S = input().strip()
excitement_levels(S)
