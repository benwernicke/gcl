#include <gcl/type.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

static inline u32 
fnv_hash(const char* s)
{
    u32 h = 97;
    for (; *s; ++s) {
        h *= 103;
        h ^= *s;
    }
    return h;
}

static inline bool
is_equal(const char* a, const char* b)
{
    return strcmp(a, b) == 0;
}

#define GCL_TYPE Map
#define GCL_PREFIX map
#define GCL_KEY_TYPE char*
#define GCL_VALUE_TYPE u32
#define GCL_HASH_FUNCTION fnv_hash
#define GCL_IS_EQUAL_FUNCTION is_equal
#define GCL_IMPLEMENTATION
#include MAP

#define TEST_START() do { printf("[test] %s\n", __func__); } while (0)
#define TEST_END() do { puts("\tok"); } while (0)

static void
create_free(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);
    assert(map_size(m) == 0);
    assert(map_capacity(m) >= map_size(m));
    map_free(m);
    TEST_END();
}

static void
init_deinit(void)
{
    TEST_START();
    Map m_;
    Map* m = &m_;
    assert(map_init(m) == 0);
    assert(map_size(m) == 0);
    assert(map_capacity(m) >= map_size(m));
    map_deinit(m);
    TEST_END();
}

static void
insert_get(void)
{
    TEST_START();
    Map* m = map_create();

    assert(map_insert(m, "00", 0) == 0);
    assert(map_insert(m, "01", 1) == 0);
    assert(map_insert(m, "02", 2) == 0);
    assert(map_insert(m, "03", 3) == 0);
    assert(map_insert(m, "04", 4) == 0);
    assert(map_insert(m, "05", 5) == 0);
    assert(map_insert(m, "06", 6) == 0);
    assert(map_insert(m, "07", 7) == 0);
    assert(map_insert(m, "08", 8) == 0);
    assert(map_insert(m, "09", 9) == 0);
    assert(map_insert(m, "10", 10) == 0);
    assert(map_insert(m, "11", 11) == 0);
    assert(map_insert(m, "12", 12) == 0);
    assert(map_insert(m, "13", 13) == 0);
    assert(map_insert(m, "14", 14) == 0);
    assert(map_insert(m, "15", 15) == 0);
    assert(map_insert(m, "16", 16) == 0);
    assert(map_insert(m, "17", 17) == 0);
    assert(map_insert(m, "18", 18) == 0);
    assert(map_insert(m, "19", 19) == 0);
    assert(map_insert(m, "20", 20) == 0);
    assert(map_insert(m, "21", 21) == 0);
    assert(map_insert(m, "22", 22) == 0);
    assert(map_insert(m, "23", 23) == 0);
    assert(map_insert(m, "24", 24) == 0);
    assert(map_insert(m, "25", 25) == 0);
    assert(map_insert(m, "26", 26) == 0);
    assert(map_insert(m, "27", 27) == 0);
    assert(map_insert(m, "28", 28) == 0);
    assert(map_insert(m, "29", 29) == 0);

    assert(*map_get(m, "00") == 0);
    assert(*map_get(m, "01") == 1);
    assert(*map_get(m, "02") == 2);
    assert(*map_get(m, "03") == 3);
    assert(*map_get(m, "04") == 4);
    assert(*map_get(m, "05") == 5);
    assert(*map_get(m, "06") == 6);
    assert(*map_get(m, "07") == 7);
    assert(*map_get(m, "08") == 8);
    assert(*map_get(m, "09") == 9);
    assert(*map_get(m, "10") == 10);
    assert(*map_get(m, "11") == 11);
    assert(*map_get(m, "12") == 12);
    assert(*map_get(m, "13") == 13);
    assert(*map_get(m, "14") == 14);
    assert(*map_get(m, "15") == 15);
    assert(*map_get(m, "16") == 16);
    assert(*map_get(m, "17") == 17);
    assert(*map_get(m, "18") == 18);
    assert(*map_get(m, "19") == 19);
    assert(*map_get(m, "20") == 20);
    assert(*map_get(m, "21") == 21);
    assert(*map_get(m, "22") == 22);
    assert(*map_get(m, "23") == 23);
    assert(*map_get(m, "24") == 24);
    assert(*map_get(m, "25") == 25);
    assert(*map_get(m, "26") == 26);
    assert(*map_get(m, "27") == 27);
    assert(*map_get(m, "28") == 28);
    assert(*map_get(m, "29") == 29);

    map_free(m);

    TEST_END();
}

