#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Below is string manipulation and parsing functions

//Word amount counter.
//Does not consider punctuation charachters
//V1
size_t countWords(char *string) {
  size_t amount = 0;
  size_t length = strlen(string);

  int lock = 0;
  for (int i = 0; i < length; i++) {
    if (string[i] != ' ') {
      if (!lock) {
        lock = 1;
        amount++;
      }
    } else {
      if (lock) {
        lock = 0;
      }
    }
  }

  return amount;
}

//Get a copy of substring retrieved from a given string
//Pos1 (included), pos2 (excluded);
//pos vals not checked for validity
//V1
char *subscpy(char *string, int pos1, int pos2) {
  size_t length = pos2 - pos1;
  char *substring = calloc(length + 1, sizeof (char));
  for (int i = 0; i < length; i++) {
    substring[i] = string[pos1 + i];
  }
  return substring;
}

void strip(char string[]) {
  int startIndex = -1;
  int endIndex = strlen(string);
  while (string[++startIndex] == ' ');
  while (string[--endIndex] == ' ');

  int index = 0;
  for (; startIndex <= endIndex; startIndex++) {
    string[index++] = string[startIndex];
  }
  string[index] = '\0';
}

// Miscellaneous below

//Palindrome checker
//Letters must be of the same case [Not implemented]
int isPalindrome(char string[]) {
  size_t length = strlen(string);

  int isSame = 1;
  for (int i = 0; i < length / 2; i++) {
    if (!(string[i] == string[length - 1 - i])) {
      isSame = 0;
      break;
    }
  }
  return isSame;
}

int compareStrings(char *string1, char *string2) {

  size_t length = strlen(string1);
  if (length != strlen(string2)) return 0;

  for (size_t i = 0; i < length; i++) {
    if (string1[i] != string2[i]) return 0;
  }

  return 1;
}

void printFlag() {
  size_t starsPerLine = 11;
  size_t starLines = 5;
  size_t stripLength = 50;
  for (int i = 0; i < 13; i++) {
    for (int s = 0; s < stripLength; s++) {
      if (s < starsPerLine * 2 - 1 && i < starLines) {
        if (i % 2) {
          printf("%c", s % 2? '*' : ' ');
        } else {
          printf("%c", s % 2? ' ': '*');
        }
      } else {
        if (s < starsPerLine * 2  && i < starLines) {
          printf(" ");
        } else {
          printf("=");
        }
      }
    }
    printf("\n");
  }
}

//Below is implementation of console parser


int main(void) {
  char *string = "Hello World";
  char *substring = subscpy(string, 6, 11);
  printf("%s\n", substring);
}
