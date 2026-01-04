#ifndef clox_common_h
#define clox_common_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// --- DEBUGGING FLAGS ---
// Uncomment these to see what your VM is doing inside!

// 1. Prints the bytecode instructions when you compile
#define DEBUG_PRINT_CODE

// 2. Prints the stack and current instruction while running
#define DEBUG_TRACE_EXECUTION

#endif