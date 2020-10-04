#include <stdio.h>

int main()
{
  // c for incoming char, len for length of the current word
  int c, len;
  len = 0;
  // array to store the numbers of occurences of words
  // we assume that there will be none longer than 19 characters long
  int wordLengths[20];
  for (int i = 0; i < 20; i++) {
	wordLengths[i] = 0;
  }

  // read incoming stream
  while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	  wordLengths[len]++;
	  len = 0;
	} else {
	  len++;
	}
  }

  // Display histogram
  for (int i = 0; i < 20; i++) {
	printf("Words with %2d characters: ", i);
	for (int j = 0; j < wordLengths[i]; j++) {
	  printf("#");
	}
	printf("\n");
  }
}
