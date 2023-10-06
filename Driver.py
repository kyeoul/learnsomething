import timeit
import sympy

def disasterCode():
    primes = [2]
    memo = [0 for x in range(1000)]
    for i in range(2, 1000):
        factors = []
        isPrime = True
        for prime in primes:
            if i % prime == 0:
                memoindex = int(i / prime)
                factors.append(prime)
                factors.append(memo[memoindex])
                isPrime = False
                break
        if isPrime:
            primes.append(i)
            factors.append(i)

        memo[i] = factors

# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")

    # Measure the execution time of disasterCode function
    benchmark_code = "util.calcPrimes()"
    setup_code = "import cppimport.import_hook;import Primes;util = Primes.Primes()"
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs (C++): {res:.6f} seconds")
