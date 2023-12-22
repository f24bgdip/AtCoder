#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int h, w, current_row;
  unsigned char *image;
  int i, j;

  if (scanf("%u %u", &h, &w) == 0)
    goto fail;

  image = (unsigned char *)calloc(h * (w + 1), sizeof(unsigned char));

  for (i = 0; i < h; i++) {
    fflush(stdin);

    if (scanf("%s", image + (i * (w + 1))) == 0)
      goto fail;
  }

  /* drow */
  current_row = 0;

  for (i = 0; i < h; i++) {
    for (j = 0; j < 2; j++) {
      printf("%s\n", image + (i * (w + 1)));
    }
  }

pass:
  exit(EXIT_SUCCESS);

fail:
  exit(EXIT_FAILURE);
}
