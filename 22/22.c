#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void print_list(char **names, int start, int length)
{
  int i;
  char **ptr;
  printf("[");
  for (i = start, ptr = names + start; i < start + length; i++, ptr++) {
    printf("%s, ", *ptr);
  }
  printf("]\n");
}

int score(const char *name)
{
  int score = 0;
  const char *ch = name;
  while (*ch ) {
    score += *ch - 'A' + 1;
    ch++;
  }
  return score;
}

int partition(char **list, int start, int length)
{
  int i = start + 1, j;
  char *temp;
  for (j = i; j < length; j++) {
    int cmp = strcmp(list[j], list[start]);
    if (cmp < 0) {
      temp = list[j];
      list[j] = list[i];
      list[i] = temp;
      i++;
    }
  }
  
  // swap pivot
  temp = list[start];
  list[start] = list[i - 1];
  list[i - 1] = temp;
  return i - 1;
}

void quicksort(char **list, int start, int length)
{
  if (length <= 1) {
    //print_list(list, start, length);
    return;
  }

  int pivot = partition(list, start, start + length);
  //printf("pivot = %d %s\n", pivot, *(list + pivot));
  //print_list(list, start, length);
  //printf("left sorting.. %d length %d\n", start, pivot - start);
  quicksort(list, start, pivot - start);
  //printf("right sorting.. %d length %d\n", pivot + 1, (start + length) - (pivot + 1));
  quicksort(list, pivot + 1, (start + length) - (pivot + 1));
}

int main(int argc, char *argv[])
{
  int ch;
  int openQuote = 0;
  int i = 0, idx = 0, pos = 1, sum = 0;
  char buf[1024];
  int szInc = 1024;
  char **list = malloc(szInc * sizeof(char *));
  char **sorted_list = NULL, **ptr;

  while ((ch = getc(stdin)) != EOF) {
    if (ch == ',' || isspace(ch))
      continue;
    else if (ch == '"') {
      if (openQuote) {
        // close quote
        buf[i] = '\0';
        if (idx == szInc) {
          szInc <<= 1;
          list = realloc(list, szInc * sizeof(char *));
        }
        list[idx++] = strdup(buf);
        i = 0;
        openQuote = 0;
        //printf("%s\n", list[idx - 1]);
      } else {
        openQuote = 1;
      }
    }
    else {
      buf[i++] = ch;
    }
  }
  list[idx] = NULL;

  sorted_list = malloc((idx + 1) * sizeof(char *));
  memcpy(sorted_list, list, (idx + 1) * sizeof(char *));
  //print_list(sorted_list, 0, idx);
  quicksort(sorted_list, 0, idx);
  //print_list(sorted_list, 0, idx);
  for (ptr = sorted_list; *ptr; ptr++) {
    sum += score(*ptr) * pos;
    pos++;
  }
  printf("%d\n", sum);
  return 0;
}


