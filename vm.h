#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

typedef struct {
    Chunk* chunk;
    uint8_t* ip; // basically the you are here marker stands for instruction pointer basically program counter pc
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILER_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk* chunk);

#endif