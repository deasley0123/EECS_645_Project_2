//  Created by David A. Easley on 4/25/2017.
//  Copyright 2017 David A. Easley. All rights reserved.
//
//  Updates:
//
//      -- initial version
//      -- Upadated May 1st by David Easley
//          revisions to reflect requriement changes (5/1/2017)
//
//	Description:
//			This program simulates an ALU that interacts with a provided register file.
//

#ifndef __ALUSimulator_H_
#define __ALUSimulator_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include "RegisterFile_01.h"

//
// Simualte all ALU functions (all uint32_t values use bottom bits)
//
extern void ALUSimulator(   RegisterFile theRegisterFile,
                            uint32_t OpCode, // 6 bits
                            uint32_t Rs, uint32_t Rt, uint32_t Rd,
                            uint32_t ShiftAmt, // 5 bits
                            uint32_t FunctionCode,
                            uint32_t ImmediateValue,
                            uint32_t* Status ); //Carry/borrow, negative, zero


//
// Shift Word Left Logical, OpCode 0x00, FunctionCode 0x00
//
void SLL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Logical, OpCode 0x00, FunctionCode 0x02
//
void SRL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Arithmetic, OpCode 0x00, FunctionCode 0x03
//
void SRA(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Left Logical Variable, OpCode 0x00, FunctionCode 0x04
//
void SLLV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Logical Variable, OpCode 0x00, FunctionCode 0x06
//
void SRLV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Add Word, OpCode 0x00, FunctionCode 0x20
//
void ADD(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Add Unsigned Word, OpCode 0x00, FunctionCode 0x21
//
void ADDU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Subtract Word, OpCode 0x00, FunctionCode 0x22
//
void SUB(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Subtract Unsigned Word, OpCode 0x00, FunctionCode 0x23
//
void SUBU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Boolean "and" operation, OpCode 0x00, FunctionCode 0x24
//
void AND(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Boolean "or" operation, OpCode 0x00, FunctionCode 0x25
//
void OR(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Boolean "xor" operation, OpCode 0x00, FunctionCode 0x26
//
void XOR(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Set on Less Than, OpCode 0x00, FunctionCode 0x2A
//
void SLT(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Set on Less Than Unsigned, OpCode 0x00, FunctionCode 0x2B
//
void SLTU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Add Immediate Word, OpCode 0x08, FunctionCode (don't care)
//
void ADDI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);

//
// Add Immediate Unsigned Word, OpCode 0x09, FunctionCode (don't care)
//
void ADDIU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);

//
// Set on Less Than Immediate, OpCode 0x0A, FunctionCode (don't care)
//
void SLTI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);

//
// Set on Less Than Immediate Unsigned, OpCode 0x0B, FunctionCode (don't care)
//
void SLTIU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);


#endif		// __RegisterFile_H_
