#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "testptr.h"

int main(void) {
    int *junk = NULL;
    int *junk2 = (int *)((uintptr_t)0x1231231233123123);
    int *p = malloc(69);
    int x = 5;
    int *px = &x;

    testptr(junk, 1, "junk", true);
    testptr(junk2, 1, "junk2", true);
    testptr(px, sizeof(int), "px", true);
    testptr(p, 69, "p", true);
    
    *junk = 123;
    return 0;
}
