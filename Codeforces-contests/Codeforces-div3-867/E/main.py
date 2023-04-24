def min_ops_to_anti_palindrome(s):
    n = len(s)
    if n == 1:
        return 0
    diff_count = 0
    for i in range(n//2):
        if s[i] == s[n-i-1]:
            diff_count += 1
    if diff_count == 0:
        return n//2  # swap any two characters in the middle
    elif diff_count == 1:
        return n//2  # swap the different characters in the middle
    else:
        return -1   # anti-palindrome not possible

t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    print(min_ops_to_anti_palindrome(s))
