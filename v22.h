struct secretkeybits {
  unsigned int k0 : 1;
  unsigned int k1 : 1;
  unsigned int k2 : 1;
  unsigned int k3 : 1;
  unsigned int k4 : 1;
  unsigned int k5 : 1;
  unsigned int k6 : 1;
  unsigned int k7 : 1;
};

typedef struct userinput {
  struct secretkeybits seckey;
  char inputfile[21];
} userinput_t;
