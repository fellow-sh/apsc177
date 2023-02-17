#!/usr/bin/env python
import time
import math
import sys
import random
from numpy import gcd, log2
from scipy.special import comb

VERY_LARGE_NUMBER = 100

def trail_division(n: int) -> bool:
    p = math.floor(n**.5)
    for i in range(2, p + 1):
        if n % i == 0:
            return False
    return True


def miller_rabin(n: int, k: int) -> bool:
    assert n % 2 == 1
    assert n > 2

    test = n - 1
    d = -1
    s = 0
    while d == -1:
        if test >> 1 == test / 2.0:
            test = test >> 1
            s += 1
        else:
            d = test
    for _ in range(k):
        a = round(random.uniform(2, n - 2))
        x = a**d % n
        for _ in range(s):
            y = x**2 % n
            if y == 1 and x != 1 and x != n - 1:
                return False
            x = y
        if y != 1:
            return False
    return True


def LFT(n: int) -> bool:
    # Implements LFT with similar preliminary checks to AKS.
    # This algorithm guarantees the number checked is or is not a prime.
    if perfect_power(n):
        return False

    R = None
    for r in range(2, VERY_LARGE_NUMBER):
        if mord(n, r) > (log2(n))**2:
            R = r
            break

    for a in range(n, 0, -1):
        cf = gcd(a, n)
        if cf > 1 and cf < n:
            return False

    if n <= r:
        return True
    #TODO: Optimize generalized-FLT based on AKS 2003
    for i in range(1, n):
        if comb(n, i, exact=True) % n != 0:
            return False
    return True


def perfect_power(n: int) -> bool:
    for b in range(2, int(log2(n) + 1)):
        if n**(1 / b) % 1 == 0:
            return True
    return False
            

def mord(a: int, n: int, bound: int = VERY_LARGE_NUMBER) -> int:
    # Returns the multiplicative order of a, n. In other words, returns the
    # smallest number k for when a^k mod n = 1.
    for k in range(1, bound):
        if k == bound:
            print('mord: warning: reached end bound')
        if a**k % n == 1:
            return k
    return 0


def gcd(a: int, b: int) -> int:
    # This is just for show: recursive calls will be inefficient for very
    # large numbers.
    if b == 0:
        return a
    return gcd(b, a % b)


def bincoeff(n: int, k: int) -> int:
    # This function is just for show: significant optimization must be made
    # for large numbers for this function to be feasible.
    top = factorial(n)
    bottom = factorial(k) * factorial(n - k)
    return top / bottom


def factorial(n: int) -> int:
    # This function is just for show: in reality, this would not be used
    # to calculate the binomial coefficient.
    answer = n
    for k in range(1, n):
        answer *= k
    return answer


def main():
    test_number = 5303
    checkpoint1 = time.time()
    print(miller_rabin(test_number, VERY_LARGE_NUMBER))
    checkpoint2 = time.time()
    print(trail_division(test_number))
    checkpoint3 = time.time()
    print(LFT(test_number))
    checkpoint4 = time.time()

    unit = 's'# if sys.platform == 'win32' else 'ms'
    print(f'Miller Rabin:   {checkpoint2 - checkpoint1} {unit}')
    print(f'Trial Division: {checkpoint3 - checkpoint2} {unit}')
    print(f'LFT:            {checkpoint4 - checkpoint3} {unit}')

if __name__ == '__main__':
    main()
