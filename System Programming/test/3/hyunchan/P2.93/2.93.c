/* CS201, Problem # 2.93
   Hyunchan Kim
*/

// Compute 2*f. If f is Nan, then return f.
// For floating-point number f, this function computes 2.0*f. If f is NaN, your function
// should return f.

#include <stdio.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) 
{
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned fraction = f & 0x7fffff;

	printf("sign = %x\r\n", sign);
        printf("exp = %x\r\n", exp);
        printf("frac = %x\r\n", fraction);

	if (exp == 0xff) //NaN
		return f;
	if (exp == 0)  //+oo
	{  
		exp += fraction << 1 >> 23;
		fraction = (fraction << 1);
	}
	else if (exp != 0xff) //-oo
		++exp;

	if (exp == 0xff)  // 0
		fraction = 0;

	return (sign << 31) | (exp << 23) | fraction;
}

int main() 
{
	unsigned u, ur;
	float f, fr;
	for (u = 0; u <= 0xffffffffu; u++)
	{
		f = *((float *) &u);
		f = f * 2.0;
		ur = float_twice(u);
		fr = *((float *) &ur);
		if (fr == f)
			printf("%u: %x 0x%x \n\n", u, f, fr);
		else
		{
			printf("%u error\n", u);
			printf("%x %x\n", f, fr);
			return -1;
		}

	}
}
