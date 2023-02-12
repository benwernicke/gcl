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

    assert(!map_get(m, "00"));
    assert(!map_get(m, "01"));
    assert(!map_get(m, "02"));
    assert(!map_get(m, "03"));
    assert(!map_get(m, "04"));
    assert(!map_get(m, "05"));
    assert(!map_get(m, "06"));
    assert(!map_get(m, "07"));
    assert(!map_get(m, "08"));
    assert(!map_get(m, "09"));
    assert(!map_get(m, "10"));
    assert(!map_get(m, "11"));
    assert(!map_get(m, "12"));
    assert(!map_get(m, "13"));
    assert(!map_get(m, "14"));
    assert(!map_get(m, "15"));
    assert(!map_get(m, "16"));
    assert(!map_get(m, "17"));
    assert(!map_get(m, "18"));
    assert(!map_get(m, "19"));
    assert(!map_get(m, "20"));
    assert(!map_get(m, "21"));
    assert(!map_get(m, "22"));
    assert(!map_get(m, "23"));
    assert(!map_get(m, "24"));
    assert(!map_get(m, "25"));
    assert(!map_get(m, "26"));
    assert(!map_get(m, "27"));
    assert(!map_get(m, "28"));
    assert(!map_get(m, "29"));

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

static void
contains(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

    assert(!map_contains(m, "00"));
    assert(!map_contains(m, "01"));
    assert(!map_contains(m, "02"));
    assert(!map_contains(m, "03"));
    assert(!map_contains(m, "04"));
    assert(!map_contains(m, "05"));
    assert(!map_contains(m, "06"));
    assert(!map_contains(m, "07"));
    assert(!map_contains(m, "08"));
    assert(!map_contains(m, "09"));
    assert(!map_contains(m, "10"));
    assert(!map_contains(m, "11"));
    assert(!map_contains(m, "12"));
    assert(!map_contains(m, "13"));
    assert(!map_contains(m, "14"));
    assert(!map_contains(m, "15"));
    assert(!map_contains(m, "16"));
    assert(!map_contains(m, "17"));
    assert(!map_contains(m, "18"));
    assert(!map_contains(m, "19"));
    assert(!map_contains(m, "20"));
    assert(!map_contains(m, "21"));
    assert(!map_contains(m, "22"));
    assert(!map_contains(m, "23"));
    assert(!map_contains(m, "24"));
    assert(!map_contains(m, "25"));
    assert(!map_contains(m, "26"));
    assert(!map_contains(m, "27"));
    assert(!map_contains(m, "28"));
    assert(!map_contains(m, "29"));

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

    assert(map_contains(m, "00"));
    assert(map_contains(m, "01"));
    assert(map_contains(m, "02"));
    assert(map_contains(m, "03"));
    assert(map_contains(m, "04"));
    assert(map_contains(m, "05"));
    assert(map_contains(m, "06"));
    assert(map_contains(m, "07"));
    assert(map_contains(m, "08"));
    assert(map_contains(m, "09"));
    assert(map_contains(m, "10"));
    assert(map_contains(m, "11"));
    assert(map_contains(m, "12"));
    assert(map_contains(m, "13"));
    assert(map_contains(m, "14"));
    assert(map_contains(m, "15"));
    assert(map_contains(m, "16"));
    assert(map_contains(m, "17"));
    assert(map_contains(m, "18"));
    assert(map_contains(m, "19"));
    assert(map_contains(m, "20"));
    assert(map_contains(m, "21"));
    assert(map_contains(m, "22"));
    assert(map_contains(m, "23"));
    assert(map_contains(m, "24"));
    assert(map_contains(m, "25"));
    assert(map_contains(m, "26"));
    assert(map_contains(m, "27"));
    assert(map_contains(m, "28"));
    assert(map_contains(m, "29"));

    map_free(m);
    TEST_END();
}

