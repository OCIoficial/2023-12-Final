# This script generates random test cases for the sample task. It takes a
# minimum and maximum value and prints two random numbers in that range.
# See the comment in testplan.txt for further details.

import random
import sys

# The argument in position 1 is the hidden seed.
random.seed(sys.argv[1])

# The min and max are in positions 2 and 3
n = int(sys.argv[2])
k = int(sys.argv[3])

print(n, k)
for _ in range(k):
	jugada = str(random.randint(0, 2))
	print(" ".join([jugada]*n))