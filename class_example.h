#include "class.h"
#define CLASS_mc(NAME, EXTENDS, PUBLIC_FIELD, PRIVATE_FIELD, PUBLIC_METHOD ) \
    NAME( mc )\
    EXTENDS( object )\
    PUBLIC_FIELD( int, x, "%d" )\
    PUBLIC_FIELD( float, y, "%f" )\
    PRIVATE_FIELD( int, _x, "%d" )\
    PRIVATE_FIELD( float, _y, "%f")\
    PUBLIC_METHOD( SOMEMETHOD )

#define SOMEMETHOD(NAME, OF, ARG, RETURNS, BODY )\
    NAME( somemethod ) OF( mc ) RETURNS( int )\
    ARG( int, a )\
    ARG( int, b )\
    BODY( { return this->x + this->y + \
            this->_y +this->_x + a + b; } ) 

CLASS( CLASS_mc )