static void
size_capacity(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);
    assert(map_insert(m, "00", 0) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 1);

    assert(map_insert(m, "01", 1) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 2);

    assert(map_insert(m, "02", 2) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 3);

    assert(map_insert(m, "03", 3) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 4);

    assert(map_insert(m, "04", 4) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 5);

    assert(map_insert(m, "05", 5) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 6);

    assert(map_insert(m, "06", 6) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 7);

    assert(map_insert(m, "07", 7) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 8);

    assert(map_insert(m, "08", 8) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 9);

    assert(map_insert(m, "09", 9) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 10);

    assert(map_insert(m, "10", 10) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 11);

    assert(map_insert(m, "11", 11) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 12);

    assert(map_insert(m, "12", 12) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 13);

    assert(map_insert(m, "13", 13) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 14);

    assert(map_insert(m, "14", 14) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 15);

    assert(map_insert(m, "15", 15) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 16);

    assert(map_insert(m, "16", 16) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 17);

    assert(map_insert(m, "17", 17) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 18);

    assert(map_insert(m, "18", 18) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 19);

    assert(map_insert(m, "19", 19) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 20);

    assert(map_insert(m, "20", 20) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 21);

    assert(map_insert(m, "21", 21) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 22);

    assert(map_insert(m, "22", 22) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 23);

    assert(map_insert(m, "23", 23) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 24);

    assert(map_insert(m, "24", 24) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 25);

    assert(map_insert(m, "25", 25) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 26);

    assert(map_insert(m, "26", 26) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 27);

    assert(map_insert(m, "27", 27) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 28);

    assert(map_insert(m, "28", 28) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 29);

    assert(map_insert(m, "29", 29) == 0);
    assert(map_size(m) <= map_capacity(m));
    assert(map_size(m) == 30);

    map_free(m);
    TEST_END();
}

static void
reserve(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

    assert(map_size(m) == 0);
    assert(map_capacity(m) >= map_size(m));

    assert(map_reserve(m, 100) == 0);
    assert(map_capacity(m) >= 100);

    assert(map_size(m) == 0);

    map_free(m);
    TEST_END();
}

static void
shrink_to_fit(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

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

    u32 old_cap = map_capacity(m);
    assert(map_shrink_to_fit(m) == 0);

    // this is not a very good test
    // shrink to fit may make it larger or smaller
    assert(old_cap != map_capacity(m));

    map_free(m);
    TEST_END();
}

