typedef struct {
    object parent;
    int x;
    float y;
    union {
        struct {
            int _x;
            float _y;
        };
        char stub[sizeof(struct {
                int _x;
                float _y;
                } )];
    };
} mc ;
mc mc_init ( mc * this ,int x ,float y ,int _x ,float _y ){
    mc instance;
    this->x = x;
    this->y = y;
    this->_x = _x;
    this->_y = _y;
    return instance;
} void mc_to_file ( mc * this, FILE* f ) {
    fprintf( f, "int" " " "x" " = " "\"%d\"" "\n", this-> x );
    fprintf( f, "float" " " "y" " = " "\"%f\"" "\n", this-> y );
    fprintf( f, "int" " " "_x" " = " "\"%d\"" "\n", this-> _x );
    fprintf( f, "float" " " "_y" " = " "\"%f\"" "\n", this-> _y );
} int mc_somemethod ( mc * this ,int a ,int b ) {
    return this->x + this->y + this->_y +this->_x + a + b;
}

typedef struct {
    mc parent;
    int z;
    union {
        struct {
        };
        char stub[sizeof(struct {
                } )];
    };
} child ;
child child_init ( child * this ,int z ){
    child instance;
    this->z = z;
    return instance;
} void child_to_file ( child * this, FILE* f ) {
    fprintf( f, "int" " " "z" " = " "\"%d\"" "\n", this-> z );
}
# 3 "class_example.c" 2

