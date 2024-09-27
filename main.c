#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "v22.h"

void readspecs(userinput_t *, char *, char *);
void outputfilename(char *);
void keyconvert(struct secretkeybits, int *);
void fileprocess(int, FILE *, FILE *);
char outputfile[25];

int main(int argc, char *argv[]) {
  //char inputfile[21]; //inputfile array holds the input file name, 21st character is null byte

  userinput_t inputval;
  //struct secretkeybits seckey;
  if (argc == 3) {
    readspecs(&inputval, argv[1], argv[2]); //readspecs reads and validates the value of the key, filename
  }
  else {
    printf("Invalid number of command-line arguments!\n");
    exit(1);
  }
  outputfilename(inputval.inputfile); //outputfilename is a copy of the inputfile with/without the .enc
  printf("Output filename: %s\n", outputfile);
  int *keyint = (int *) malloc(8 * sizeof(int));
  if (keyint == NULL) {
    fprintf(stderr, "Malloc error!\n");
    exit(1);
  }
  /* keyconvert converts key temporary char array to a pointer to a number holding decimal version of that binary number */
  keyconvert(inputval.seckey, keyint);
  //FILE *in;
  FILE *out;
  FILE *in = fopen(inputval.inputfile, "r");
  if (in == NULL) { //ensuring no error occurs while opening inputfile to read from
    fprintf(stderr, "Error opening the input file!");
    exit(1);
  }
  out = fopen(outputfile, "w");
  if (out == NULL) { //ensuring no error occurs while opening outputfile to write to
    fclose(in);
    in = NULL;
    fprintf(stderr, "Error opening the output file!");
    exit(1);
  }
  fileprocess(keyint[0], in, out); //fileprocess encrypts the inputfile into its outputfile
  free(keyint); //freeing up all memory dynamically allocated
  fclose(in);
  fclose(out);
  in = NULL;
  out = NULL; //closing all file pointers and ensuring they don't accidentally point to unaccessible memory is crucial
}
