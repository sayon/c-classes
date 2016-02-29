#define id(x) x
#define _1(q) 
#define _2(q,w) 
#define _3(q,w,e) 
#define _4(q,w,e,r) 
#define _field(t, n, dv, fs) t n;

#define pair(x,y) pair_(x,y)
#define pair_(x,y) x ## _ ## y
 
#define classname(descr) descr(id, _1, _4, _1, _3)
#define classbase(descr) descr(_1, id, _4, _1, _3)
#define for_base(descr, f) descr(_1, f, _4, _1, _3)
#define for_fields(descr, f) descr(_1, _1, f, _1, _3)
#define for_vmethods(descr, f) descr(_1, _1, _4, f, _3)
#define for_override(descr, f) descr(_1, _1, _4, _1, f)

#define _field_init( t, n, v, _ ) this.n = v;
 
#define ctor_name(descr) pair(classname(descr), init)

#define default_ctor_proto(descr) \
    classname(descr) ctor_name(descr) (void)

#define base_ctor_call(bdescr) this.pair(as,classname(bdescr)) =\
 pair(classname(bdescr), init)();
#define default_ctor(descr)  default_ctor_proto(descr) {\
            classname(descr) this; \
            descr(_1, base_ctor_call, _4,_1, _3)\
            descr(_1, _1,_field_init,_1, _3)\
            this.vtable = & vtable_instance(descr);\
            return this; \
    }

#define declare_base( descr ) classname(descr) pair(as, classname(descr));

#define vtable_name(descr) pair(classname(descr), vtable)

#define m_name( m ) m(id, _1, _2, _1, _1 )
#define m_of( m ) m(_1, id, _2, _1, _1 )
#define m_for_args( m, f ) m(_1, _1, f, _1, _1 )
#define m_returns( m ) m(_1, _1, _2, id, _1 )
#define m_body( m ) m(_1, _1, _2, _1, id )
#define m_arg_def( t, n ) , t n

#define m_proto( m ) m_returns(m) pair(_vt, pair(m_of(m), m_name(m)))\
    ( m_of(m)* this \
        m_for_args(m, m_arg_def) )

#define method_def( m ) m_proto(m) { m_body(m) } 

#define vmethod_entry( m ) m_returns(m) (*m_name(m))( m_of(m) * \
        m_for_args(m, m_arg_def) );

#define vtable_base_def(descr)  struct vtable_name(descr) vtable_base;
#define vtable_instance(descr) pair(vtable_name(descr),inst)

#define declarations(descr) \
    struct vtable_name(descr);\
    union classname(descr);\
    typedef union classname(descr) classname(descr);\
    typedef struct vtable_name(descr) vtable_name(descr);

#define vtable(descr) \
    struct vtable_name(descr) {\
    descr(_1, vtable_base_def, _4, _1, _3)\
descr(_1, _1, _4, vmethod_entry , _3)\
} vtable_instance(descr);

#define call_vtable_base(descr) pair(vtable_name(descr),init)(); 
#define init_base_vtable_part(descr) vt->vtable_base = vtable_instance(descr);

#define vtable_init_member(m) pair(m_of(m) , vtable_inst).m_name(m ) = pair(_vt,pair( m_of(m), m_name(m)));

#define vtable_override( baseentry, name, overridden) ((baseentry ## _vtable*)vt)->name = \
    pair(_vt, overridden);

#define vtable_init(descr) void pair(vtable_name(descr),init)(void) {\
    descr(_1, call_vtable_base, _4, _1, _3)\
    vtable_name(descr) * const vt = &vtable_instance(descr);\
    for_base(descr, init_base_vtable_part)\
    for_vmethods( descr, vtable_init_member)\
    for_override( descr, vtable_override )\
}

#define override_method_def(baseentry, name, overridden) method_def(overridden)

#define m_caller(m) m_returns(m) \
    (*pair(vt, pair( m_of(m), m_name(m)))(m_of(m)* this m_for_args(m, m_arg_def)))(m_of(m)*) { return this->vtable->m_name(m); }

#define class(descr) \
    declarations(descr)\
    vtable(descr)\
        union classname(descr) {\
        vtable_name(descr) * vtable;\
        struct {\
        descr(_1, declare_base, _4, _1, _3)\
		descr( _1, _1,  _field, _1, _3)\
        };\
};\
default_ctor( descr )\
for_vmethods(descr, method_def)\
for_override(descr, override_method_def)\
for_vmethods(descr, m_caller)\
vtable_init(descr)


#define object_tostring(name, of, arg, returns, body) \
    name( tostring ) of( object ) returns( const char* )\
    body( { return "Object or A"; } )

#define b_tostring(name, of, arg, returns, body) \
    name( tostring ) of( b ) returns( const char* )\
    body( { return "B"; } )

#define class_object(name, extends, public_field, vmethod, override)\
    name( object )\
    public_field( int, x, 0, "%d" )\
    vmethod( object_tostring )

#define class_a(name, extends, public_field, vmethod, override)\
    name( a )\
    extends( class_object )\
    public_field( int, y, 0, "%d" )\

#define class_b(name, extends, public_field, vmethod, override)\
    name( b )\
    extends( class_a )\
    public_field( int, z, 0, "%d" )\
    override( object, tostring, b_tostring )


class( class_object )

class( class_a )


class( class_b )



void puts(const char*);
int main() {
    object_vtable_init();
    a_vtable_init();
    b_vtable_init();
    b myb = b_init();
    a mya = a_init();
    puts(vt_object_tostring( (object*)&myb)((object*)&myb));
    puts(vt_object_tostring( (object*)&mya)((object*)&mya));
    return 0;
}


