#include <stdio.h>
#include "lookkool.h"
/* #include <stdatomic.h> */

/*
 * Returns the start and end of palindromes in the given sequences.
 * The chars in seq must be upper case.
 * seqlen should be the length of the sequence.
 * Locations of palindromes will be added to locs.
 */

int MIN_PALINDROME_LENGTH = 4;

char complement(char base){
    if (base == 'T') {
        return 'A';
    }
    if (base == 'C') {
        return 'G';
    }
    if (base == 'A') {
        return 'T';
    }
    if (base == 'G') {
        return 'C';
    }
    return 'N';
}


void find_palindromes(char *seq, int seqlen, int *locs, int maxlocs){

    int start = 0;
    int window = seqlen;
    int end = start + window;
    int loc_i = 0;
    int i = 0;
    int j = 0;


    while(window >= MIN_PALINDROME_LENGTH && start < seqlen - MIN_PALINDROME_LENGTH){

        i = start;
        end = start + window;
        j = end - 1;

        // printf("seq %d is %c and complement of seq %d is %c\n",i,seq[i],j,complement(seq[j]));
        while(seq[i] == complement(seq[j]) && i < j){
            i++;
            j--;
        }
        if (i >= j){
            // Found a palindrome
            // printf("Found a palindrome at %d and %d\n",start + 1,end);

            int k = 0;
            int subset = 0;
            while(locs[k] > 0 && k+1 < maxlocs){
                if(start + 1 - locs[k] == locs[k+1] - end){
                    subset = 1;
                }
                k++;
            }
            if(!subset){
                locs[loc_i] = start + 1;
                loc_i += 1;
                locs[loc_i] = end;
                loc_i += 1;
            }
        }

        if(start + window > seqlen){
            start = 0;
            window = window - 2;
        }
        else {
            start = start + 1;
        }
        //printf("Window is now %d and start is %d\n",window,start);
    }

}