static void 
get_or_insert(void)
{
    TEST_START();
    Map* m = map_create();

    assert(*map_get_or_insert(m, "00", 0) == 0);
    assert(*map_get_or_insert(m, "01", 1) == 1);
    assert(*map_get_or_insert(m, "02", 2) == 2);
    assert(*map_get_or_insert(m, "03", 3) == 3);
    assert(*map_get_or_insert(m, "04", 4) == 4);
    assert(*map_get_or_insert(m, "05", 5) == 5);
    assert(*map_get_or_insert(m, "06", 6) == 6);
    assert(*map_get_or_insert(m, "07", 7) == 7);
    assert(*map_get_or_insert(m, "08", 8) == 8);
    assert(*map_get_or_insert(m, "09", 9) == 9);
    assert(*map_get_or_insert(m, "10", 10) == 10);
    assert(*map_get_or_insert(m, "11", 11) == 11);
    assert(*map_get_or_insert(m, "12", 12) == 12);
    assert(*map_get_or_insert(m, "13", 13) == 13);
    assert(*map_get_or_insert(m, "14", 14) == 14);
    assert(*map_get_or_insert(m, "15", 15) == 15);
    assert(*map_get_or_insert(m, "16", 16) == 16);
    assert(*map_get_or_insert(m, "17", 17) == 17);
    assert(*map_get_or_insert(m, "18", 18) == 18);
    assert(*map_get_or_insert(m, "19", 19) == 19);
    assert(*map_get_or_insert(m, "20", 20) == 20);
    assert(*map_get_or_insert(m, "21", 21) == 21);
    assert(*map_get_or_insert(m, "22", 22) == 22);
    assert(*map_get_or_insert(m, "23", 23) == 23);
    assert(*map_get_or_insert(m, "24", 24) == 24);
    assert(*map_get_or_insert(m, "25", 25) == 25);
    assert(*map_get_or_insert(m, "26", 26) == 26);
    assert(*map_get_or_insert(m, "27", 27) == 27);
    assert(*map_get_or_insert(m, "28", 28) == 28);
    assert(*map_get_or_insert(m, "29", 29) == 29);

    assert(*map_get_or_insert(m, "00", 0) == 0);
    assert(*map_get_or_insert(m, "01", 0) == 1);
    assert(*map_get_or_insert(m, "02", 0) == 2);
    assert(*map_get_or_insert(m, "03", 0) == 3);
    assert(*map_get_or_insert(m, "04", 0) == 4);
    assert(*map_get_or_insert(m, "05", 0) == 5);
    assert(*map_get_or_insert(m, "06", 0) == 6);
    assert(*map_get_or_insert(m, "07", 0) == 7);
    assert(*map_get_or_insert(m, "08", 0) == 8);
    assert(*map_get_or_insert(m, "09", 0) == 9);
    assert(*map_get_or_insert(m, "10", 0) == 10);
    assert(*map_get_or_insert(m, "11", 0) == 11);
    assert(*map_get_or_insert(m, "12", 0) == 12);
    assert(*map_get_or_insert(m, "13", 0) == 13);
    assert(*map_get_or_insert(m, "14", 0) == 14);
    assert(*map_get_or_insert(m, "15", 0) == 15);
    assert(*map_get_or_insert(m, "16", 0) == 16);
    assert(*map_get_or_insert(m, "17", 0) == 17);
    assert(*map_get_or_insert(m, "18", 0) == 18);
    assert(*map_get_or_insert(m, "19", 0) == 19);
    assert(*map_get_or_insert(m, "20", 0) == 20);
    assert(*map_get_or_insert(m, "21", 0) == 21);
    assert(*map_get_or_insert(m, "22", 0) == 22);
    assert(*map_get_or_insert(m, "23", 0) == 23);
    assert(*map_get_or_insert(m, "24", 0) == 24);
    assert(*map_get_or_insert(m, "25", 0) == 25);
    assert(*map_get_or_insert(m, "26", 0) == 26);
    assert(*map_get_or_insert(m, "27", 0) == 27);
    assert(*map_get_or_insert(m, "28", 0) == 28);
    assert(*map_get_or_insert(m, "29", 0) == 29);

    map_free(m);
    TEST_END();
}

int main(void)
{
    create_free();
    init_deinit();
    insert_get();
    get_or_insert();
    return 0;
}
