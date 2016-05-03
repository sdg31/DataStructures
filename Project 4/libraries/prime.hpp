#ifndef PRIME_HPP
#define PRIME_HPP

// all prime numbers are only divisible by 1 and themselves
inline int is_prime(int x) {
	// 2 is the smallest prime
	if (x < 2)
		return false;
	else {
		for (int divisor = 2; divisor < x; divisor++)
			if (x%divisor == 0)
				return false;

		return true;
	}
}

// search for next prime lower
// this is inefficient but we only do it once so it is okay
inline int greatest_prime(int x) {

	// while x is not prime
	while (!is_prime(x)) {
		x--;
	}

	return x;
}

#endif