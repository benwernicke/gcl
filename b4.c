#include <stdio.h>
#include <gcl/type.h>
#include <string.h>
#include <ctype.h>

static inline u32 
fnv_hash(const char* s)
{
    uintptr_t h = 2166136261;
    for (; *s; s++) {
        h *= 16777619;
        h ^= *s;
    }
    return h;
}

static inline bool is_eq_str
(const char* a, const char* b) 
{ return strcmp(a, b) == 0; }

#define GCL_PREFIX map
#define GCL_TYPE Map
#define GCL_KEY_TYPE char*
#define GCL_VALUE_TYPE u32
#define GCL_HASH_FUNCTION fnv_hash
#define GCL_IS_EQUAL_FUNCTION is_eq_str
#define GCL_IMPLEMENTATION
#include MAP

static char* 
read_file(const char* path_name)
{
    FILE* f = fopen(path_name, "r");
    fseek(f, 0, SEEK_END);
    u64 l = ftell(f);
    rewind(f);
    char* s = malloc(l + 2);
    fread(s, 1, l, f);
    s[l] = 0;
    s[l + 1] = 0;
    fclose(f);
    return s;
}

static void
first_word(char* s, char** start, char** end)
{
    for (; isspace(*s); ++s) {  }
    if (!*s) {
        *start = NULL;
        return;
    }
    *start = s;
    for (; *s && !isspace(*s); ++s) {  }
    *end = s;
}

int
main(int argc, char** argv)
{
    char* file_content = read_file(argv[1]);

    Map* m = map_create();

    char* s;
    char* e;
    first_word(file_content, &s, &e);
    for (; s; first_word(e, &s, &e)) {
        *e++ = 0;
        u32* v = map_get_or_insert(m, s, 0);
        if (*v == 10) {
            map_remove(m, s);
        } else {
            *v += 1;
        }
    }

    {
        void* iter = map_iter_begin(m);
        void* const end = map_iter_end(m);
        for (; iter != end; iter = map_iter_next(iter)) {
            printf("%s:\r\t\t\t%u\n", 
                    *map_iter_key(iter),
                    *map_iter_value(iter)
                );
        }
    }

    free(file_content);
    map_free(m);
    return 0;
}
