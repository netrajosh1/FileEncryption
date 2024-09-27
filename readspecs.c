#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v22.h"

void readspecs(userinput_t *datastruct, char *com_key, char *com_filename) {
  for (int i = 0; i < 8; i++) {
    if ((com_key[i] != '0') && (com_key[i] != '1')) { //key input validation
      printf("Invalid key value!\n");
      exit(1);
    }
    //datastruct.seckey.i = com_key[i];
  }
  datastruct->seckey.k0 = com_key[0];
  datastruct->seckey.k1 = com_key[1];
  datastruct->seckey.k2 = com_key[2];
  datastruct->seckey.k3 = com_key[3];
  datastruct->seckey.k4 = com_key[4];
  datastruct->seckey.k5 = com_key[5];
  datastruct->seckey.k6 = com_key[6];
  datastruct->seckey.k7 = com_key[7];

  int index = 0;
  for (int j = 0; j < strlen(com_filename); j++) {
    if (((com_filename[j] < 65) && (com_filename[j] != 46)) || (com_filename[j] > 122)) { //filename validation
      printf("Invalid filename input 1!\n");
      exit(1);
    }
    else if ((com_filename[j] > 90) && (com_filename[j] < 97)) { //filename validation
      printf("Invalid filename input 2!\n");
      exit(1);
    }
    else {
      *(datastruct->inputfile + index) = com_filename[j]; //populating the filename with pointers
    }
    index++;
  }
  printf("Inputfile readspecs: %s\n", datastruct->inputfile);
  datastruct->inputfile[index] = '\0'; //ensuring filename ends with nullbyte
  if (strlen(com_key) < 8) { //key length can't be less than 8
    printf("Invalid key length!\n");
    exit(1);
  }
  if (strlen(com_filename) > 20) { //filename length can't be more than 20
    printf("Invalid filename length!\n");
    exit(1);
  }

  return;
}
