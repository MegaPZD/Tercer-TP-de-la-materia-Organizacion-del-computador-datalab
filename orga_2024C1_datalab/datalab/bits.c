/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

	Replace the "return" statement in each function with one
	or more lines of C code that implements the function. Your code
	must conform to the following style:

	int Funct(arg1, arg2, ...) {
			/* brief description of how your implementation works */
			int var1 = Expr1;
			...
			int varM = ExprM;

			varJ = ExprJ;
			...
			varN = ExprN;
			return ExprR;
	}

	Each "Expr" is an expression using ONLY the following:
	1. Integer constants 0 through 255 (0xFF), inclusive. You are
			not allowed to use big constants such as 0xffffffff.
	2. Function arguments and local variables (no global variables).
	3. Unary integer operations ! ~
	4. Binary integer operations & ^ | + << >>

	Some of the problems restrict the set of allowed operators even further.
	Each "Expr" may consist of multiple operators. You are not restricted to
	one operator per line.

	You are expressly forbidden to:
	1. Use any control constructs such as if, do, while, for, switch, etc.
	2. Define or use any macros.
	3. Define any additional functions in this file.
	4. Call any functions.
	5. Use any other operations, such as &&, ||, -, or ?:
	6. Use any form of casting.
	7. Use any data type other than int.  This implies that you
		 cannot use arrays, structs, or unions.


	You may assume that your machine:
	1. Uses 2s complement, 32-bit representations of integers.
	2. Performs right shifts arithmetically.
	3. Has unpredictable behavior when shifting if the shift amount
		 is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
	/*
	 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
	 */
	int pow2plus1(int x) {
		 /* exploit ability of shifts to compute powers of 2 */
		 return (1 << x) + 1;
	}

	/*
	 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
	 */
	int pow2plus4(int x) {
		 /* exploit ability of shifts to compute powers of 2 */
		 int result = (1 << x);
		 result += 4;
		 return result;
	}

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
	1. Define or use any macros.
	2. Define any additional functions in this file.
	3. Call any functions.
	4. Use any form of casting.
	5. Use any data type other than int or unsigned.  This means that you
		 cannot use arrays, structs, or unions.
	6. Use any floating point data types, operations, or constants.


