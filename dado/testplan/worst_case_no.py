import random
import sys

random.seed(sys.argv[1])

N = 1000000

vals = list(range(1, N // 2))
vals.append(N // 2 + 2)

if sys.argv[2] == "asc":
    pass
elif sys.argv[2] == "desc":
    vals.reverse()
else:
    sys.stderr.write("Primer argument debe ser 'asc' o 'desc'\n")
    sys.exit(0)

assert len(vals) == N // 2

print(N)
print(" ".join(str(v) for v in vals))
