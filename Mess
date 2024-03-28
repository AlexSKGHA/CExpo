#include <stdio.h>
#include <string.h>

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

//========Above are functions allowing for code readability below===============

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


int main(void) {

}
