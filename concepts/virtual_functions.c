#include <stdlib.h>
#include <stdio.h>

typedef void* vtable_t;
typedef struct { vtable_t* vtable; } Object;

typedef struct Parent {
    Object base;
    /// virtual void print() { puts("P"); }
} Parent;


void Parent_print(Parent* this) { puts ("P"); }

typedef struct Child {
    Parent base;
} Child;

void Child_print(Parent* this) { puts ("C"); }

static struct {
   void (*print)(Parent* this);
} Parent_vtable;

static struct {
   void (*print)(Parent* this);
} Child_vtable;

void vt_print(Parent* this) {
    void (* fptr)(Parent*) = ((Object*)this)->vtable[0];
    fptr(this);
}
void vt_child(Child* this) {
    void (* fptr)(Child*) = ((Object*)this)->vtable[0];
    fptr(this);
}
