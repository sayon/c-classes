#pragma once

#include <stdio.h>

typedef struct {   } object;

#include "cl_util.h"

#define FIELD_TO_ARG( type, name, _, __ ) ,type name
#define CREATE_ARG( type, name ) ,type name
#define DECLARE_FIELD( type, name, _, __ ) type name;




#include "cl_to_file.h"

#include "cl_ctor.h"

#include "cl_method.h"


#define PRIVATE_FIELDS_STRUCT( DESCR ) struct {\
        FOR_PRIVATE_FIELDS( DESCR, DECLARE_FIELD )\
    }

#define CLASS_METHODS_PROTO( DESCR )\
    CTOR_PROTO( DESCR  )\
    TO_FILE_PROTO( DESCR )\
    FOR_PUBLIC_METHODS( DESCR, METHOD_PROTO )


#define CLASS_METHODS( DESCR )\
    CTOR_IMPL( DESCR )\
    TO_FILE_IMPL( DESCR )\
    FOR_PUBLIC_METHODS( DESCR, METHOD_IMPL )


#ifdef IMPL /*  Inside .c file */

#define CLASS_TYPE( DESCR )\
    typedef struct {\
        PARENT_NAME( DESCR ) parent;\
        FOR_PUBLIC_FIELDS( DESCR, DECLARE_FIELD )\
        union {\
            PRIVATE_FIELDS_STRUCT( DESCR );\
        char stub[sizeof(PRIVATE_FIELDS_STRUCT(DESCR) )];\
        };\
} CLASS_NAME( DESCR ) ;

#define CLASS( DESCR )\
    CLASS_TYPE( DESCR )\
    CLASS_METHODS( DESCR )

#else  /*  Inside .h file */

#define CLASS_TYPE( DESCR )\
    typedef struct { \
        PARENT_NAME( DESCR ) parent;\
        FOR_PUBLIC_FIELDS( DESCR, DECLARE_FIELD )\
        union {\
            char stub[sizeof(PRIVATE_FIELDS_STRUCT(DESCR) )];\
        };\
} CLASS_NAME( DESCR ) ;


#define CLASS( DESCR )\
    CLASS_TYPE( DESCR )\
    CLASS_METHODS_PROTO( DESCR )

#endif /*  IMPL */


