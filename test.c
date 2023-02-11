#define GCL_PREFIX vec
#define GCL_TYPE Vec
#define GCL_VALUE_TYPE uint32_t
#define GCL_IMPLEMENTATION
#include "vec.h"

#include <assert.h>
#include <stdio.h>

#define TEST_START() do { printf("[test] %s\n", __func__); } while (0)
#define TEST_END() do { puts("\tok"); } while (0)

static void
create_free(void)
{
    TEST_START();
    Vec* v = vec_create();
    assert(v);
    assert(vec_begin(v));
    assert(vec_size(v) == 0);
    assert(vec_begin(v) == vec_end(v));
    vec_free(v);
    TEST_END();
}

static void
init_deinit(void)
{
    TEST_START();
    Vec v_ = { 0 };
    Vec* v = &v_;
    assert(vec_init(v) == 0);
    assert(vec_size(v) == 0);
    assert(vec_begin(v));
    assert(vec_begin(v) == vec_end(v));
    vec_deinit(v);
    TEST_END();
}

static void 
more(void)
{
    TEST_START();
    Vec* v = vec_create();

    for (uint32_t i = 0; i < 100; ++i) {
        uint32_t* p = vec_more(v);
        assert(p);
        *p = i;
    }
    assert(vec_size(v) == 100);
    
    assert(v);
    vec_free(v);
    TEST_END();
}

static void
push(void)
{
    TEST_START();
    Vec* v = vec_create();
    assert(v);

    for (uint32_t i = 0; i < 100; ++i) {
        assert(vec_push(v, i) == 0);
    }
    assert(vec_size(v) == 100);
    assert(vec_capacity(v) >= vec_size(v));

    vec_free(v);
    TEST_END();
}

static void
resize(void)
{
    TEST_START();
    Vec* v = vec_create();
    assert(v);

    assert(vec_size(v) == 0);
    assert(vec_capacity(v) >= vec_size(v));

    assert(vec_resize(v, 100) == 0);
    assert(vec_size(v) == 100);
    assert(vec_end(v) - vec_begin(v) == 100);
    vec_free(v);
    TEST_END();
}

static void
shrink_to_fit(void)
{
    TEST_START();

    Vec* v = vec_create();

    for (uint32_t i = 0; i < 100; ++i) {
        *vec_more(v) = i;
    }

    assert(vec_size(v) == 100);
    assert(vec_capacity(v) >= vec_size(v));
    assert(vec_shrink_to_fit(v) == 0);
    assert(vec_capacity(v) == vec_size(v));

    vec_free(v);

    TEST_END();
}

static void
begin_end_last(void)
{
    TEST_START();
    Vec* v = vec_create();

    for (uint32_t i = 0; i < 10; ++i) {
        *vec_more(v) = i;
    }

    uint32_t* b = vec_begin(v);
    uint32_t* e = vec_end(v);
    uint32_t* l = vec_last(v);

    assert(*b == 0);
    assert(e - b == 10);
    assert(*l == 9);

    vec_free(v);
    TEST_END();
}

static void
get(void)
{
    TEST_START();
    Vec* v = vec_create();

    for (uint32_t i = 0; i < 100; ++i) {
        *vec_more(v) = i;
    }

    for (uint32_t i = 0; i < 100; ++i) {
        assert(*vec_get(v, i) == i);
    }

    vec_free(v);
    TEST_END();
}

int main(void)
{
    create_free();
    init_deinit();
    more();
    push();
    resize();
    shrink_to_fit();
    begin_end_last();
    get();
    return 0;
}
