#include <stdio.h>

// substr_c returns the first substring of s2 in s1
char *substr_c(char *s1, char *s2) {
    char *p1, *p2, *rv;
    rv = NULL;

    while (*s1 != '\0') {
        // Loop over all characters in s1
        p1 = s1;
        p2 = s2;
        while (*p1 != '\0' && *p2 != '\0' && (*p1 == *p2)) {
            // See if s2 is a substring of s1 at this index
            p1 += 1;
            p2 += 1;            
        }
        if (*p2 == '\0') {
            rv = s1;
            break;
        }
        s1 += 1;
    }

    return rv;
}

// matches_c counts the number of occurrences of s2 in s1
int matches_c(char *s1, char *s2) {
    int count = 0;
    char *next;
    
    while (*s1 != '\0') {
        if ((next = substr_c(s1, s2)) != 0) {
            count += 1;
            s1 = next + 1;
        } else {
            break;
        }
    }

    return count;
}
