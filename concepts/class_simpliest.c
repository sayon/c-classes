
#define class_mc( name, public_field, public_method) \
    name( mc )\
    public_field( int, x, 0, "%d" )\
    public_field( float, y, 0, "%f" )\
    public_method( somemethod )

#define somemethod(name, of, arg, returns, body )\
    name( somemethod ) of( mc ) returns( int )\
    arg( int, a )\
    arg( int, b )\
    body( { return this->x + this->y + a + b; } )


#define id(x) x
#define _1(q) 
#define _2(q,w) 
#define _3(q,w,e) 
#define _4(q,w,e,r) 
#define _field(t, n, dv, fs) t n;

#define classname(descr) descr(id, _4, _1)

#define class(descr) \
    typedef struct classname(descr) {\
		descr( _1, _field, _1)\
}  classname(descr);

class( class_mc)



