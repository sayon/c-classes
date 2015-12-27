#include "class_example.h"

int main() {
    mc c;
    mc_init(&c, 1,2.0f, 3, 4.0f  );
    mc_to_file(&c, stdout);
    return 0;
}
