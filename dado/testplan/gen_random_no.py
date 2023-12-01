import random
import sys

random.seed(sys.argv[1])

N = int(sys.argv[2])

assert N % 2 == 0
assert N > 2

# Asegurarse que al menos un i aparece con su complemento
i = random.randint(1, N // 2)
candidates = [j for j in range(1, N + 1) if j != i and j != N + 1 - i]

random.shuffle(candidates)

vals = candidates[: N // 2 - 2]
vals.append(i)
vals.append(N + 1 - i)

random.shuffle(vals)

print(N)
print(" ".join(str(v) for v in vals))
