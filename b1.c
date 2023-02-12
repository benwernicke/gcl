#include <gcl/type.h>
#include <stdio.h>
#include <stdlib.h>

static inline u32
hash_i32(i32 a)
{
    uintptr_t h = 2166136261;

    h *= 16777619;
    h ^= ((i8*)&a)[0];

    h *= 16777619;
    h ^= ((i8*)&a)[1];

    h *= 16777619;
    h ^= ((i8*)&a)[2];

    h *= 16777619;
    h ^= ((i8*)&a)[3];

    return h;
}

static inline bool
is_eq_i32(i32 a, i32 b)
{
    return a == b;
}

#define GCL_TYPE Map
#define GCL_PREFIX map
#define GCL_KEY_TYPE i32
#define GCL_VALUE_TYPE u32
#define GCL_HASH_FUNCTION hash_i32
#define GCL_IS_EQUAL_FUNCTION is_eq_i32
#define GCL_IMPLEMENTATION
#include MAP

int
main(int argc, char** argv)
{
    Map* m = map_create();
    u64 N = atoll(argv[1]);
    srand(69);

    for (u64 i = 0; i < N; ++i) {
        i32 v = rand();
        *map_get_or_insert(m, v, 0) += 1;
    }

    {
        void* iter = map_iter_begin(m);
        void* const end = map_iter_end(m);
        for (; iter != end; iter = map_iter_next(iter)) {
            printf("%d\r\t\t%u\n", 
                    *map_iter_key(iter),
                    *map_iter_value(iter)
                );
        }
    }

    map_free(m);
    return 0;
}
