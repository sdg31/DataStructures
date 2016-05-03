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

// uses prime factorization https://en.wikipedia.org/wiki/Prime_factor
// uses the least prime factor on each step of factorization
// in order to be left with the greatest prime factor at the end
// this is inefficient but we only do it once so it is okay
inline int greatest_prime_factor(int x) {

	// while x is not prime
	while (!is_prime(x)) {

		// find least valued prime x is divisible by
		for (int divisor = 2; divisor < x; divisor++) {
			if (is_prime(divisor) && x%divisor == 0) {
				x /= divisor;
				break;
			}

		}
	}

	return x;
}

#endif