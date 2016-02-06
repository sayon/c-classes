#include <stdlib.h>
#include <stdio.h>

typedef struct { void* vtable; } Object;

/*  Parent  */
typedef struct Parent {
    Object base;
    int value;
} Parent;

void __virtual__Parent_print(Parent* this) { puts ("P"); }

static struct Parent_vcall {
    void (*print)(Parent* this);
} Parent_vtable = { __virtual__Parent_print };

void Parent_init(Parent* this, int value) {
    ((Object*)this)->vtable = &Parent_vtable;
    this->value = value;
}

Parent* Parent_alloc(int value) {
    Parent* instance;
    instance = malloc( sizeof( Parent ) );
    Parent_init( instance, value );
    return instance;
}

/*  Child  */
typedef struct Child {
    Parent base;
    int value;
} Child;

void __virtual__Child_print(Child* this) { puts ("C"); }


static struct Child_vcall {
    void (*print)(Child*);
} Child_vtable = {  __virtual__Child_print };


void Child_init(Child* this, int value) {
    Parent_init( & this->base, 999 );
    ((Object*)this)->vtable = &Child_vtable;
    this->value = value;
}

Child* Child_alloc(int value) {
    Child* instance;
    instance = malloc( sizeof( Child ) );
    Child_init( instance, value );
    return instance;
}

struct Parent_vcall* Parent_virtual(Parent* obj) {
    return (struct Parent_vcall*) ((Object*)obj)->vtable;
}

struct Child_vcall* Child_virtual(Child* obj) {
    return (struct Child_vcall*) ((Object*)obj)->vtable;
}

int main() {
    Parent* mychild;
    Parent* myparent = Parent_alloc( 24 );
    mychild = (Parent*)Child_alloc( 42 );


    Parent_virtual(myparent)->print(myparent);
    Parent_virtual(mychild)->print(mychild);
    return 0;
}
