# 1 "virtual_functions.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 310 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "virtual_functions.c" 2
# 133 "virtual_functions.c"
struct object_vtable;
union object ;
typedef union object object ;
typedef struct object_vtable object_vtable;
struct object_vtable { const char* (*tostring )( object * );
} object_vtable_inst;
union object { object_vtable * vtable;
    struct { int x;
    };
};
object object_init (void) { object this;
    this.x = 0;
    this.vtable = & object_vtable_inst;
    return this;
} 

const char* _vt_object_tostring ( object * this ) { { 
    return "Object or A";
} } 

const char* (*vt_object_tostring( object * this ))( object *) {
    return this->vtable->tostring ;
}
void object_vtable_init(void) { 
    object_vtable * const vt = &object_vtable_inst;
    object_vtable_inst.tostring = _vt_object_tostring;
}

struct a_vtable;
union a ;
typedef union a a ;
typedef struct a_vtable a_vtable;
struct a_vtable {
    struct object_vtable vtable_base;
} a_vtable_inst;

union a { 
    a_vtable * vtable;
    struct { 
        object as_object;
        int y;
    };
};

a a_init (void) { a this;
    this.as_object = object_init();
    this.y = 0;
    this.vtable = & a_vtable_inst;
    return this;
} void a_vtable_init(void) { object_vtable_init();
    a_vtable * const vt = &a_vtable_inst;
    vt->vtable_base = object_vtable_inst;
}


struct b_vtable;
union b ;
typedef union b b ;
typedef struct b_vtable b_vtable;
struct b_vtable { 
    struct a_vtable vtable_base;
} b_vtable_inst;
union b { 
    b_vtable * vtable;
    struct { a as_a;
        int z;
    };
};

b b_init (void) { b this;
    this.as_a = a_init();
    this.z = 0;
    this.vtable = & b_vtable_inst;
    return this;
} const char* _vt_b_tostring ( b * this ) { { return "B";
} }

void b_vtable_init(void) { a_vtable_init();
    b_vtable * const vt = &b_vtable_inst;
    vt->vtable_base = a_vtable_inst;
    (( object_vtable*)vt)->tostring = _vt_b_tostring;
}

void puts(const char*);

int main() {
    b myb;
    a mya;
    myb = b_init();
    mya = a_init();
    object_vtable_init();
    a_vtable_init();
    b_vtable_init();
    /*  outputs "B" */
    puts(vt_object_tostring( (object*)&myb)((object*)&myb));
    /*  outputs "Object or A" */
    puts(vt_object_tostring( (object*)&mya)((object*)&mya));

    return 0;

}
