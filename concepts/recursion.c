#define EMPTY()
#define DEFER(id) id EMPTY()
#define EXPAND( x ) x 

#define A() 123

A() 
DEFER(A)() 
EXPAND(DEFER(A)()) 
