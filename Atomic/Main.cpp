#include <iostream>
#include "Atomic/API/Wrapper.h"
#include "Atomic/atomic.h"

int main()
{
#ifndef VS_DEBUG
    try {
#endif
        // Primary code
#ifndef VS_DEBUG
    }
    catch (...) {
        // If any errors go unhandled, handle them here
    }
#endif
    return 0;
}