static void
get_key(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

    char s00[] = "00";
    char s01[] = "01";
    char s02[] = "02";
    char s03[] = "03";
    char s04[] = "04";
    char s05[] = "05";
    char s06[] = "06";
    char s07[] = "07";
    char s08[] = "08";
    char s09[] = "09";
    char s10[] = "10";
    char s11[] = "11";
    char s12[] = "12";
    char s13[] = "13";
    char s14[] = "14";
    char s15[] = "15";
    char s16[] = "16";
    char s17[] = "17";
    char s18[] = "18";
    char s19[] = "19";
    char s20[] = "20";
    char s21[] = "21";
    char s22[] = "22";
    char s23[] = "23";
    char s24[] = "24";
    char s25[] = "25";
    char s26[] = "26";
    char s27[] = "27";
    char s28[] = "28";
    char s29[] = "29";

    assert(map_get_key(m, "00") == NULL);
    assert(map_get_key(m, "01") == NULL);
    assert(map_get_key(m, "02") == NULL);
    assert(map_get_key(m, "03") == NULL);
    assert(map_get_key(m, "04") == NULL);
    assert(map_get_key(m, "05") == NULL);
    assert(map_get_key(m, "06") == NULL);
    assert(map_get_key(m, "07") == NULL);
    assert(map_get_key(m, "08") == NULL);
    assert(map_get_key(m, "09") == NULL);
    assert(map_get_key(m, "10") == NULL);
    assert(map_get_key(m, "11") == NULL);
    assert(map_get_key(m, "12") == NULL);
    assert(map_get_key(m, "13") == NULL);
    assert(map_get_key(m, "14") == NULL);
    assert(map_get_key(m, "15") == NULL);
    assert(map_get_key(m, "16") == NULL);
    assert(map_get_key(m, "17") == NULL);
    assert(map_get_key(m, "18") == NULL);
    assert(map_get_key(m, "19") == NULL);
    assert(map_get_key(m, "20") == NULL);
    assert(map_get_key(m, "21") == NULL);
    assert(map_get_key(m, "22") == NULL);
    assert(map_get_key(m, "23") == NULL);
    assert(map_get_key(m, "24") == NULL);
    assert(map_get_key(m, "25") == NULL);
    assert(map_get_key(m, "26") == NULL);
    assert(map_get_key(m, "27") == NULL);
    assert(map_get_key(m, "28") == NULL);
    assert(map_get_key(m, "29") == NULL);

    assert(map_insert(m, s00, 0) == 0);
    assert(map_insert(m, s01, 0) == 0);
    assert(map_insert(m, s02, 0) == 0);
    assert(map_insert(m, s03, 0) == 0);
    assert(map_insert(m, s04, 0) == 0);
    assert(map_insert(m, s05, 0) == 0);
    assert(map_insert(m, s06, 0) == 0);
    assert(map_insert(m, s07, 0) == 0);
    assert(map_insert(m, s08, 0) == 0);
    assert(map_insert(m, s09, 0) == 0);
    assert(map_insert(m, s10, 0) == 0);
    assert(map_insert(m, s11, 0) == 0);
    assert(map_insert(m, s12, 0) == 0);
    assert(map_insert(m, s13, 0) == 0);
    assert(map_insert(m, s14, 0) == 0);
    assert(map_insert(m, s15, 0) == 0);
    assert(map_insert(m, s16, 0) == 0);
    assert(map_insert(m, s17, 0) == 0);
    assert(map_insert(m, s18, 0) == 0);
    assert(map_insert(m, s19, 0) == 0);
    assert(map_insert(m, s20, 0) == 0);
    assert(map_insert(m, s21, 0) == 0);
    assert(map_insert(m, s22, 0) == 0);
    assert(map_insert(m, s23, 0) == 0);
    assert(map_insert(m, s24, 0) == 0);
    assert(map_insert(m, s25, 0) == 0);
    assert(map_insert(m, s26, 0) == 0);
    assert(map_insert(m, s27, 0) == 0);
    assert(map_insert(m, s28, 0) == 0);
    assert(map_insert(m, s29, 0) == 0);

    assert(*map_get_key(m, "00") == s00);
    assert(*map_get_key(m, "01") == s01);
    assert(*map_get_key(m, "02") == s02);
    assert(*map_get_key(m, "03") == s03);
    assert(*map_get_key(m, "04") == s04);
    assert(*map_get_key(m, "05") == s05);
    assert(*map_get_key(m, "06") == s06);
    assert(*map_get_key(m, "07") == s07);
    assert(*map_get_key(m, "08") == s08);
    assert(*map_get_key(m, "09") == s09);
    assert(*map_get_key(m, "10") == s10);
    assert(*map_get_key(m, "11") == s11);
    assert(*map_get_key(m, "12") == s12);
    assert(*map_get_key(m, "13") == s13);
    assert(*map_get_key(m, "14") == s14);
    assert(*map_get_key(m, "15") == s15);
    assert(*map_get_key(m, "16") == s16);
    assert(*map_get_key(m, "17") == s17);
    assert(*map_get_key(m, "18") == s18);
    assert(*map_get_key(m, "19") == s19);
    assert(*map_get_key(m, "20") == s20);
    assert(*map_get_key(m, "21") == s21);
    assert(*map_get_key(m, "22") == s22);
    assert(*map_get_key(m, "23") == s23);
    assert(*map_get_key(m, "24") == s24);
    assert(*map_get_key(m, "25") == s25);
    assert(*map_get_key(m, "26") == s26);
    assert(*map_get_key(m, "27") == s27);
    assert(*map_get_key(m, "28") == s28);
    assert(*map_get_key(m, "29") == s29);

    map_free(m);
    TEST_END();
}

