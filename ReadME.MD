# Modulus Calculator Library

> High-performance modular arithmetic implementations using WebAssembly for cryptographic and mathematical computations.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 📌 Overview

This library provides efficient implementations of modular arithmetic operations, optimized through WebAssembly for maximum performance.

## 🔗 Live Demo

Try out the live implementation: [RemainderX](https://remainderx.onrender.com)

## 🔧 Core Implementations

### Modular Exponentiation

```c
// Efficient implementation using square-and-multiply algorithm
#include <stdint.h>
#include <emscripten.h>

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
```

### Basic Modulus Operation

```c
// Simple and efficient modulus calculation
EMSCRIPTEN_KEEPALIVE
uint64_t mod_calc(uint64_t a, uint64_t m) {
    return a % m;
}
```

## ⚡ Performance Analysis

### Time Complexity

| Operation              | Time Complexity | Space Complexity |
| ---------------------- | --------------- | ---------------- |
| Modular Exponentiation | O(log n)        | O(1)             |
| Basic Modulus          | O(1)            | O(1)             |

### Benchmark Results

| Operation              | JavaScript | WebAssembly | Improvement |
| ---------------------- | ---------- | ----------- | ----------- |
| Modular Exponentiation | 1.0x       | ~2-3x       | Up to 200%  |
| Basic Modulus          | 1.0x       | ~1.5-2x     | Up to 100%  |

## 🚀 WebAssembly Integration

### Key Benefits

- **Performance**: Near-native execution speed
- **Security**: Protected memory space
- **Portability**: Cross-platform compatibility

### Usage Example

```javascript
// Initialize WebAssembly module
WebAssembly.instantiateStreaming(fetch("mod_exp.wasm")).then((obj) => {
  // Calculate (2^3) % 5
  const result = obj.instance.exports.mod_exp(2n, 3n, 5n);
  console.log(result); // Output: 3
});
```

## 🛠️ Building from Source

1. **Prerequisites**

   - Emscripten SDK
   - Modern C compiler
   - Node.js (optional, for testing)

2. **Compilation**
   ```bash
   # Compile with optimization level 3
   emcc src/mod_exp.c -o dist/mod_exp.wasm \
       -O3 \
       -s EXPORTED_FUNCTIONS='["_mod_exp", "_mod_calc"]' \
       -s ENVIRONMENT='web'
   ```

## 📚 Use Cases

- ✅ Cryptographic computations
- ✅ Number theory applications
- ✅ High-performance mathematical operations
- ✅ Real-time data processing

## 🔍 Technical Requirements

- Modern web browser with WebAssembly support (Chrome 57+, Firefox 52+, Safari 11+)
- Emscripten toolchain for compilation
- C11 compatible compiler

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

---
