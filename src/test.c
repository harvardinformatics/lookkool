#include <stdio.h>
#include "lookkool.h"
 
int main(void)
{
    int len = 28;
    char palindrome[] = "ATCGCGATAATATGCAGTAATCGCGAT";
    int maxlocs = 20;
    int locs[20] = {0};
    printf("Looking for palindromes in %s\n",palindrome);
    
    find_palindromes(palindrome,len,locs,maxlocs);

    int i = 0;
    for(i = 0; i < 20; i = i + 2){
        if(locs[i] > 0){
            printf("Palindrome starts at %d and ends at %d\n",locs[i],locs[i+1]);
        }
    }
    
    return 0;
}
