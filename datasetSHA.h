#ifndef DATASET_H
#define DATASET_H

#define DATA_SIZE 1024  // Define the size of the dataset

// // Random ASCII characters dataset for benchmarking
// unsigned char dataset[DATA_SIZE] = {
//     84,  104, 105, 115, 32, 105, 115, 32, 97, 32, 116, 101, 115, 116, 32, 100, 
//     97,  116, 97,  32, 102, 111, 114, 32, 83, 72, 65,  45,  50, 53,  54, 46, 
//     84,  104, 105, 115, 32, 105, 115, 32, 97, 32, 108, 97, 114, 103, 101, 114, 
//     32, 100, 97, 116, 97, 32, 115, 101, 116, 32, 116, 111, 32, 115, 116, 114,
//     101, 115, 115, 32, 116, 104, 101, 32, 83, 72, 65, 45, 50, 53, 54, 32, 105, 
//     109, 112, 108, 101, 109, 101, 110, 116, 97, 116, 105, 111, 110, 46, 32, 73, 
//     116, 32, 105, 115, 32, 99, 114, 101, 97, 116, 101, 100, 32, 116, 111, 32, 
//     115, 105, 109, 117, 108, 97, 116, 101, 32, 118, 97, 114, 105, 111, 117, 115, 
//     32, 105, 110, 112, 117, 116, 32, 99, 97, 115, 101, 115, 46, 46, 46,  // Continue or generate dynamically...
// };
// Function to generate a random dataset
void generate_dataset(unsigned char *dataset, size_t size) {
    for (size_t i = 0; i < size; i++) {
        dataset[i] = (rand() % 94) + 32;  // Generate random ASCII printable characters (32 to 126)
    }
}
#endif // DATASET_H
