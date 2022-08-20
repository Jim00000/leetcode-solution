class Solution {

	public boolean isPalindrome(int x) {
		try {
			final long invVal = invertedInteger(x);
			return invVal == x ? true : false;
		} catch (UnsupportedOperationException e) {
			return false;
		}
	}

	public long invertedInteger(int x) throws UnsupportedOperationException {
		if (x < 0)
			throw new UnsupportedOperationException();
		final int numdigits = numOfDigits(x);
		long invVal = 0;
		for (int i = 0, tmp = x; i < numdigits; i++, tmp /= 10) {
			final int digit = tmp % 10;
			invVal += digit * Math.pow(10, numdigits - 1 - i);
		}
		return invVal;
	}

	public int numOfDigits(int x) {
		return x == 0 ? 1 : (int) (Math.floor(Math.log10(x)) + 1);
	}
}