static void
update_key(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

    char a00[] = "00";
    char a01[] = "01";
    char a02[] = "02";
    char a03[] = "03";
    char a04[] = "04";
    char a05[] = "05";
    char a06[] = "06";
    char a07[] = "07";
    char a08[] = "08";
    char a09[] = "09";
    char a10[] = "10";
    char a11[] = "11";
    char a12[] = "12";
    char a13[] = "13";
    char a14[] = "14";
    char a15[] = "15";
    char a16[] = "16";
    char a17[] = "17";
    char a18[] = "18";
    char a19[] = "19";
    char a20[] = "20";
    char a21[] = "21";
    char a22[] = "22";
    char a23[] = "23";
    char a24[] = "24";
    char a25[] = "25";
    char a26[] = "26";
    char a27[] = "27";
    char a28[] = "28";
    char a29[] = "29";

    char b00[] = "00";
    char b01[] = "01";
    char b02[] = "02";
    char b03[] = "03";
    char b04[] = "04";
    char b05[] = "05";
    char b06[] = "06";
    char b07[] = "07";
    char b08[] = "08";
    char b09[] = "09";
    char b10[] = "10";
    char b11[] = "11";
    char b12[] = "12";
    char b13[] = "13";
    char b14[] = "14";
    char b15[] = "15";
    char b16[] = "16";
    char b17[] = "17";
    char b18[] = "18";
    char b19[] = "19";
    char b20[] = "20";
    char b21[] = "21";
    char b22[] = "22";
    char b23[] = "23";
    char b24[] = "24";
    char b25[] = "25";
    char b26[] = "26";
    char b27[] = "27";
    char b28[] = "28";
    char b29[] = "29";

    assert(map_insert(m, a00, 0) == 0);
    assert(map_insert(m, a01, 0) == 0);
    assert(map_insert(m, a02, 0) == 0);
    assert(map_insert(m, a03, 0) == 0);
    assert(map_insert(m, a04, 0) == 0);
    assert(map_insert(m, a05, 0) == 0);
    assert(map_insert(m, a06, 0) == 0);
    assert(map_insert(m, a07, 0) == 0);
    assert(map_insert(m, a08, 0) == 0);
    assert(map_insert(m, a09, 0) == 0);
    assert(map_insert(m, a10, 0) == 0);
    assert(map_insert(m, a11, 0) == 0);
    assert(map_insert(m, a12, 0) == 0);
    assert(map_insert(m, a13, 0) == 0);
    assert(map_insert(m, a14, 0) == 0);
    assert(map_insert(m, a15, 0) == 0);
    assert(map_insert(m, a16, 0) == 0);
    assert(map_insert(m, a17, 0) == 0);
    assert(map_insert(m, a18, 0) == 0);
    assert(map_insert(m, a19, 0) == 0);
    assert(map_insert(m, a20, 0) == 0);
    assert(map_insert(m, a21, 0) == 0);
    assert(map_insert(m, a22, 0) == 0);
    assert(map_insert(m, a23, 0) == 0);
    assert(map_insert(m, a24, 0) == 0);
    assert(map_insert(m, a25, 0) == 0);
    assert(map_insert(m, a26, 0) == 0);
    assert(map_insert(m, a27, 0) == 0);
    assert(map_insert(m, a28, 0) == 0);
    assert(map_insert(m, a29, 0) == 0);

    assert(*map_get_key(m, a00) == a00);
    assert(*map_get_key(m, a01) == a01);
    assert(*map_get_key(m, a02) == a02);
    assert(*map_get_key(m, a03) == a03);
    assert(*map_get_key(m, a04) == a04);
    assert(*map_get_key(m, a05) == a05);
    assert(*map_get_key(m, a06) == a06);
    assert(*map_get_key(m, a07) == a07);
    assert(*map_get_key(m, a08) == a08);
    assert(*map_get_key(m, a09) == a09);
    assert(*map_get_key(m, a10) == a10);
    assert(*map_get_key(m, a11) == a11);
    assert(*map_get_key(m, a12) == a12);
    assert(*map_get_key(m, a13) == a13);
    assert(*map_get_key(m, a14) == a14);
    assert(*map_get_key(m, a15) == a15);
    assert(*map_get_key(m, a16) == a16);
    assert(*map_get_key(m, a17) == a17);
    assert(*map_get_key(m, a18) == a18);
    assert(*map_get_key(m, a19) == a19);
    assert(*map_get_key(m, a20) == a20);
    assert(*map_get_key(m, a21) == a21);
    assert(*map_get_key(m, a22) == a22);
    assert(*map_get_key(m, a23) == a23);
    assert(*map_get_key(m, a24) == a24);
    assert(*map_get_key(m, a25) == a25);
    assert(*map_get_key(m, a26) == a26);
    assert(*map_get_key(m, a27) == a27);
    assert(*map_get_key(m, a28) == a28);
    assert(*map_get_key(m, a29) == a29);

    assert(map_update_key(m, b00) == 0);
    assert(map_update_key(m, b01) == 0);
    assert(map_update_key(m, b02) == 0);
    assert(map_update_key(m, b03) == 0);
    assert(map_update_key(m, b04) == 0);
    assert(map_update_key(m, b05) == 0);
    assert(map_update_key(m, b06) == 0);
    assert(map_update_key(m, b07) == 0);
    assert(map_update_key(m, b08) == 0);
    assert(map_update_key(m, b09) == 0);
    assert(map_update_key(m, b10) == 0);
    assert(map_update_key(m, b11) == 0);
    assert(map_update_key(m, b12) == 0);
    assert(map_update_key(m, b13) == 0);
    assert(map_update_key(m, b14) == 0);
    assert(map_update_key(m, b15) == 0);
    assert(map_update_key(m, b16) == 0);
    assert(map_update_key(m, b17) == 0);
    assert(map_update_key(m, b18) == 0);
    assert(map_update_key(m, b19) == 0);
    assert(map_update_key(m, b20) == 0);
    assert(map_update_key(m, b21) == 0);
    assert(map_update_key(m, b22) == 0);
    assert(map_update_key(m, b23) == 0);
    assert(map_update_key(m, b24) == 0);
    assert(map_update_key(m, b25) == 0);
    assert(map_update_key(m, b26) == 0);
    assert(map_update_key(m, b27) == 0);
    assert(map_update_key(m, b28) == 0);
    assert(map_update_key(m, b29) == 0);

    assert(*map_get_key(m, a00) == b00);
    assert(*map_get_key(m, a01) == b01);
    assert(*map_get_key(m, a02) == b02);
    assert(*map_get_key(m, a03) == b03);
    assert(*map_get_key(m, a04) == b04);
    assert(*map_get_key(m, a05) == b05);
    assert(*map_get_key(m, a06) == b06);
    assert(*map_get_key(m, a07) == b07);
    assert(*map_get_key(m, a08) == b08);
    assert(*map_get_key(m, a09) == b09);
    assert(*map_get_key(m, a10) == b10);
    assert(*map_get_key(m, a11) == b11);
    assert(*map_get_key(m, a12) == b12);
    assert(*map_get_key(m, a13) == b13);
    assert(*map_get_key(m, a14) == b14);
    assert(*map_get_key(m, a15) == b15);
    assert(*map_get_key(m, a16) == b16);
    assert(*map_get_key(m, a17) == b17);
    assert(*map_get_key(m, a18) == b18);
    assert(*map_get_key(m, a19) == b19);
    assert(*map_get_key(m, a20) == b20);
    assert(*map_get_key(m, a21) == b21);
    assert(*map_get_key(m, a22) == b22);
    assert(*map_get_key(m, a23) == b23);
    assert(*map_get_key(m, a24) == b24);
    assert(*map_get_key(m, a25) == b25);
    assert(*map_get_key(m, a26) == b26);
    assert(*map_get_key(m, a27) == b27);
    assert(*map_get_key(m, a28) == b28);
    assert(*map_get_key(m, a29) == b29);

    map_free(m);
    TEST_END();
}

