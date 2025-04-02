// #include <stdint.h>

// // Modular exponentiation function: (base^exp) % mod
// uint32_t mod_exp(uint32_t base, uint32_t exp, uint32_t mod) {
//     uint32_t result = 1;
//     base = base % mod;
    
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         exp = exp >> 1;
//         base = (base * base) % mod;
//     }
    
//     return result;
// }
#include <stdint.h>
#include <math.h>
#include <emscripten.h>  // ✅ Required for EMSCRIPTEN_KEEPALIVE

// ✅ Ensure function is exported properly
EMSCRIPTEN_KEEPALIVE
uint64_t mod_exp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp & 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;  // Right shift: exp = exp / 2
    }

    return result;
}

