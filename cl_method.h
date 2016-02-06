
#define METHOD_NAME( MDESCR ) MDESCR( ID, SKIP1, SKIP2, SKIP1, SKIP1 )
#define METHOD_RETURNS( MDESCR ) MDESCR( SKIP1, SKIP1,SKIP2, ID, SKIP1 )
#define METHOD_CLASSNAME( MDESCR ) MDESCR( SKIP1, ID, SKIP2, SKIP1, SKIP1 )
#define METHOD_BODY( MDESCR ) MDESCR( SKIP1, SKIP1, SKIP2, SKIP1, ID )
#define FOR_METHOD_ARGS( MDESCR, DO ) MDESCR( SKIP1, SKIP1, DO, SKIP1, SKIP1 )


#define METHOD_SIGNATURE( MDESCR ) \
    METHOD_RETURNS( MDESCR )\
    PAIR( METHOD_CLASSNAME(MDESCR), METHOD_NAME(MDESCR) )\
    ( METHOD_CLASSNAME(MDESCR) * this \
      FOR_METHOD_ARGS(MDESCR, CREATE_ARG ) ) 

#define METHOD_PROTO( MDESCR ) METHOD_SIGNATURE( MDESCR );

#define METHOD_IMPL( MDESCR )\
    METHOD_SIGNATURE(MDESCR) METHOD_BODY( MDESCR )

