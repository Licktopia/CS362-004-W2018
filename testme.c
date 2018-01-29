#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


// A utility function to swap to integers
void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char inputChar()
{   
    char *characters = "[({ ax})]";
    int random = rand() % 9;
    return characters[random];
}

char *inputString()
{
  char *arr = (char *) malloc(sizeof(char) * 6);   
  arr[0] = 'r';
  arr[1] = 'e';
  arr[2] = 's';
  arr[3] = 'e';
   arr[4] = 't';
    arr[5] = '\0';
    srand ( time(NULL) );
    for (int i = 4; i > 0; i--)
    {
        int j = rand() % (i+1);
 
        swap(&arr[i], &arr[j]);
    }
    printf("1%s", arr);
    return arr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