static void
mremove(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

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

    assert(map_size(m) == 30);

    assert(map_remove(m, "00") == 0);
    assert(map_remove(m, "01") == 0);
    assert(map_remove(m, "02") == 0);
    assert(map_remove(m, "03") == 0);
    assert(map_remove(m, "04") == 0);
    assert(map_remove(m, "05") == 0);
    assert(map_remove(m, "06") == 0);
    assert(map_remove(m, "07") == 0);
    assert(map_remove(m, "08") == 0);
    assert(map_remove(m, "09") == 0);
    assert(map_remove(m, "10") == 0);
    assert(map_remove(m, "11") == 0);
    assert(map_remove(m, "12") == 0);
    assert(map_remove(m, "13") == 0);
    assert(map_remove(m, "14") == 0);
    assert(map_remove(m, "15") == 0);
    assert(map_remove(m, "16") == 0);
    assert(map_remove(m, "17") == 0);
    assert(map_remove(m, "18") == 0);
    assert(map_remove(m, "19") == 0);
    assert(map_remove(m, "20") == 0);
    assert(map_remove(m, "21") == 0);
    assert(map_remove(m, "22") == 0);
    assert(map_remove(m, "23") == 0);
    assert(map_remove(m, "24") == 0);
    assert(map_remove(m, "25") == 0);
    assert(map_remove(m, "26") == 0);
    assert(map_remove(m, "27") == 0);
    assert(map_remove(m, "28") == 0);
    assert(map_remove(m, "29") == 0);

    assert(!map_contains(m, "00"));
    assert(!map_contains(m, "01"));
    assert(!map_contains(m, "02"));
    assert(!map_contains(m, "03"));
    assert(!map_contains(m, "04"));
    assert(!map_contains(m, "05"));
    assert(!map_contains(m, "06"));
    assert(!map_contains(m, "07"));
    assert(!map_contains(m, "08"));
    assert(!map_contains(m, "09"));
    assert(!map_contains(m, "10"));
    assert(!map_contains(m, "11"));
    assert(!map_contains(m, "12"));
    assert(!map_contains(m, "13"));
    assert(!map_contains(m, "14"));
    assert(!map_contains(m, "15"));
    assert(!map_contains(m, "16"));
    assert(!map_contains(m, "17"));
    assert(!map_contains(m, "18"));
    assert(!map_contains(m, "19"));
    assert(!map_contains(m, "20"));
    assert(!map_contains(m, "21"));
    assert(!map_contains(m, "22"));
    assert(!map_contains(m, "23"));
    assert(!map_contains(m, "24"));
    assert(!map_contains(m, "25"));
    assert(!map_contains(m, "26"));
    assert(!map_contains(m, "27"));
    assert(!map_contains(m, "28"));
    assert(!map_contains(m, "29"));

    assert(map_size(m) == 0);

    map_free(m);
    TEST_END();
}

