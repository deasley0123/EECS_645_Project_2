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

#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include "ALUSimulator.h"

//
// Simulate all ALU functions (all uint32_t values use bottom bits)
//
extern void ALUSimulator(   RegisterFile theRegisterFile,
                            uint32_t OpCode, // 6 bits
                            uint32_t Rs, uint32_t Rt, uint32_t Rd,
                            uint32_t ShiftAmt, // 5 bits
                            uint32_t FunctionCode,
                            uint32_t ImmediateValue,
                            uint32_t* Status ){ //Carry/borrow (0x4), negative (0x2), zero (0x1)

    switch(OpCode){
        case 0x00 :
            switch(FunctionCode){
                case 0x00 :
                    SLL(theRegisterFile, Rs, Rt, Rd, ShiftAmt);
                    break;
                case 0x02 :
                    SRL(theRegisterFile, Rs, Rt, Rd, ShiftAmt);
                    break;
                case 0x03 :
                    SRA(theRegisterFile, Rs, Rt, Rd, ShiftAmt);
                    break;
                case 0x04 :
                    SLLV(theRegisterFile, Rs, Rt, Rd, ShiftAmt);
                    break;
                case 0x06 :
                    SRLV(theRegisterFile, Rs, Rt, Rd, ShiftAmt);
                    break;
                case 0x20 :
                    ADD(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x21 :
                    ADDU(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x22 :
                    SUB(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x23 :
                    SUBU(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x24 :
                    AND(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x25 :
                    OR(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x26 :
                    XOR(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x2A :
                    SLT(theRegisterFile, Rs, Rt, Rd);
                    break;
                case 0x2B :
                    SLTU(theRegisterFile, Rs, Rt, Rd);
                    break;

                default :
                    printf("Unknown FunctionCode selected!");
            }
            break;
        case 0x08 :
            ADDI(theRegisterFile, Rs, Rd, ImmediateValue);
            break;
        case 0x09 :
            ADDIU(theRegisterFile, Rs, Rd, ImmediateValue);
            break;
        case 0x0A :
            SLTI(theRegisterFile, Rs, Rd, ImmediateValue);
            break;
        case 0x0B :
            SLTIU(theRegisterFile, Rs, Rd, ImmediateValue);
            break;

        default :
            printf("Unknown OpCode selected!");

    }
}

//
// Shift Word Left Logical, OpCode 0x00, FunctionCode 0x00
//
void SLL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt){
              uint32_t RdVal = Rt << ShiftAmt;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Shift Word Right Logical, OpCode 0x00, FunctionCode 0x02
//
void SRL(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt){
            uint32_t RdVal = Rt >> ShiftAmt;
            RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);

}

//
// Shift Word Right Arithmetic, OpCode 0x00, FunctionCode 0x03
//
void SRA(   RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt){
              uint32_t RdVal = (signed)Rt >> ShiftAmt;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);

}

//
// Shift Word Left Logical Variable, OpCode 0x00, FunctionCode 0x04
//
void SLLV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt){
              uint32_t RdVal = Rt << Rs;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);

}

//
// Shift Word Right Logical Variable, OpCode 0x00, FunctionCode 0x06
//
void SRLV(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd,
            uint32_t ShiftAmt){
              uint32_t RdVal = Rt >> Rs;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);

}

//
// Add Word, OpCode 0x00, FunctionCode 0x20
//
void ADD(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){
              uint32_t RdVal = Rs + Rt;
              //TODO: overflow case
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Add Unsigned Word, OpCode 0x00, FunctionCode 0x21
//
void ADDU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){
              uint32_t RdVal = Rs + Rt;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);

}

//
// Subtract Word, OpCode 0x00, FunctionCode 0x22
//
void SUB(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = Rs - Rt;
              //TODO: overflow case
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Subtract Unsigned Word, OpCode 0x00, FunctionCode 0x23
//
void SUBU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = Rs - Rt;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Boolean "and" operation, OpCode 0x00, FunctionCode 0x24
//
void AND(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = Rs & Rt;
              RegisterFile_Write(theRegisterFile, 1, Rd, Rdvalue);
}

//
// Boolean "or" operation, OpCode 0x00, FunctionCode 0x25
//
void OR(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = Rs | Rt;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Boolean "xor" operation, OpCode 0x00, FunctionCode 0x26
//
void XOR(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = Rs ^ Rt;
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Set on Less Than, OpCode 0x00, FunctionCode 0x2A
//
void SLT(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = 0;
              if(Rs < Rt){
                  RdVal = 1;
               }
               else{
                  RdVal = 0;
               }
               RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Set on Less Than Unsigned, OpCode 0x00, FunctionCode 0x2B
//
void SLTU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rt, uint32_t Rd){

              uint32_t RdVal = 0;
              if((unsigned)Rs < (unsigned)Rt){
                    RdVal = 1;
              }
              else{
                    RdVal = 0;
              }
              RegisterFile_Write(theRegisterFile, 1, Rd, RdVal);
}

//
// Add Immediate Word, OpCode 0x08, FunctionCode (don't care)
//
void ADDI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue){

              uint32_t RdVal = Rs + ImmediateValue;
              //TODO: overflow
              RegisterFile_Write(theRegisterFile, 1, Rt, RdVal);
}

//
// Add Immediate Unsigned Word, OpCode 0x09, FunctionCode (don't care)
//
void ADDIU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue){

              uint32_t RdVal = Rs + ImmediateValue;
              RegisterFile_Write(theRegisterFile, 1, Rt, RdVal);
}

//
// Set on Less Than Immediate, OpCode 0x0A, FunctionCode (don't care)
//
void SLTI(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue){

              uint32_t RdVal = 0;
              if(Rs < ImmediateValue){
                  RdVal = 1;
              }
              else{
                  RdVal = 0;
              }
              RegisterFile_Write(theRegisterFile, 1, Rt, RdVal);
}

//
// Set on Less Than Immediate Unsigned, OpCode 0x0B, FunctionCode (don't care)
//
void SLTIU(  RegisterFile theRegisterFile,
            uint32_t Rs, uint32_t Rd,
            uint32_t ImmediateValue){

              uint32_t RdVal = 0;
              if((unsigned)Rs < (unsigned)ImmediateValue){
                  RdVal = 1;
              }
              else{
                  RdVal = 0;
              }
              RegisterFile_Write(theRegisterFile, 1, Rt, RdVal);
}
