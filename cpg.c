#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *passgen(char **characterSet, size_t cs_length, size_t ps_length) {
  srand(time(NULL));

  if ((ps_length == 0) || (cs_length == 0)) return NULL;
  char *password = malloc(ps_length + 1);
  size_t char_set_index;
  size_t char_index;
  size_t char_set_length;
  size_t i;
  for (i = 0; i < ps_length; i++) {
    char_set_index = rand() % cs_length;
    char_set_length = strlen(characterSet[char_set_index]);
    char_index = rand() % char_set_length;
    password[i] = characterSet[char_set_index][char_index];
  }
  password[i] = '\0';
  return password;
}
