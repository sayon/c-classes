#pragma once

#include "class.h"
#define CLASS_mc( NAME, EXTENDS, PUBLIC_FIELD, PRIVATE_FIELD, PUBLIC_METHOD, PRIVATE_METHOD, PUBLIC_CTOR, PRIVATE_CTOR, DTOR ) \
    NAME( mc )\
    EXTENDS( object )\
    PUBLIC_FIELD( int, x, 0, "%d" )\
    PUBLIC_FIELD( float, y, 0, "%f" )\
    PRIVATE_FIELD( int, _x, 1, "%d" )\
    PRIVATE_FIELD( float, _y, 1, "%f")\
    PUBLIC_METHOD( SOMEMETHOD )\
    PRIVATE_METHOD( SOMEMETHOD )

#define SOMEMETHOD(NAME, OF, ARG, RETURNS, BODY )\
    NAME( somemethod ) OF( mc ) RETURNS( int )\
    ARG( int, a )\
    ARG( int, b )\
    BODY( { return this->x + this->y + \
            this->_y +this->_x + a + b; } ) 


#define CLASS_child( NAME, EXTENDS, PUBLIC_FIELD, PRIVATE_FIELD, PUBLIC_METHOD, PRIVATE_METHOD, PUBLIC_CTOR, PRIVATE_CTOR, DTOR) \
    NAME( child )\
    EXTENDS( mc )\
    PUBLIC_FIELD( int, z, 0, "%d" )\
    PUBLIC_CTOR( child_ctor )




#define child_ctor(CONSTRUCTOR, OF, ARG, BASENAME, BASEARG, BODY )\
    CONSTRUCTOR( other ) OF( child ) ARG( int, a )\
    BASEARG( 1 )\
    BASEARG( 2.0f )\
    BASEARG( 3 )\
    BASEARG( 4.0f )\
    BODY( { } )

CLASS( CLASS_mc )

CLASS( CLASS_child )
