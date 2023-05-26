// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef int16_t sample_type;
typedef uint8_t header_type;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    header_type header[HEADER_SIZE];
    
    fread(header, sizeof(header_type), HEADER_SIZE, input);
    fwrite(header, sizeof(header_type), HEADER_SIZE, output);
    
    
    // TODO: Read samples from input file and write updated data to output file
    sample_type buffer;

    
    
    while ((fread(&buffer, sizeof(sample_type), 1, input)) != 0)
    {
        buffer = (float) buffer * factor;
        fwrite(&buffer, sizeof(sample_type), 1, output);
        // printf(".");
    }
    
    
    // Close files
    fclose(input);
    fclose(output);
}
