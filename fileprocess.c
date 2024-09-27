#include <stdio.h>

void fileprocess(int key, FILE * in, FILE * out) { //encrypts inputfile, writes encrypted version of it to outputfile
  int c;
  while ((c = fgetc(in)) != EOF) { //reads in all characters one-by-one from inputfile
    c = c ^ key; //this is the encryption process (also the decryption process)
    fputc(c, out); //writing to output file
  }

}
