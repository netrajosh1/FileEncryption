#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "v22.h"

void keyconvert(struct secretkeybits keystr, int *key) { //keyconvert translates the secret key into the first 8 bits of key
  int mask = ~(~0 << 1);
  int num = 0;
  if (keystr.k7 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k6 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k5 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k4 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k3 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k2 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k1 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  if (keystr.k0 == 1) {
    num = num | mask;
  }
  mask = mask << 1;
  *key = num;
  printf("Key in hex: 0x%08x\n", *key); //printing out the decimal value as a hexadecimal
}
