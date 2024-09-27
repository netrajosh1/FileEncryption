#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char outputfile[25]; //global variable, can be accessed from any file as long as "extern"

void outputfilename(char *inputfile) {
  char *last_four;
  last_four = &inputfile[strlen(inputfile) - 4]; //puts the last 4 characters of inputfile in last_four
  if (strcmp(last_four, ".enc") == 0) { //if .enc in inputfilename, outputfilename = inputfilename - .enc
    strcpy(outputfile, inputfile);
    outputfile[strlen(inputfile) - 4] = '\0'; //ensures outputfile length is 4 more than inputfile length
  }
  else { //if .enc not in inputfilename, outputfilename = inputfilename + .enc
    last_four = ".enc";
    //printf("filename doesn't end with .enc\n");
    strcpy(outputfile, inputfile);
    strcat(outputfile, last_four);
  }
} //no return needed as outputfile is global, populated appropriately
