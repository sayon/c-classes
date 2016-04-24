typedef unsigned long size_t;

struct vector_int {
    size_t length;
    char __stub__[sizeof(struct {size_t capacity; int* buffer; })];
};
