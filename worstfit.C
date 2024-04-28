#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000

// Structure to represent a memory block
typedef struct MemoryBlock {
    int start_address;
    int size;
    int allocated;
} MemoryBlock;

// Function to initialize memory blocks
void initializeMemory(MemoryBlock *memory, int num_blocks) {
    for (int i = 0; i < num_blocks; i++) {
        memory[i].start_address = 0;
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

// Function to display memory blocks
void displayMemory(MemoryBlock *memory, int num_blocks) {
    printf("Memory Blocks:\n");
    printf("Start Address | Size | Allocated\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("%14d | %4d | %9s\n", memory[i].start_address, memory[i].size, memory[i].allocated ? "Yes" : "No");
    }
}

// Function to allocate memory using worst fit strategy
void allocateMemoryWorstFit(MemoryBlock *memory, int num_blocks, int request_size) {
    int worst_fit_index = -1;
    int max_size = 0;
    
    // Find the largest available block
    for (int i = 0; i < num_blocks; i++) {
        if (!memory[i].allocated && memory[i].size >= request_size && memory[i].size > max_size) {
            worst_fit_index = i;
            max_size = memory[i].size;
        }
    }
    
    // Allocate memory if a block is found
    if (worst_fit_index != -1) {
        memory[worst_fit_index].allocated = 1;
        printf("Memory allocated at address %d for request of size %d\n", memory[worst_fit_index].start_address, request_size);
    } else {
        printf("Memory allocation failed for request of size %d\n", request_size);
    }
}

int main() {
    MemoryBlock memory[MEMORY_SIZE];
    int num_blocks, request_size;

    // Initialize memory
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);
    initializeMemory(memory, num_blocks);

    // Input memory blocks
    printf("Enter the memory blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &memory[i].size);
        memory[i].start_address = i * 100; // Assuming block size is multiple of 100 for simplicity
    }

    // Display initial memory state
    displayMemory(memory, num_blocks);

    // Allocate memory using worst fit strategy
    printf("\nEnter the size of memory request: ");
    scanf("%d", &request_size);
    allocateMemoryWorstFit(memory, num_blocks, request_size);

    // Display memory state after allocation
    displayMemory(memory, num_blocks);

    return 0;
}
