#pragma once

#include <stdio.h>

typedef struct {   } object;


#define FIELD_TO_ARG( type, name, _ ) ,type name
#define CREATE_ARG( type, name ) ,type name
#define DECLARE_FIELD( type, name, _ ) type name;

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

#define PAIR_(a, b) a##_##b
#define PAIR(a, b) PAIR_(a, b)

#define ID(x) x
#define SKIP1( a ) 
#define SKIP2( a,b ) 
#define SKIP3( a,b,c ) 
#define SKIP4( a,b,c,d ) 

#define CLASS_NAME( DESCR ) DESCR( ID, SKIP1, SKIP3, SKIP3, SKIP1 )
#define PARENT_NAME( DESCR ) DESCR( SKIP1, ID, SKIP3, SKIP3, SKIP1 )

#define FOR_PUBLIC_FIELDS( DESCR, DO ) DESCR( SKIP1, SKIP1, DO, SKIP3, SKIP1 )
#define FOR_PRIVATE_FIELDS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP3, DO, SKIP1 )

#define FOR_PUBLIC_METHODS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP3, SKIP3, DO )

#define FOR_ALL_FIELDS( DESCR, DO )\
    FOR_PUBLIC_FIELDS(DESCR, DO) \
    FOR_PRIVATE_FIELDS(DESCR,DO)

#define CTOR_INIT( _, name, __ ) this->name = name; 

#define CTOR_SIGNATURE( DESCR)\
    CLASS_NAME( DESCR ) \
    CAT(CLASS_NAME(DESCR) , _init )  ( CLASS_NAME(DESCR)* this\
            FOR_ALL_FIELDS( DESCR, FIELD_TO_ARG ) )

#define CTOR_PROTO( DESCR ) CTOR_SIGNATURE( DESCR );
#define CTOR_IMPL( DESCR ) \
    CTOR_SIGNATURE( DESCR )\
{\
        CLASS_NAME( DESCR ) instance;\
        FOR_ALL_FIELDS( DESCR, CTOR_INIT )\
        return instance; }

#define PRIVATE_FIELDS_STRUCT( DESCR ) struct {\
        FOR_PRIVATE_FIELDS( DESCR, DECLARE_FIELD )\
    }

#define METHOD_NAME( MDESCR ) MDESCR( ID, SKIP1, SKIP2, SKIP1, SKIP1 )
#define METHOD_RETURNS( MDESCR ) MDESCR( SKIP1, SKIP1,SKIP2, ID, SKIP1 )
#define METHOD_CLASSNAME( MDESCR ) MDESCR( SKIP1, ID, SKIP2, SKIP1, SKIP1 )
#define METHOD_BODY( MDESCR ) MDESCR( SKIP1, SKIP1, SKIP2, SKIP1, ID )
#define FOR_METHOD_ARGS( MDESCR, DO ) MDESCR( SKIP1, SKIP1, DO, SKIP1, SKIP1 )

#define PRINT_FIELD( TYPE, NAME, SPEC ) fprintf( f, #TYPE " " #NAME " = " #SPEC "\n", this-> NAME );

#define TO_FILE_SIGNATURE( DESCR )\
    void PAIR( CLASS_NAME(DESCR), to_file ) ( CLASS_NAME(DESCR)* this,  FILE* f )

#define TO_FILE_PROTO( DESCR ) TO_FILE_SIGNATURE( DESCR );

#define TO_FILE_IMPL( DESCR ) TO_FILE_SIGNATURE( DESCR ) { FOR_ALL_FIELDS( DESCR, PRINT_FIELD ) }


#define METHOD_SIGNATURE( MDESCR ) \
    METHOD_RETURNS( MDESCR )\
    PAIR( METHOD_CLASSNAME(MDESCR), METHOD_NAME(MDESCR) )\
    ( METHOD_CLASSNAME(MDESCR) * this \
      FOR_METHOD_ARGS(MDESCR, CREATE_ARG ) ) 

#define METHOD_PROTO( MDESCR ) METHOD_SIGNATURE( MDESCR );

#define METHOD_IMPL( MDESCR )\
    METHOD_SIGNATURE(MDESCR) METHOD_BODY( MDESCR )


#define CLASS_METHODS_PROTO( DESCR )\
    CTOR_PROTO( DESCR  )\
    TO_FILE_PROTO( DESCR )\
    FOR_PUBLIC_METHODS( DESCR, METHOD_PROTO )


#define CLASS_METHODS( DESCR )\
    CTOR_IMPL( DESCR )\
    TO_FILE_IMPL( DESCR )\
    FOR_PUBLIC_METHODS( DESCR, METHOD_IMPL )


#ifdef IMPL

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
#else 

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
#endif


