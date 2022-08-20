class Solution {
    public int reverse(int x) {
		int reversed_integer = 0;
		try {
			String intconst = Integer.toString(x);
			int sign = +1;

			// Check leading minus sign
			if (x < 0) {
				sign = -1;
				intconst = intconst.substring(1, intconst.length());
			}
			
			// Reverse the string
			final String reversed_intconst = new StringBuilder(intconst).reverse().toString();
			// Parse to integer and determine positive/negative
			reversed_integer = Integer.parseInt(reversed_intconst) * sign;
		} catch (NumberFormatException e) {
			// Go through here when the input overflow then return 0
			reversed_integer = 0;
		} catch (Exception e) {
			// Other exceptions
			e.printStackTrace();
			throw e;
		}

		return reversed_integer;
    }
}