/* Ctor */

#define CTOR_INIT( _, name, __, ___ ) this->name = name; 

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

#define CCTOR_NAME( DESCR ) DESCR( ID, SKIP1, SKIP2, SKIP1, SKIP1, SKIP1 )
#define CCTOR_CLASS( DESCR ) DESCR( SKIP1, ID, SKIP2, SKIP1, SKIP1, SKIP1 )
#define CCTOR_BASECTOR( DESCR ) DESCR( SKIP1, ID, SKIP2, ID, SKIP1, SKIP1 )
#define CCTOR_BODY( DESCR ) DESCR( SKIP1, ID, SKIP2, SKIP1, SKIP1, ID)

#define FOR_CCTOR_ARG( DESCR, DO ) DESCR( SKIP1, SKIP1, DO, SKIP1, SKIP1, SKIP1 )
#define FOR_CCTOR_BASEARG( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP2, SKIP1, DO, SKIP1 )

#define CCTOR_SIGNATURE( DESCR ) CCTOR_NAME( DESCR ) ( CCTOR_CLASS(DESCR)* this\
        FOR_CCTOR_ARG( CREATE_ARG ) ) 

#define CCTOR( DESCR ) CCTOR_SIGNATURE( DESCR ){\
        CCTOR_BASECTOR(DESCR)( &(this->parent) FOR_CCTOR_BASEARG( PREPEND_COMMA ) ); \
    CCTOR_BODY( DESCR )\
}





/*  #define child_ctor(NAME, OF, ARG, BASECTOR, BASEARG, BODY )\
    NAME( other ) OF( child ) \
        ARG( int, a )\
    BASECTOR( mc_custom )\
    BASEARG( 1 )\
    BASEARG( 2.0f )\
    BASEARG( 3 )\
    BASEARG( 4.0f )\ */
