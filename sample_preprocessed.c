#include <stdio.h>

/* implementing virtual functions */

typedef void* vtable_t;

typedef struct { vtable_t vtable[]; } object;

static object object_init( object* obj ) {
   obj->vtable = 0; 
}

typedef struct { 
    object parent; 
    int x; 
    float y; 
    union {
        struct { 
            int _x; 
            float _y;
        };
        char stub[sizeof(struct { int _x; float _y; } )]; 
    };
} mc ; 


mc mc_init ( mc * this ,int x ,float y ,int _x ,float _y ){
    this->x = x;
    this->y = y;
    this->_x = _x; 
    this->_y = _y; 
    return this; 
} 





//todo
mc* mc_alloc( int x, float y, int _x, float _y ) {
    mc* instance = (mc*)malloc( sizeof( mc ) );
    mc_init( instance, x, y, _x, _y );
    return intance;
}
//todo
mc mc_stackalloc( int x, float y, int _x, float _y ) {
    mc instance;
    mc_init( &instance, x, y, _x, _y) ;
    return instance;
}

void mc_to_file ( mc * this, FILE* f ) { 
    fprintf( f, "int" " " "x" " = " "\"%d\"" "\n", this-> x );
    fprintf( f, "float" " " "y" " = " "\"%f\"" "\n", this-> y );
    fprintf( f, "int" " " "_x" " = " "\"%d\"" "\n", this-> _x ); 
    fprintf( f, "float" " " "_y" " = " "\"%f\"" "\n", this-> _y );
} 

int mc_somemethod ( mc * this ,int a ,int b ) { 
    return this->x + this->y + this->_y +this->_x + a + b;
}


/* TODO 
 * Better ctors
 * Dtors
 * Virtual functions
 * Interfaces
 * */
