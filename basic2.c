
#include <stdio.h>

int main() {
    float f = 1.0 / 3.0;      // single precision
    double d = 1.0 / 3.0;     // double precision

    // Print with different precision
    printf("Float  (6 decimal places): %.6f\n", f);
    printf("Double (6 decimal places): %.6lf\n", d);

    printf("Float  (15 decimal places): %.15f\n", f);
    printf("Double (15 decimal places): %.15lf\n", d);

    return 0;
}
// Explanation

// float (single precision) usually takes 4 bytes (32 bits).

// 1 bit sign, 8 bits exponent, 23 bits mantissa → about 6–7 decimal digits of precision.

// double (double precision) usually takes 8 bytes (64 bits).

// 1 bit sign, 11 bits exponent, 52 bits mantissa → about 15–16 decimal digits of precision.

// 👉 That’s why float starts losing accuracy after ~7 digits, while double remains accurate up to ~15 digits.
// If asked “Why should we prefer double over float?”

// Float → saves memory, faster on some architectures (good for graphics, ML models on GPUs).

// Double → more precision, useful for scientific calculations and finance.