static void 
move_pair(void)
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

    u32 dest_value;
    char* dest_key;

    assert(map_move_pair(m, "00", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "00") == 0);
    assert(dest_value == 0);

    assert(map_move_pair(m, "01", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "01") == 0);
    assert(dest_value == 1);

    assert(map_move_pair(m, "02", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "02") == 0);
    assert(dest_value == 2);

    assert(map_move_pair(m, "03", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "03") == 0);
    assert(dest_value == 3);

    assert(map_move_pair(m, "04", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "04") == 0);
    assert(dest_value == 4);

    assert(map_move_pair(m, "05", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "05") == 0);
    assert(dest_value == 5);

    assert(map_move_pair(m, "06", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "06") == 0);
    assert(dest_value == 6);

    assert(map_move_pair(m, "07", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "07") == 0);
    assert(dest_value == 7);

    assert(map_move_pair(m, "08", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "08") == 0);
    assert(dest_value == 8);

    assert(map_move_pair(m, "09", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "09") == 0);
    assert(dest_value == 9);

    assert(map_move_pair(m, "10", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "10") == 0);
    assert(dest_value == 10);

    assert(map_move_pair(m, "11", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "11") == 0);
    assert(dest_value == 11);

    assert(map_move_pair(m, "12", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "12") == 0);
    assert(dest_value == 12);

    assert(map_move_pair(m, "13", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "13") == 0);
    assert(dest_value == 13);

    assert(map_move_pair(m, "14", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "14") == 0);
    assert(dest_value == 14);

    assert(map_move_pair(m, "15", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "15") == 0);
    assert(dest_value == 15);

    assert(map_move_pair(m, "16", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "16") == 0);
    assert(dest_value == 16);

    assert(map_move_pair(m, "17", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "17") == 0);
    assert(dest_value == 17);

    assert(map_move_pair(m, "18", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "18") == 0);
    assert(dest_value == 18);

    assert(map_move_pair(m, "19", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "19") == 0);
    assert(dest_value == 19);

    assert(map_move_pair(m, "20", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "20") == 0);
    assert(dest_value == 20);

    assert(map_move_pair(m, "21", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "21") == 0);
    assert(dest_value == 21);

    assert(map_move_pair(m, "22", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "22") == 0);
    assert(dest_value == 22);

    assert(map_move_pair(m, "23", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "23") == 0);
    assert(dest_value == 23);

    assert(map_move_pair(m, "24", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "24") == 0);
    assert(dest_value == 24);

    assert(map_move_pair(m, "25", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "25") == 0);
    assert(dest_value == 25);

    assert(map_move_pair(m, "26", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "26") == 0);
    assert(dest_value == 26);

    assert(map_move_pair(m, "27", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "27") == 0);
    assert(dest_value == 27);

    assert(map_move_pair(m, "28", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "28") == 0);
    assert(dest_value == 28);

    assert(map_move_pair(m, "29", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "29") == 0);
    assert(dest_value == 29);

    assert(map_size(m) == 0);

    assert(!map_contains(m, "00"));
    assert(!map_contains(m, "01"));
    assert(!map_contains(m, "02"));
    assert(!map_contains(m, "03"));
    assert(!map_contains(m, "04"));
    assert(!map_contains(m, "05"));
    assert(!map_contains(m, "06"));
    assert(!map_contains(m, "07"));
    assert(!map_contains(m, "08"));
    assert(!map_contains(m, "09"));
    assert(!map_contains(m, "10"));
    assert(!map_contains(m, "11"));
    assert(!map_contains(m, "12"));
    assert(!map_contains(m, "13"));
    assert(!map_contains(m, "14"));
    assert(!map_contains(m, "15"));
    assert(!map_contains(m, "16"));
    assert(!map_contains(m, "17"));
    assert(!map_contains(m, "18"));
    assert(!map_contains(m, "19"));
    assert(!map_contains(m, "20"));
    assert(!map_contains(m, "21"));
    assert(!map_contains(m, "22"));
    assert(!map_contains(m, "23"));
    assert(!map_contains(m, "24"));
    assert(!map_contains(m, "25"));
    assert(!map_contains(m, "26"));
    assert(!map_contains(m, "27"));
    assert(!map_contains(m, "28"));
    assert(!map_contains(m, "29"));

    map_free(m);
    TEST_END();
}

