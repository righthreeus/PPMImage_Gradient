#pragma once

#if defined(_MSVC_VER)
    #define DISABLE_WARING_PUSH      __pragma(warning(push))
    #define DISABLE_WARING_POP       __pragma(warning(pop))
    #define DISABLE_WARNING(number)  __pragma(warning(number))
    
    #define DISABLE_NARROWING        DISABLE_WARNING(4838)
#elif defined(__GNUC__) || defined(__clang__)
    #define DO_PRAGMA(X)_Pragma(#X)
    #define DISABLE_WARING_PUSH     DO_PRAGMA(GCC diagnostic push)
    #define DISABLE_WARING_POP      DO_PRAGMA(GCC diagnostic pop)
    #define DISABLE_WARNING(name)   DO_PRAGMA(GCC diagnostic ignored #name)

    #define DISABLE_NARROWING       DISABLE_WARNING(-Wnarrowing)
#else
    #define DISABLE_WARING_PUSH    
    #define DISABLE_WARING_POP     
    #define DISABLE_WARNING(name)  

    #define DISABLE_NARROWING
#endif