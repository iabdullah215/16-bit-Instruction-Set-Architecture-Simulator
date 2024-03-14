#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
// Define constants
const int MEMORY_SIZE = 256;
const int REGISTER_COUNT = 8;

// Define instruction opcodes
const int OP_ADD = 0x01;
const int OP_SUB = 0x02;
const int OP_MUL = 0x03;
const int OP_STORE_REG1 = 0x04;
const int OP_STORE_REG2 = 0x05;
const int OP_STORE_REG3 = 0x06;
const int OP_STORE_REG4 = 0x07;
const int OP_STORE_REG5 = 0x08;
const int OP_STORE_REG6 = 0x09;
const int OP_STORE_REG7 = 0x0A;
const int OP_STORE_REG8 = 0x0B;
const int OP_LOAD_REG1 = 0x0C;
const int OP_LOAD_REG2 = 0x0D;
const int OP_LOAD_REG3 = 0x0E;
const int OP_LOAD_REG4 = 0x0F;
const int OP_LOAD_REG5 = 0x10;
const int OP_LOAD_REG6 = 0x11;
const int OP_LOAD_REG7 = 0x12;
const int OP_LOAD_REG8 = 0x13;

const int OP_HALT = 0xFF;

class ISA_Simulator {
private:
    vector<short> memory; // Memory unit
    vector<short> registers; // Registers
    int pc; // Program counter

public:
    ISA_Simulator() {
        // Initialize memory with zeros
        memory.resize(MEMORY_SIZE, 0);

        // Initialize registers with zeros
        registers.resize(REGISTER_COUNT, 0);

        // Initialize program counter
        pc = 0;
    }

    void loadProgram(const std::vector<short>& program) {
        // Load program into memory
        for (int i = 0; i < program.size(); ++i) {
            memory[i] = program[i];
        }
    }

    void run() {
    while (pc < MEMORY_SIZE) {
        short instruction = memory[pc++]; // Fetch instruction
        int opcode = instruction >> 8; // Extract opcode
        int operand = instruction & 0xFF; // Extract operand

        switch (opcode) {
            case OP_ADD:
                registers[0] = registers[operand] + registers[operand + 1]; // ADD
                break;
            case OP_SUB:
                registers[0] = registers[operand] - registers[operand + 1]; // SUB
                break;
            case OP_STORE_REG1:
            case OP_STORE_REG2:
            case OP_STORE_REG3:
            case OP_STORE_REG4:
            case OP_STORE_REG5:
            case OP_STORE_REG6:
            case OP_STORE_REG7:
            case OP_STORE_REG8:
                registers[operand] = registers[0]; // STORE value in the specified register
                break;
            case OP_LOAD_REG1:
            case OP_LOAD_REG2:
            case OP_LOAD_REG3:
            case OP_LOAD_REG4:
            case OP_LOAD_REG5:
            case OP_LOAD_REG6:
            case OP_LOAD_REG7:
            case OP_LOAD_REG8:
                registers[operand] = memory[registers[operand]]; // LOAD value from memory into the specified register
                break;
            case OP_HALT:
                cout << "Halt instruction encountered. Program terminated.\n";
                return;
            default:
                cerr << "Unknown opcode encountered. Exiting.\n";
                return;
        }
    }
    cout << "End of program. Program counter reached end of memory.\n";
}


    void printMemory() const {
        cout << "Memory:\n";
        for (int i = 0; i < MEMORY_SIZE; ++i) {
            cout << hex << setw(4) << setfill('0') << memory[i] << " ";
            if ((i + 1) % 16 == 0) cout << endl;
        }
        cout << endl;
    }

    void printRegisters() const {
        cout << "Registers:\n";
        for (int i = 0; i < REGISTER_COUNT; ++i) {
            cout << "R" << i << ": " << registers[i] << endl;
        }
        cout << endl;
    }
};
int main() 
{
  ISA_Simulator simulator;

  // Example program: Load values into registers, add them, and store the result in memory and register 3
  vector<short> program = {
      (OP_LOAD_REG1 << 8) | 10,  // Load value from memory location 10 into register 1
      (OP_LOAD_REG2 << 8) | 20,  // Load value from memory location 20 into register 2
      (OP_ADD << 8),             // Add values in registers 1 and 2
      (OP_STORE_REG3 << 8) | 3,  // Store result (in ALU) into register 3 
      (OP_STORE_REG1 << 8) | 30, // Store original value in register 1 to memory location 30
      (OP_STORE_REG2 << 8) | 40, // Store original value in register 2 to memory location 40
       // Halt (OP_HALT << 8)
  };

  simulator.loadProgram(program);
  simulator.run();
  simulator.printMemory();
  simulator.printRegisters();

  return 0;
}
