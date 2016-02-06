/*
 * Every object is a union of its contents AND all interfaces it implements
 */
/*
interface ISerializable {
    char* serialize( ISerializable* this );
}

class  C implements ISerializable implements Interface2 {
    int value;
    char* serialize( ISerializable* this ) {
        char* buffer = malloc( 64 );
        sprintf("C value: %d", value );
        return buffer;
    }
}
*/

#include <stdio.h>
#include <string.h>

union ISerializable {};

char* serialize( ISerializable* elem );


void to_file( ISerializable* something ) {
    char* b = serialize( something );
    fprintf( stdout, "%s", b );
    free(b);
}




