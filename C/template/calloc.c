#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 0;
  long t_running = 0;
  long *t_on = NULL;
  int i;

  if (scanf("%d %ld", &n, &t_running) != 2)
    goto fail;

  t_on = (long *)calloc(n, sizeof(long));
  if (t_on == NULL)
    goto fail;

  for (i = 0; i < n; i++) {
    if (scanf("%ld", &t_on[i]) != 1)
      goto fail;
  }

  long interval;
  long long total_running_time = 0;

  for (i = 1; i < n; i++) {
    interval = t_on[i] - t_on[i - 1];
    if (interval > t_running) {
      total_running_time += t_running;
    } else {
      total_running_time += interval;
    }
  }

  /* Add the last running time. */
  total_running_time += t_running;

  printf("%lld\n", total_running_time);

pass:
  free(t_on);

  return 0;

failure:
  free(t_on);

  printf("Failure\n");

  return -1;
}