#include "church_numerals.h"
#include "macro_defer.h"

int printf(const char* format, ...);

typedef void* vtable_t;

typedef const char* string; 
/*  UTIL  */
#define ID(x) x
#define SKIP1(_) 
#define CAT(x, y) CAT_(x,y)
#define CAT_(x,y) x##y
#define PAIR(x,y) PAIR_(x,y)
#define PAIR_(x,y) CAT_(x, _## y)

/*  CLASS DECL UTIL */
#define _ROOT() _ROOT
#define C_NAME( DESCR ) DESCR( ID, SKIP1, SKIP1, SKIP1 )
#define C_BASE( DESCR ) DESCR( SKIP1, C_NAME, SKIP1, SKIP1 )
#define C_BASEDESCR( DESCR ) DESCR( SKIP1, ID, SKIP1, SKIP1 )
#define C_AS_CLASS( DESCR )  C_NAME( DESCR ) PAIR(as, C_NAME(DESCR));
#define FOR_BASEDESCR( DESCR, DO ) DESCR( SKIP1, OBSTRUCT(DO), SKIP1, SKIP1 )


#define DECLARE_BASE(DESCR) OBSTRUCT( IF_BASE_ELSE(DESCR, DECLARE_BASE_))(DESCR)
#define DECLARE_BASE_(DESCR) FOR_BASEDESCR( DESCR, C_AS_CLASS )
#define DECLARE_BASE__ROOT(DESCR) 

#define GET_BASE(DESCR) DESCR(SKIP1, SKIP1, SKIP1, _ROOT)
#define IF_BASE_ELSE(DESCR, ACTIONS) CAT(ACTIONS, GET_BASE(DESCR))

/* METHOD */
#define METHOD_OF_NAME(VMETHOD) (METHOD_CLASS_NAME(VMETHOD) , METHOD_NAME(VMETHOD))

#define METHOD_CLASS_NAME(VMETHOD) C_NAME(METHOD_OF(VMETHOD))
#define METHOD_OF(METHOD) METHOD(SKIP1, ID, SKIP2, SKIP1, SKIP1)
#define METHOD_NAME(METHOD) METHOD(ID, SKIP1, SKIP2, SKIP1, SKIP1)
#define METHOD_RETURNS(METHOD) METHOD( SKIP1, SKIP1, SKIP2, ID, SKIP1)
#define TO_ARG(t, n) , t  n 


#define CLASS( DESCR )\
    VTABLE_TYPE_NAME(DESCR);\
    typedef union C_NAME( DESCR ) C_NAME(DESCR);\
    typedef  VTABLE_TYPE_NAME(DESCR) CAT(C_NAME(DESCR), _vtable_t);\
    VTABLE(DESCR)\
    union C_NAME( DESCR ){\
        VTABLE_TYPE_NAME(DESCR) vtable;\
        struct {\
            EVAL(DECLARE_BASE(DESCR))\
        };\
    };\
    EVAL(DESCR(SKIP1, SKIP1, DEFINE_METHOD, SKIP1))
    


#define DEFINE_METHOD(VMETHOD) METHOD_RETURNS(VMETHOD) PAIR( METHOD_OF(VMETHOD), METHOD_NAME(VMETHOD)) (\
         OBSTRUCT(CAT(VMETHOD( SKIP1, ID, SKIP2, SKIP1, SKIP1), _END))()\
        (ID, SKIP1,SKIP1, SKIP1 )*)      \
                VMETHOD(SKIP1, SKIP1, TO_ARG, SKIP1, SKIP1) ;

#define VTABLE_TYPE_NAME(DESCR) struct PAIR(C_NAME(DESCR), vtable_t) 

#define VTABLE_NAME(DESCR) PAIR(C_NAME(DESCR), vtable) 
#define CLASS_VTABLE_REF(DESCR) VTABLE_TYPE_NAME(DESCR) VTABLE_NAME(DESCR);

