#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* likes(char* names[], size_t names_size) {
  char* result = calloc(255, sizeof(char)); // 255 cells of memory
  char comma_delimiter[] = ", ";
  char and_delimiter[] = " and ";

  for (int i = 0; i < names_size; i++) {
    int is_last = i == names_size - 1;

    if (names_size == 1) {
      strcat(result, names[i]);
    } else if(names_size == 2) {
      if (is_last) {
        strcat(result, and_delimiter);
      }

      strcat(result, names[i]);
    } else if(names_size == 3) {

      if (is_last) {
        strcat(result, and_delimiter);
      }

      strcat(result, names[i]);

      if (!is_last) {
        strcat(result, comma_delimiter);
      }
    } else {
      is_last = i == 1;

      if (i > 1) {
        char* other = (char*)malloc(16 * sizeof(char));
        sprintf(other, " and %lu others", names_size - 2); //%lu - for size_t
        strcat(result, other);
        break;
      }

      if (is_last) {
        strcat(result, comma_delimiter);
      }

      strcat(result, names[i]);
    }
  }

  return result;
}

void main() {
  int name_count;
  printf("How many names do you want to submit?\n");
  scanf("%d", &name_count);
  char* names[name_count];

  for (int i = 0; i < name_count; i++) {
    names[i] = malloc(16);
    scanf("%s", names[i]);  // s - string
  }

  printf("%s likes this\n", likes(names, name_count));
}
