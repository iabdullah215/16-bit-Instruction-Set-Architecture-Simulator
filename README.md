# 16-bit-Instruction-Set-Architecture-Simulator

# ISA Simulator

This C++ code simulates a simple Instruction Set Architecture (ISA) processor. Let's break down the code and understand its components and functionality.

## Constants
Several constants are defined at the beginning, including `MEMORY_SIZE` for the size of the memory, `REGISTER_COUNT` for the number of registers, and various opcode constants representing different instructions.

## Class `ISA_Simulator`
This class represents the ISA simulator.
- Private member variables:
  - `memory`: A vector representing the memory of the simulated ISA machine.
  - `registers`: A vector representing the registers of the simulated ISA machine.
  - `pc`: An integer representing the program counter.
- Public member functions:
  - `ISA_Simulator()`: The constructor that initializes memory, registers, and the program counter.
  - `void loadProgram(const std::vector<short>& program)`: Loads a program into the memory.
  - `void run()`: Executes the loaded program.
  - `void printMemory() const`: Prints the content of the memory.
  - `void printRegisters() const`: Prints the content of the registers.

## `loadProgram` Function
Loads the given program into the memory.

## `run` Function
Executes the loaded program by iterating through memory instructions.
- Fetches each instruction from memory, extracts the opcode and operand, and performs the corresponding operation.
- The loop continues until the program counter reaches the end of the memory or a halt instruction is encountered.

## `printMemory` Function
Prints the content of the memory in hexadecimal format.

## `printRegisters` Function
Prints the content of the registers.

## `main` Function
Creates an instance of `ISA_Simulator`.
Defines an example program using opcode constants and operand values.
Loads the program into the simulator, runs it, and then prints the memory and registers after execution.

## Example Program
The example program loads values from memory into registers, adds them, stores the result in memory and a register, and then halts.
Each instruction in the program is represented by a short integer where the opcode occupies the upper 8 bits and the operand occupies the lower 8 bits.

This code provides a basic framework for simulating an ISA processor with a limited set of instructions and capabilities. It can be extended further to support additional instructions and features as needed.
