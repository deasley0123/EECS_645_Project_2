//  Created by David A. Easley on 4/25/2017.
//  Copyright 2017 David A. Easley. All rights reserved.
//
//  Updates:
//
//      -- initial version
//
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
// Shift Word Left Logical
//
void SLL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Logical
//
void SRL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);
                
//
// Shift Word Right Logical
//
void SRL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Arithmetic
//
void SRA(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Logical
//
void SRL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Left Logical Variable
//
void SLLV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Shift Word Right Logical Variable
//
void SRLV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt);

//
// Move From HI
//
void MFHI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Move From LO
//
void MFLO(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Multiply Word
//
void MULT(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Mulitply Unsigned Word
//
void MULTU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Divide Word
//
void DIV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Divide Unsigned Word
//
void DIVU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Add Word
//
void ADD(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Add Unsigned Word
//
void ADDU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Subtract Word
//
void SUB(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Subtract Unsigned Word
//
void SUBU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Boolean "and" operation
//
void AND(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Boolean "or" operation
//
void OR(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Boolean "xor" operation
//
void XOR(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Set on Less Than
//
void SLT(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Set on Less Than Unsigned
//
void SLTU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd);

//
// Add Immediate Word
//
void ADDI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);

//
// Add Immediate Unsigned Word
//
void ADDIU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);

//
// Set on Less Than Immediate
//
void SLTI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);

//
// Set on Less Than Immediate Unsigned
//
void SLTIU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue);


#endif		// __RegisterFile_H_