static void 
copy_pair(void)
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

    u32 dest_value;
    char* dest_key;

    assert(map_copy_pair(m, "00", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "00") == 0);
    assert(dest_value == 0);

    assert(map_copy_pair(m, "01", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "01") == 0);
    assert(dest_value == 1);

    assert(map_copy_pair(m, "02", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "02") == 0);
    assert(dest_value == 2);

    assert(map_copy_pair(m, "03", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "03") == 0);
    assert(dest_value == 3);

    assert(map_copy_pair(m, "04", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "04") == 0);
    assert(dest_value == 4);

    assert(map_copy_pair(m, "05", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "05") == 0);
    assert(dest_value == 5);

    assert(map_copy_pair(m, "06", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "06") == 0);
    assert(dest_value == 6);

    assert(map_copy_pair(m, "07", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "07") == 0);
    assert(dest_value == 7);

    assert(map_copy_pair(m, "08", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "08") == 0);
    assert(dest_value == 8);

    assert(map_copy_pair(m, "09", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "09") == 0);
    assert(dest_value == 9);

    assert(map_copy_pair(m, "10", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "10") == 0);
    assert(dest_value == 10);

    assert(map_copy_pair(m, "11", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "11") == 0);
    assert(dest_value == 11);

    assert(map_copy_pair(m, "12", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "12") == 0);
    assert(dest_value == 12);

    assert(map_copy_pair(m, "13", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "13") == 0);
    assert(dest_value == 13);

    assert(map_copy_pair(m, "14", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "14") == 0);
    assert(dest_value == 14);

    assert(map_copy_pair(m, "15", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "15") == 0);
    assert(dest_value == 15);

    assert(map_copy_pair(m, "16", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "16") == 0);
    assert(dest_value == 16);

    assert(map_copy_pair(m, "17", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "17") == 0);
    assert(dest_value == 17);

    assert(map_copy_pair(m, "18", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "18") == 0);
    assert(dest_value == 18);

    assert(map_copy_pair(m, "19", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "19") == 0);
    assert(dest_value == 19);

    assert(map_copy_pair(m, "20", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "20") == 0);
    assert(dest_value == 20);

    assert(map_copy_pair(m, "21", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "21") == 0);
    assert(dest_value == 21);

    assert(map_copy_pair(m, "22", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "22") == 0);
    assert(dest_value == 22);

    assert(map_copy_pair(m, "23", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "23") == 0);
    assert(dest_value == 23);

    assert(map_copy_pair(m, "24", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "24") == 0);
    assert(dest_value == 24);

    assert(map_copy_pair(m, "25", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "25") == 0);
    assert(dest_value == 25);

    assert(map_copy_pair(m, "26", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "26") == 0);
    assert(dest_value == 26);

    assert(map_copy_pair(m, "27", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "27") == 0);
    assert(dest_value == 27);

    assert(map_copy_pair(m, "28", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "28") == 0);
    assert(dest_value == 28);

    assert(map_copy_pair(m, "29", &dest_key, &dest_value) == 0);
    assert(strcmp(dest_key, "29") == 0);
    assert(dest_value == 29);

    assert(map_size(m) == 30);

    assert(map_contains(m, "00"));
    assert(map_contains(m, "01"));
    assert(map_contains(m, "02"));
    assert(map_contains(m, "03"));
    assert(map_contains(m, "04"));
    assert(map_contains(m, "05"));
    assert(map_contains(m, "06"));
    assert(map_contains(m, "07"));
    assert(map_contains(m, "08"));
    assert(map_contains(m, "09"));
    assert(map_contains(m, "10"));
    assert(map_contains(m, "11"));
    assert(map_contains(m, "12"));
    assert(map_contains(m, "13"));
    assert(map_contains(m, "14"));
    assert(map_contains(m, "15"));
    assert(map_contains(m, "16"));
    assert(map_contains(m, "17"));
    assert(map_contains(m, "18"));
    assert(map_contains(m, "19"));
    assert(map_contains(m, "20"));
    assert(map_contains(m, "21"));
    assert(map_contains(m, "22"));
    assert(map_contains(m, "23"));
    assert(map_contains(m, "24"));
    assert(map_contains(m, "25"));
    assert(map_contains(m, "26"));
    assert(map_contains(m, "27"));
    assert(map_contains(m, "28"));
    assert(map_contains(m, "29"));

    map_free(m);
    TEST_END();
}

