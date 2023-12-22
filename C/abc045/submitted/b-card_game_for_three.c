#include <stdio.h>
#include <string.h>

#define MAX_CARD 100 + 1

int main() {
  char SA[MAX_CARD], SB[MAX_CARD], SC[MAX_CARD];
  if (scanf("%s", SA) != 1)
    return -1;
  if (scanf("%s", SB) != 1)
    return -1;
  if (scanf("%s", SC) != 1)
    return -1;

  int a = 0, b = 0, c = 0;
  char current = 'a';

  while (1) {
    if (current == 'a') {
      if (SA[a] == '\0') {
        printf("A\n");
        break;
      }
      current = SA[a++];
    } else if (current == 'b') {
      if (SB[b] == '\0') {
        printf("B\n");
        break;
      }
      current = SB[b++];
    } else if (current == 'c') {
      if (SC[c] == '\0') {
        printf("C\n");
        break;
      }
      current = SC[c++];
    }
  }

  return 0;
}
