typedef unsigned long size_t;

struct vector_int {
    size_t length;
    struct {
        size_t capacity;
        int* buffer; 
    };
};
