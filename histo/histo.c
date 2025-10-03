#include <stdio.h>
#include <stdlib.h>

#define NUM_BINS 16

int main() {
    int bins[NUM_BINS];
    int bin_size = 1;
    int max_range = NUM_BINS;
    int num;
    
    // Initialize all bins to 0
    for (int i = 0; i < NUM_BINS; i++) {
        bins[i] = 0;
    }
    
    printf("%d bins of size %d for range [0,%d)\n", NUM_BINS, bin_size, max_range);
    
    while (scanf("%d", &num) == 1) {
        if (num < 0) {
            continue;
        }
        
        // Chec if in range
        while (num >= max_range) {
            bin_size *= 2;
            max_range *= 2;
            
            for (int i = 0; i < NUM_BINS / 2; i++) {
                bins[i] = bins[i * 2] + bins[i * 2 + 1];
            }
            
            for (int i = NUM_BINS / 2; i < NUM_BINS; i++) {
                bins[i] = 0;
            }
            
            printf("%d bins of size %d for range [0,%d)\n", NUM_BINS, bin_size, max_range);
        }
        
        int bin_index = num / bin_size;
        bins[bin_index]++;
    }
    
    // Print 
    for (int i = 0; i < NUM_BINS; i++) {
        int low = i * bin_size;
        int high = (i + 1) * bin_size - 1;
        
        printf("[%3d:%3d] ", low, high);
        
        // Print stars 
        for (int j = 0; j < bins[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
