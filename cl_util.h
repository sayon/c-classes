/*  Util macro */

#define PREPEND_COMMA( x ) ,x

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

#define PAIR_(a, b) a##_##b
#define PAIR(a, b) PAIR_(a, b)

#define ID(x) x
#define SKIP1( a ) 
#define SKIP2( a,b ) 
#define SKIP3( a,b,c ) 
#define SKIP4( a,b,c,d ) 
#define SKIP5( a,b,c,d,e ) 

/*  Reference:
 *  Declaring class:
 *
#define CLASS_mc( NAME, EXTENDS, PUBLIC_FIELD, PRIVATE_FIELD, PUBLIC_METHOD, PRIVATE_METHOD, PUBLIC_CTOR, PRIVATE_CTOR, DTOR )
 *
 *
 *  Declaring ctor:
#define child_ctor(NAME, OF, ARG, BASEARG, BODY )\
 *
 *  Declaring method:
#define method(NAME, OF, ARG, RETURNS, BODY )\
 *  */

/*  Class util: 'getters' */
#define CLASS_NAME( DESCR ) DESCR( ID, SKIP1, SKIP4, SKIP4, SKIP1, SKIP1, SKIP1, SKIP1, SKIP1 )
#define PARENT_NAME( DESCR ) DESCR( SKIP1, ID, SKIP4, SKIP4, SKIP1, SKIP1, SKIP1, SKIP1, SKIP1 )

#define FOR_PUBLIC_FIELDS( DESCR, DO ) DESCR( SKIP1, SKIP1, DO, SKIP4, SKIP1, SKIP1, SKIP1, SKIP1, SKIP1 )
#define FOR_PRIVATE_FIELDS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP4, DO, SKIP1, SKIP1, SKIP1, SKIP1, SKIP1 )

#define FOR_ALL_FIELDS( DESCR, DO )\
    FOR_PUBLIC_FIELDS(DESCR, DO) \
    FOR_PRIVATE_FIELDS(DESCR,DO)

#define FOR_PUBLIC_METHODS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP4, SKIP4, DO, SKIP1, SKIP1, SKIP1, SKIP1 )
#define FOR_PRIVATE_METHODS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP4, SKIP4, SKIP1, DO, SKIP1, SKIP1, SKIP1 )
#define FOR_ALL_METHODS( DESCR, DO )\
    FOR_PRIVATE_METHODS( DESCR, DO )\
    FOR_PUBLIC_METHODS( DESCR, DO )


#define FOR_PUBLIC_CTORS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP4, SKIP4, SKIP1, SKIP1, DO, SKIP1, SKIP1 )
#define FOR_PRIVATE_CTORS( DESCR, DO ) DESCR( SKIP1, SKIP1, SKIP4, SKIP4, SKIP1, DO, SKIP1, DO, SKIP1 )
#define FOR_ALL_CTORS( DESCR, DO )\
    FOR_PRIVATE_METHODS( DESCR, DO )\
    FOR_PUBLIC_METHODS( DESCR, DO )
