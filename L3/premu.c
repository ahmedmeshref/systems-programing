#include <stdio.h> 
#include <string.h> 
  
void swap(char *x, char *y);
void permute(char *a, int l, int r);
  
int main (void) 
{ 
    char str[] = "asc"; 
    int n = strlen(str); 
    printf("Orginal String: %s\n", str);
    printf("----------- Premutations -----------\n");
    permute(str, 0, n-1); 
    return 0; 
} 

/* permute is a function to print permutations of string 
   This function takes three parameters: 
   1. *a: input string 
   2. s: starting index of the string 
   3. e: ending index of the string. */
void permute(char *a, int s, int e) 
{ 
   int i; 
   if (s == e) printf("%s\n", a); 
   else { 
       for (i = s; i <= e; i++) 
       { 
          swap((a+s), (a+i)); 
          permute(a, s+1, e); 
          swap((a+s), (a+i));
       } 
   } 
} 


/* wap function swaps values at two char pointers
   This function takes two parameters: 
   1. x: address to first char 
   2. y: address to second char */
void swap(char *x, char *y) 
{ 
    char temp = *x; 
    *x = *y; 
    *y = temp; 
} 