NOTES:
	1. Use the dlc (data lab checker) compiler (described in the handout) to
		 check the legality of your solutions.
	2. Each function has a maximum number of operations (integer, logical,
		 or comparison) that you are allowed to use for your implementation
		 of the function.  The max operator count is checked by dlc.
		 Note that assignment ('=') is not counted; you may use as many of
		 these as you want without penalty.
	3. Use the btest test harness to check your functions for correctness.
	4. Use the BDD checker to formally verify your functions
	5. The maximum number of ops for each function is given in the
		 header comment for each function. If there are any inconsistencies
		 between the maximum ops in the writeup and in this file, consider
		 this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	return ~(~x | ~y);
}
/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
	return (x & y) | (~x & ~y);
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
	return ~x & ~y;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	int a = ~(x & y);
	int b = ~(x & a);
	int c = ~(y & a);
	return ~(b & c);
}
//2
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int m8 = 0xAA;
	int m16 = m8 | m8 << 8;
	int m32 = m16 | m16 << 16;
	int a = x ^ m32;
	return !(a & m32);
}
/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
	int m8 = 0x55;
	int m16 = m8 | m8 << 8;
	int m32 = m16 | m16 << 16;
	int even_x = x & m32;
	return !!even_x;
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	int byte_n = (x >> (n << 3)) & 0xFF;
	int byte_m = (x >> (m << 3)) & 0xFF;
	x &= ~(0xFF << (n << 3));
	x &= ~(0xFF << (m << 3));
	x |= byte_n << (m << 3);
	x |= byte_m << (n << 3);
	return x;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int bit_sign = x >> 31;
	x = x >> (n + (~0));
	return !(x ^ bit_sign);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	return ~x + 0x01;
}
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	int bit_sign = x >> 31;
	return (!!x) | bit_sign;
}
//3
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	int add = x + y;
	int sign_x = x >> 31;
	int sign_y = y >> 31;
	int sign_add = add >> 31;
	return !((sign_x ^ sign_add) & (sign_add ^ sign_y));
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int bitMask(int highbit, int lowbit) {
	int min_1_8b = 0xFF;
	int min_1_16b = min_1_8b | min_1_8b << 8;
	int min_1_32b = min_1_16b | min_1_16b << 16;
	int one = ~min_1_32b + 0x01;
	return ~(min_1_32b << highbit << one) & (min_1_32b << lowbit);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int true_number = ((!!x) << 31) >> 31;
	return (true_number & y) + (z & ~true_number);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int zero8b = 0x00;
	int zero16b = zero8b << 8;
	int zero32b = zero16b << 16;
	int hexa30 = zero32b + 0x30;
	int hexa39 = zero32b + 0x39;
	int in_range = !((x + ~hexa30 + 1) >> 31) & !((hexa39 + ~x + 1) >> 31);
	return in_range;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	int diff = x + (~y + 1);
	int sign_x = (x >> 31) & 0x01;
	int sign_y = (y >> 31) & 0x01;
	int sign_diff = (diff >> 31) & 0x01;
	int same_sign = !(sign_x ^ sign_y);
	int equal = !!(x ^ y);
	return (((!sign_diff) & same_sign) & (equal)) | (sign_y & (!same_sign));
}
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
	x &= ~(0xFF << (n << 3));
	x |= c << (n << 3);
	return x;
}
//4
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	int sign_x = (x >> 31);
	int neg_x = ~x + 1; 
	return (neg_x & sign_x) | (x & ~sign_x);
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
	int zero_8b = 0x00;
	int zero_16b = zero_8b << 8;
	int zero_32b = zero_16b << 16;
	int one = zero_32b + 0x01;
	int comp_zero = ~(x | (~x+one));
	int msb_comp = comp_zero >> 31;
	return msb_comp & one;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {
	int zero_8b = 0x00;
	int zero_16b = zero_8b << 8;
	int zero_32b = zero_16b << 16;
	int one = zero_32b + 0x01;
	int comp_zero = x | (~x+one);
	int msb_comp = comp_zero >> 31;
	return msb_comp & one;
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
	int zero_8b = 0x00;
	int zero_16b = zero_8b << 8;
	int zero_32b = zero_16b << 16;
	int one = zero_32b + 0x01;
	int comp_zero = ~(x | (~x+one));
	int msb_comp = comp_zero >> 31;
	return msb_comp & one;
}
//float
/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
	unsigned exp = (uf >> 23) & 0xff;
	unsigned frac = uf << 9;
	if (exp == 0xff && frac != 0)
		return uf;
	return uf & 0x7fffffff;
}
/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
	unsigned exp_uf = uf & 0x7f800000;
	unsigned frac_uf = uf << 9;
	unsigned exp_ug = ug & 0x7f800000;
	unsigned frac_ug = ug << 9;
	if ((exp_uf == 0x7f800000 && frac_uf != 0) || (exp_ug == 0x7f800000 && frac_ug != 0))
		return 0;
	if (((uf & 0x7fffffff) == 0) & ((ug & 0x7fffffff) == 0))
		return 1;
	while (uf != 0 || ug != 0) {
		if ((uf & 0x80000000) != (ug & 0x80000000))
			return 0;
		uf <<= 0x1;
		ug <<= 0x1;
	}
	return 1;
}
/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
	unsigned exp = (uf >> 23) & 0xff;
	unsigned frac = uf << 9;
	unsigned neg_sign = uf ^ 0x80000000;
	if (exp == 0xff && frac != 0)
		return uf;
	return (uf & 0x7fffffff) | neg_sign;
}
/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
	unsigned exp_uf = uf & 0x7f800000;
	unsigned frac_uf = uf & 0x7fffff;
	unsigned exp_frac_uf = uf & 0x7fffffff;
	unsigned uf_sign = uf >> 31;
	unsigned exp_ug = ug & 0x7f800000;
	unsigned frac_ug = ug & 0x007fffff;
	unsigned exp_frac_ug = ug & 0x7fffffff;
	unsigned ug_sign = ug >> 31;
	if ((exp_uf == 0x7f800000 && frac_uf != 0) || (exp_ug == 0x7f800000 && frac_ug != 0))
		return 0;
	if (exp_frac_uf == 0 && exp_frac_ug == 0)
		return 0;
	if (uf_sign != ug_sign)
		return (uf_sign > ug_sign);
	if ((exp_uf != exp_ug)) {
		if (uf_sign == 1)
			return exp_uf > exp_ug;
		else
			return exp_uf < exp_ug;
	}
	if (uf_sign == 1)
		return frac_uf > frac_ug;
	return frac_uf < frac_ug;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned exp = uf & 0x7f800000;
    	unsigned frac = uf & 0x007FFFFF;
	unsigned minus_one = 0xFFFFFFFF;
	unsigned sign_exp = uf & 0xff800000;
  	int shift = (exp >> 23) - 127 - 23;
	unsigned exp_4_msb = exp & 0x78000000;
    	if (exp_4_msb == 0x78000000) {
    		return 0x80000000u;
  	}
	if (shift < 0) {
		shift = -shift;
	}
	minus_one <<= shift;
	frac &= minus_one;
  	if (uf == 0 || uf == 0x80000000 || (frac == 0 && exp != 0x3f800000) || exp == 0) {
   		return 0x0;
  	}
	frac |= sign_exp;
	if (frac == 0x3f800000)
		return 0x1;
	if (frac == 0xbf800000)
		return 0xffffffff;
    	return frac;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	unsigned INF = 0x7F800000;
    	unsigned result = ((x + 127) << 23);
	if (x < -126)
		return 0x0;
	if (x > 127)
		return INF;
    	return result;
}
