import math

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def count_primes_in_range(l, r):
    primes = []
    for i in range(l, r + 1):
        if is_prime(i):
            primes.append(i)
    return len(primes) // 3

# Reading input
test_cases = [
    (1, 3),
    (3, 7),
    (10, 21),
    (2, 8),
    (51, 60),
    (2, 15),
    (10, 26),
    (1, 1000)
]

# Calculating results for each test case
results = []
for l, r in test_cases:
    results.append(count_primes_in_range(l, r))

# Output the results
for result in results:
    print(result)