static void
iter(void)
{
    TEST_START();
    Map* m = map_create();
    assert(m);

    char* key_list[] = {
        "00", "01", "02", "03", "04", "05", 
        "06", "07", "08", "09", "10", "11", 
        "12", "13", "14", "15", "16", "17",
        "18", "19", "20", "21", "22", "23",
        "24", "25", "26", "27", "28", "29" };

    u32 val_list[] = {
         0,  1,  2,  3,  4,  5, 
         6,  7,  8,  9, 10, 11, 
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23,
        24, 25, 26, 27, 28, 29 };

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

    void* iter = map_iter_begin(m);
    void* const end = map_iter_end(m);
    for (; iter != end; iter = map_iter_next(iter)) {
        char** s = key_list;
        char** const e = key_list + 30;

        char* key = *map_iter_key(iter);
        u32   val = *map_iter_value(iter);

        for (; s != e; ++s) {
            if (*s && strcmp(*s, key) == 0) {
                assert(val_list[30 - (e - s)] == val);
                *s = NULL;
                break;
            }
        }

        assert(s != e);
    }

    map_free(m);
    TEST_END();
}

int 
main(void)
{
    create_free();
    init_deinit();
    insert_get();
    get_or_insert();
    contains();
    size_capacity();
    reserve();
    shrink_to_fit();
    get_key();
    update_key();
    mremove();
    move_pair();
    copy_pair();
    iter();
    return 0;
}