#define VTABLE_ENTRY_ARG(t, n) t,
#define METHOD_OBJECT_NAME(VMETHOD) EVAL( METHOD_OBJECT_NAME_(VMETHOD) ) 
#define METHOD_OBJECT_NAME_(VMETHOD) OBSTRUCT(CAT(VMETHOD( SKIP1, ID, SKIP2, SKIP1, SKIP1), _END))() (ID, SKIP1,SKIP1, SKIP1 )

#define FLIP(x,y) y,x

#define METHOD_FULL_NAME(M)  FLIP(METHOD_OBJECT_NAME(VMETHOD), METHOD_NAME(VMETHOD ))


#define VTABLE_ENTRY(VMETHOD) METHOD_RETURNS(VMETHOD) (* METHOD_NAME(VMETHOD) ) (\
         OBSTRUCT(CAT(VMETHOD( SKIP1, ID, SKIP2, SKIP1, SKIP1), _END))() (ID, SKIP1,SKIP1, SKIP1 )*      \
                VMETHOD(SKIP1, SKIP1, TO_ARG, SKIP1, SKIP1)) ;


/*  For all base classes, insert their respective vtables
 *  For all methods, insert function pointers on them */
#define VTABLE(DESCR)  VTABLE_TYPE_NAME(DESCR) {\
    EVAL(FOR_BASEDESCR(DESCR, CLASS_VTABLE_REF) )  \
    EVAL(DESCR(SKIP1, SKIP1, VTABLE_ENTRY, SKIP1))\
} VTABLE_NAME(DESCR);



#define CLASS_VTABLE(DESCR) DESCR(SKIP1, SKIP1, VTABLE_ENTRY, SKIP1 )

/*  EXAMPLE  */
#define OBJECT_TOSTRING( NAME, OF, ARG, RETURNS, BODY ) \
    NAME( tostring )\
    OF(OBJECT)\
    RETURNS( string )\
    BODY( { return "Object"; })

#define A_TOSTRING( NAME, OF, ARG, RETURNS, BODY ) \
    NAME( tostring )\
    OF(A)\
    RETURNS( string )\
    BODY( { return "A"; })

#define B_TOSTRING( NAME, OF, ARG, RETURNS, BODY ) \
    NAME( tostring )\
    OF(B)\
    RETURNS( string )\
    BODY( { return "B"; })

#define C_TOSTRING( NAME, OF, ARG, RETURNS, BODY ) \
    NAME( tostring )\
    OF(C)\
    RETURNS( string )\
    BODY( { return "C"; })

#define OBJECT( NAME, BASE, VMETHOD, IS_BASE )\
    IS_BASE()\
    NAME( object )\
    VMETHOD( OBJECT_TOSTRING )

#define OBJECT_END() OBJECT

#define A( NAME, BASE, VMETHOD, IS_BASE )\
    BASE( OBJECT )\
    VMETHOD( A_TOSTRING )\
    NAME( a )

#define A_END() A

#define B( NAME, BASE, VMETHOD, IS_BASE)\
    BASE( OBJECT )\
    VMETHOD( B_TOSTRING )\
    NAME( b )
#define B_END() B

#define C( NAME, BASE, VMETHOD, IS_BASE)\
    BASE( A )\
    BASE( B )\
    VMETHOD( B_TOSTRING )\
    NAME( c )
#define C_END() C


CLASS(OBJECT)

    METHOD_FULL_NAME(OBJECT_TOSTRING)

a a_init(void){
    a this;
    this.vtable = a_vtable; 
    return a;
}

void vtable_object_init() {

}
void vtable_a_init() {
    a_vtable.object_vtable = object_vtable;
    a_vtable.object_vtable.tostring = a_vtable.tostring;
}


void puts(const char* );

int main(void) {
    a mya;
    puts( mya.vtable.tostring(&mya) );
return 0;
}
