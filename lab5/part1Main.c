#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern char *  pop();
extern void push(char *);

int main(int argc, char * argv[])
{
  int ch;
  char tag[100];
  int i = 0;
  int isEndTag = 0;
  int inTag = 0;
  
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    if (ch == '<') {
        inTag = 1;
        isEndTag = 0;
        i = 0;
    } else if (ch == '/') {
        isEndTag = 1;
    } else if (ch == '>') {
        if (inTag) {
            tag[i] = '\0';
            inTag = 0;

            if (!isEndTag) {
                char *newTag = (char *)malloc((i + 1) * sizeof(char));
                int j;
                for (j = 0; j <= i; j++) {
                    newTag[j] = tag[j];
                }
                push(newTag);
            } else {
                char *poppedTag = pop();
                
                if (poppedTag == (char *)0) {
                    printf("Invalid\n");
                    exit(0);
                }
                
                int match = 1;
                int j = 0;
                while (tag[j] != '\0' || poppedTag[j] != '\0') {
                    if (tag[j] != poppedTag[j]) {
                        match = 0;
                        break;
                    }
                    j++;
                }
                
                if (!match) {
                    printf("Invalid\n");
                    exit(0);
                }
                
                free(poppedTag);
            }
        }
    } else if (isalpha(ch) && inTag) {
        tag[i++] = ch;
    }
  }
  
  char *check = pop();
  if (check != (char *)0) {
      printf("Invalid\n");
  } else {
      printf("Valid\n");
  }
  exit(0);
}
