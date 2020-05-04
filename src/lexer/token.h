//
// Created by ariel.simulevski on 04.05.20.
//

#ifndef HADESLANG_TOKEN_H
#define HADESLANG_TOKEN_H

#include <stdint.h>

const uint8_t TOKEN_IDENTIFER = 0x0;
const uint8_t TOKEN_VAR = 0x1;
const uint8_t TOKEN_ASSIGN = 0x2;
const uint8_t TOKEN_COMPOUND_ASSIGN = 0x3;
const uint8_t TOKEN_TYPE_FUN = 0x;
const uint8_t TOKEN_TYPE_U8 = 0x;
const uint8_t TOKEN_TYPE_I8 = 0x;
const uint8_t TOKEN_TYPE_U16 = 0x;
const uint8_t TOKEN_TYPE_I16 = 0x;
const uint8_t TOKEN_TYPE_U32 = 0x;
const uint8_t TOKEN_TYPE_I32 = 0x;
const uint8_t TOKEN_TYPE_U64 = 0x;
const uint8_t TOKEN_TYPE_I64 = 0x;
const uint8_t TOKEN_TYPE_F32 = 0x;
const uint8_t TOKEN_TYPE_F64 = 0x;
const uint8_t TOKEN_TYPE_BOOL = 0x;

struct token {
    char * value;
    uint8_t type;
};

#endif //HADESLANG_TOKEN_H
