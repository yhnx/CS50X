#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Invalid command-line arguement \n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *aud = fopen(argv[1], "rb");
    if (aud == NULL)
    {
        printf("File doesnt exist \n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER waveheader;
    fread(&waveheader, sizeof(WAVHEADER), 1, aud);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(waveheader) == 0)
    {
        printf("Invalid file format");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outfile = fopen(argv[2], "wb");

    // Write header to file
    // TODO #6
    fwrite(&waveheader, sizeof(WAVHEADER), 1, outfile);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(waveheader);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];
    fseek(aud, block_size, SEEK_END);
    while (ftell(aud) - block_size > sizeof(waveheader))
    {
        fseek(aud, -2 * block_size, SEEK_CUR);
        fread(buffer, block_size, 1, aud);
        fwrite(buffer, block_size, 1, outfile);
    }

    fclose(outfile);
    fclose(aud);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if ((header.format[0] == 'W') && (header.format[1] == 'A') && (header.format[2] == 'V') && (header.format[3] == 'E'))
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}
