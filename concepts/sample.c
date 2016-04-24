# 1 "vtables.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 312 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "vtables.c" 2
# 1 "./church_numerals.h" 1
# 2 "vtables.c" 2
# 1 "./macro_defer.h" 1
# 3 "vtables.c" 2

int printf(const char* format, ...);

typedef void* vtable_t;

typedef const char* string;
# 132 "vtables.c"
struct object_vtable_t; typedef union object object ; typedef struct object_vtable_t object_vtable_t; struct object_vtable_t { string (* tostring ) ( object *) ;} object_vtable; union object { struct object_vtable_t vtable; struct { }; };
struct a_vtable_t; typedef union a a; typedef struct a_vtable_t a_vtable_t; struct a_vtable_t { struct object_vtable_t object_vtable; string (* tostring ) ( a*) ;} a_vtable; union a{ struct a_vtable_t vtable; struct { object as_object; }; };
struct b_vtable_t; typedef union b b; typedef struct b_vtable_t b_vtable_t; struct b_vtable_t { struct object_vtable_t object_vtable; string (* tostring ) ( b*) ;} b_vtable; union b{ struct b_vtable_t vtable; struct { object as_object; }; };
struct c_vtable_t; typedef union c c; typedef struct c_vtable_t c_vtable_t; struct c_vtable_t { struct a_vtable_t a_vtable; struct b_vtable_t b_vtable; string (* tostring ) ( b*) ;} c_vtable; union c{ struct c_vtable_t vtable; struct { a as_a; b as_b; }; };
