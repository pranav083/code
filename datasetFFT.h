#ifndef DATASET_H
#define DATASET_H

#include <stdlib.h>

#define DATA_SIZE 1024  // Define the size of the dataset

// Function to generate a random dataset
void generate_dataset(unsigned char *dataset, size_t size) {
    for (size_t i = 0; i < size; i++) {
        dataset[i] = (rand() % 94) + 32;  // Generate random ASCII printable characters (32 to 126)
    }
}

#endif // DATASET_H
