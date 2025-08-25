#include <stdio.h>      // stdio: for printf/scanf
#include <stdint.h>     // stdint: for fixed-width integer types like int32_t, int64_t

#define SCALE (1 << 16) // Constant scale factor = 2^16 = 65536 (Q16.16 fixed-point format)

typedef int32_t fixed;  // Our fixed-point type is a signed 32-bit integer

// Convert a floating-point number to fixed-point (scale up by 2^16)
fixed toFixed(double x)   { return (fixed)(x * SCALE); }

// Convert fixed-point back to floating-point (scale down by 2^16)
double toDouble(fixed x)  { return (double)x / SCALE; }

// Fixed-point add: same as integer add because both operands share the same scale
fixed fadd(fixed a, fixed b) { return a + b; }

// Fixed-point subtract: same as integer subtract for the same reason
fixed fsub(fixed a, fixed b) { return a - b; }

// Fixed-point multiply:
// (a and b are Q16.16). The product a*b is Q32.32 in a 64-bit temp, then >>16 to return to Q16.16.
fixed fmul(fixed a, fixed b) { return (fixed)(((int64_t)a * b) >> 16); }

// Fixed-point divide:
// To keep precision, shift the numerator left by 16 (Q16.16 << 16 => Q32.16) then divide by b => Q16.16.
fixed fdiv(fixed a, fixed b) { return (fixed)(((int64_t)a << 16) / b); }

int main() {
    double x, y;         // Read user inputs as doubles for convenience
    char op;             // Operator: +, -, *, or /

    printf("Enter expression (<num> <op> <num>): ");               // Prompt
    if (scanf("%lf %c %lf", &x, &op, &y) != 3) {                   // Read "num op num"
        printf("Invalid input\n");                                 // If not exactly 3 tokens, bail out
        return 1;
    }

    fixed a = toFixed(x), b = toFixed(y), result;                  // Convert inputs to Q16.16

    switch (op) {                                                  // Dispatch by operator
        case '+': result = fadd(a, b); break;                      // Add
        case '-': result = fsub(a, b); break;                      // Subtract
        case '*': result = fmul(a, b); break;                      // Multiply (with 64-bit temp + shift)
        case '/': result = fdiv(a, b); break;                      // Divide (shift left then divide)
        default:
            printf("Unknown operator\n");                          // Any other char is invalid
            return 1;
    }

    printf("Result = %.6f\n", toDouble(result));                   // Convert back to double and print
    return 0;                                                      // Normal exit
}

//had to take help with this one. This looks so complicated.
