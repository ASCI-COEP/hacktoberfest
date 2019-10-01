import numpy as np
import sys
import argparse


def seive(N):
    isPrime = [True] * N  # Initialize the list with prime flags
    isPrime[0] = isPrime[1] = False  # 0 and 1 are not primes
    primes = np.array([], dtype=np.int64)  # empty array for the primes

    for (i, isprime) in enumerate(isPrime):
        if isprime:
            primes = np.append(primes, i)
            for n in range(i*i, N, i):
                isPrime[n] = False
    return primes


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        'max', metavar='int', type=int, help='find primes in range(2,max)')
    args = parser.parse_args()
    primes = seive(args.max)
    print(primes)
