#include "church_numerals.h"
#include "macro_defer.h"

int printf(const char* format, x);


typedef void* vtable_t;

#define SKIP 
#define ID(x) x
#define SKIP1(_) 
#define CAT(x, y) CAT_(x,y)
#define CAT_(x,y) x##y


#define C_NAME( DESCR ) DESCR( ID, SKIP1, SKIP )
#define C_BASE( DESCR ) DESCR( SKIP1, C_NAME, SKIP )
#define C_BASEDESCR( DESCR ) DESCR( SKIP1, ID, SKIP )

#define CLASS( DESCR )\
    typedef struct C_NAME( DESCR ){\
        C_BASE( DESCR ) base;\
    } C_NAME( DESCR );

#define STUB_ROOT( NAME, BASE, IS_BASE )\
    NAME( vtable_t )

#define OBJECT( NAME, BASE, IS_BASE )\
    IS_BASE\
    BASE( STUB_ROOT )\
    NAME( object )

#define B( NAME, BASE, IS_BASE) NAME(b) BASE( OBJECT )
#define C( NAME, BASE, IS_BASE ) NAME( c ) BASE( B )    
#define D( NAME, BASE, IS_BASE ) NAME( d ) BASE( C)    
#define E( NAME, BASE, IS_BASE ) NAME( e ) BASE( D  )    

CLASS( OBJECT )
CLASS( B )
CLASS( C)
CLASS( D )
CLASS( E )

#define GET_BASE(DESCR) DESCR(SKIP1, SKIP1, _BASE)
#define IF_BASE_ELSE(DESCR, ACTIONS) CAT(ACTIONS, GET_BASE(DESCR))


#define ANCESTORS( DESCR ) OBSTRUCT(IF_BASE_ELSE(DESCR, ANC))(DESCR) 

#define ANC(DESCR) C_BASEDESCR (DESCR )  OBSTRUCT(ANCESTORS)(C_BASEDESCR(DESCR))
#define ANC_BASE(DESCR) 


EVAL( ANCESTORS(E))

/*  
#define ITE(x,y,z) x (y,z)
#define T(x,y) x
#define F(x,y) y


#define G ,1)
#define BA ,)
#define LPAR (
#define TEST(x,y) x##y
#define MT TEST LPAR
 EVAL4( MT 0 G )


EVAL5( ANCESTORS( E ) )
EVAL5(EVAL5( ANCESTORS( E ) ))
EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))
EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) ))))))))))))))))
EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5(EVAL5( ANCESTORS( E ) )))))))))))))))))
//EVAL5(EVAL5(//EVAL(ID _C3(C_BASEDESCR, E))

//EVAL2( ANCESTORS( E) )
//
#define ANCESTOR(CL, i) EVAL(C_BASE( ID TO_CHURCH(i, C_BASEDESCR, E ) ))

ANCESTOR(E, 0)
ANCESTOR(E, 1)
ANCESTOR(E, 2 )
ANCESTOR(E, 3)
ANCESTOR(E, 4) 
ANCESTOR(E, 5)
ANCESTOR(E, 6) 
ANCESTOR(E, 7) 
ANCESTOR(E, 8) 
ANCESTOR(E, 9) 

*/