
/*  myclass_to_file( myclass* this, FILE* ) */

#define PRINT_FIELD( TYPE, NAME, _, SPEC ) fprintf( f, #TYPE " " #NAME " = " #SPEC "\n", this-> NAME );

#define TO_FILE_SIGNATURE( DESCR )\
    void PAIR( CLASS_NAME(DESCR), to_file ) ( CLASS_NAME(DESCR)* this,  FILE* f )

#define TO_FILE_PROTO( DESCR ) TO_FILE_SIGNATURE( DESCR );

#define TO_FILE_IMPL( DESCR ) TO_FILE_SIGNATURE( DESCR ) { FOR_ALL_FIELDS( DESCR, PRINT_FIELD ) }
