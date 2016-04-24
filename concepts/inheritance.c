#define id(x) x
#define _1(q) 
#define _2(q,w) 
#define _3(q,w,e) 
#define _4(q,w,e,r) 
#define _field(t, n, dv, fs) t n;

#define pair(x,y) pair_(x,y)
#define pair_(x,y) x##_##y


#define _field_init( t, n, v, _ ) this.n = v;


#define ctor_name(descr) pair(classname(descr), init)

#define default_ctor_proto(descr) \
    classname(descr) ctor_name(descr) (void)

#define base_ctor_call(bdescr) this.pair(as,classname(bdescr)) = pair(classname(bdescr), init)();
#define default_ctor(descr)  default_ctor_proto(descr) {\
            classname(descr) this; \
            descr(_1, base_ctor_call, _4)\
            descr(_1, _1,_field_init)\
            return this; \
    }

#define classname(descr) descr(id, _1, _4)
#define classbase(descr) descr(_1, id, _4)

#define declare_base( descr ) classname(descr) pair(as, classname(descr));

#define class(descr) \
    typedef struct classname(descr) {\
        descr(_1, declare_base, _4)\
		descr( _1, _1,  _field )\
}  classname(descr);\
 default_ctor( descr )

#define class_object(name, extends, public_field)\
    name( object )\
    public_field( int, x, 0, "%d" )\

#define class_a(name, extends, public_field)\
    name( a )\
    extends( class_object )\
    public_field( int, x, 0, "%d" )

class( class_object )
class( class_a )
