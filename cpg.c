#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIGITS_PASSWORD_CHARSET "0123456789"
#define UPPERCASE_PASSWORD_CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_PASSWORD_CHARSET "abcdefghijklmnopqrstuvwxyz"
#define SPECIAL_PASSWORD_CHARSET "!@#$%^&*()?"

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

typedef struct {
  char useDigits;
  char useUppercase;
  char useLowercase;
  char useSpecial;
  size_t length;
} PassProps;

char *getPreDefPass(PassProps props) {
  char **charset = malloc(sizeof(void *) * 4);
  int index = 0;
  int charsetLength = 0;
  if (charsetLength += props.useDigits) 
    charset[index++] = DIGITS_PASSWORD_CHARSET;
  if (charsetLength += props.useUppercase) 
    charset[index++] = UPPERCASE_PASSWORD_CHARSET;
  if (charsetLength += props.useLowercase) 
    charset[index++] = LOWERCASE_PASSWORD_CHARSET;
  if (charsetLength += props.useSpecial) 
    charset[index++] = SPECIAL_PASSWORD_CHARSET;
  char *password = passgen(charset, charsetLength, props.length);
  free(charset);
  return password;
}

int main(void) {
  size_t ps_amount = 20;
  size_t ps_length = 16;
  PassProps pp = {
    .useDigits=1,
    .useUppercase=1,
    .useLowercase=1,
    .useSpecial=1,
    .length=ps_length * ps_amount
  };
  char *whole_password = getPreDefPass(pp);
  char password_sample[ps_length + 1] = {};
  for (int i = 0; i < ps_amount; i++) {
    strncpy(password_sample, whole_password + i * ps_length, ps_length);
    printf("%5d: %s\n", i + 1, password_sample);
  }
  free(whole_password);
  char *ptr = 0;
}
