#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILE   "crc32cr.h"
#define CRC32C_POLY    0x1EDC6F41UL

static FILE *tf;

static uint32_t
reflect_32(uint32_t b)
{
  int i;
  uint32_t rw = 0UL;

  for (i = 0; i < 32; i++) {
      if (b & 1)
        rw |= 1 << (31 - i);
      b >>= 1;
  }
  return (rw);
}

static uint32_t
build_crc_table(int index)
{
  int i;
  uint32_t rb;

  rb = reflect_32(index);

  for (i = 0; i < 8; i++) {
      if (rb & 0x80000000UL)
       rb = (rb << 1) ^ (uint32_t)CRC32C_POLY;
      else
       rb <<= 1;
  }
  return (reflect_32 (rb));
}

int
main (void)
{
  int i;

  printf("\nGenerating CRC-32c table file <%s>\n",
  OUTPUT_FILE);
  if ((tf = fopen (OUTPUT_FILE, "w")) == NULL) {
      printf ("Unable to open %s\n", OUTPUT_FILE);
      exit (1);
  }
  fprintf(tf, "#ifndef __crc32cr_h__\n");
  fprintf(tf, "#define __crc32cr_h__\n\n");
  fprintf(tf, "#define CRC32C_POLY 0x%08XUL\n",
    (uint32_t)CRC32C_POLY);
  fprintf(tf,
    "#define CRC32C(c,d) (c=(c>>8)^crc_c[(c^(d))&0xFF])\n");
  fprintf(tf, "\nuint32_t crc_c[256] =\n{\n");
  for (i = 0; i < 256; i++) {
      fprintf(tf, "0x%08XUL,", build_crc_table (i));
      if ((i & 3) == 3)
        fprintf(tf, "\n");
      else
        fprintf(tf, " ");
  }
  fprintf(tf, "};\n\n#endif\n");

  if (fclose (tf) != 0)
    printf("Unable to close <%s>.", OUTPUT_FILE);
  else
    printf("\nThe CRC-32c table has been written to <%s>.\n",
      OUTPUT_FILE);
}
