import random
import sys

random.seed(sys.argv[1])

N = int(sys.argv[2])

assert N % 2 == 0

print(N)
vals = [str(random.choice([i, N + 1 - i])) for i in range(1, N // 2 + 1)]
print(" ".join(vals))
