#ifndef GCL_PREFIX
#error "GCL_PREFIX must be defined"
#endif

#ifndef GCL_VALUE_TYPE
#error "GCL_VALUE_TYPE must be defined"
#endif

#ifndef GCL_TYPE
#error "GCL_TYPE must be defined"
#endif

#ifndef GCL_INIT_CAP
#define GCL_INIT_CAP 4
#endif

#ifndef GCL_GROWTH_FACTOR
#define GCL_GROWTH_FACTOR 2
#endif

#define GCL_GLUE_(A, B) A##B
#define GCL_GLUE(A, B) GCL_GLUE_(A, B)
#define GCL_FUNC_(A, B) GCL_GLUE(A, B)
#define GCL_FUNC(A) GCL_FUNC_(GCL_PREFIX, A)

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct GCL_TYPE GCL_TYPE;
struct GCL_TYPE {
    GCL_VALUE_TYPE* buf;
    uint32_t size;
    uint32_t cap;
};

GCL_TYPE*
GCL_FUNC(_create)(void);

void
GCL_FUNC(_free)(GCL_TYPE* v);

int
GCL_FUNC(_init)(GCL_TYPE* v);

void 
GCL_FUNC(_deinit)(GCL_TYPE* v);

GCL_VALUE_TYPE*
GCL_FUNC(_more)(GCL_TYPE* v);

int
GCL_FUNC(_push)(GCL_TYPE* v, GCL_VALUE_TYPE t);

int 
GCL_FUNC(_pop)(GCL_TYPE* v);

int 
GCL_FUNC(_erase)(GCL_TYPE* v, GCL_VALUE_TYPE* t);

int
GCL_FUNC(_resize)(GCL_TYPE* v, uint32_t new_size);

int
GCL_FUNC(_shrink_to_fit)(GCL_TYPE* v);

void
GCL_FUNC(_clear)(GCL_TYPE* v);

GCL_VALUE_TYPE* 
GCL_FUNC(_begin)(GCL_TYPE* v);

GCL_VALUE_TYPE*
GCL_FUNC(_end)(GCL_TYPE* v);

GCL_VALUE_TYPE*
GCL_FUNC(_last)(GCL_TYPE* v);

uint32_t 
GCL_FUNC(_size)(GCL_TYPE* v);

uint32_t
GCL_FUNC(_capacity)(GCL_TYPE* v);

bool
GCL_FUNC(_empty)(GCL_TYPE* v);

GCL_VALUE_TYPE* 
GCL_FUNC(_get)(GCL_TYPE* v, uint32_t i);

#ifdef GCL_IMPLEMENTATION

static inline int
GCL_FUNC(_realloc_)(GCL_TYPE* v, uint32_t new_cap)
{
    GCL_VALUE_TYPE* new_buf = realloc(v->buf, new_cap * sizeof(*new_buf));
    if (!new_buf) return 1;
    v->buf = new_buf;
    v->cap = new_cap;
    return 0;
}

GCL_TYPE*
GCL_FUNC(_create)(void)
{
    GCL_TYPE* v = malloc(sizeof(*v));
    if (!v) return NULL;
    int e = GCL_FUNC(_init)(v);
    if (e) {
        free(v);
        return NULL;
    }
    return v;
}

void
GCL_FUNC(_free)(GCL_TYPE* v)
{
    if (!v) return;
    free(v->buf);
    free(v);
}

int
GCL_FUNC(_init)(GCL_TYPE* v)
{
    v->cap  = GCL_INIT_CAP;
    v->size = 0;
    v->buf  = malloc(v->cap * sizeof(*v->buf));
    return v->buf ? 0 : 1;
}

void 
GCL_FUNC(_deinit)(GCL_TYPE* v)
{
    free(v->buf);
}

GCL_VALUE_TYPE*
GCL_FUNC(_more)(GCL_TYPE* v)
{
    if (v->size >= v->cap) {
        int e = GCL_FUNC(_realloc_)(v, v->cap * GCL_GROWTH_FACTOR);
        if (e) return NULL;
    }
    return &v->buf[v->size++];
}

int
GCL_FUNC(_push)(GCL_TYPE* v, GCL_VALUE_TYPE t)
{
    GCL_VALUE_TYPE* p = GCL_FUNC(_more)(v);
    if (!p) return 1;
    *p = t;
    return 0;
}

int 
GCL_FUNC(_pop)(GCL_TYPE* v)
{
    // TODO downsize
    v->size -= 1;
    return 0;
}

int 
GCL_FUNC(_erase)(GCL_TYPE* v, GCL_VALUE_TYPE* t)
{
    v->size = t - v->buf;
    return 0;
}

int
GCL_FUNC(_resize)(GCL_TYPE* v, uint32_t new_size)
{
    if (v->size < new_size) {
        int e = GCL_FUNC(_realloc_)(v, new_size);
        if (e) return e;
    }
    v->size = new_size;
    return 0;
}

int
GCL_FUNC(_shrink_to_fit)(GCL_TYPE* v)
{
    return GCL_FUNC(_realloc_)(v, v->size);
}

void
GCL_FUNC(_clear)(GCL_TYPE* v)
{
    v->size = 0;
}

GCL_VALUE_TYPE* 
GCL_FUNC(_begin)(GCL_TYPE* v)
{
    return v->buf;
}

GCL_VALUE_TYPE*
GCL_FUNC(_end)(GCL_TYPE* v)
{
    return v->buf + v->size;
}

GCL_VALUE_TYPE*
GCL_FUNC(_last)(GCL_TYPE* v)
{
    return v->buf + v->size - 1;
}

uint32_t 
GCL_FUNC(_size)(GCL_TYPE* v)
{
    return v->size;
}

uint32_t
GCL_FUNC(_capacity)(GCL_TYPE* v)
{
    return v->cap;
}

bool
GCL_FUNC(_empty)(GCL_TYPE* v)
{
    return v->size == 0;
}

GCL_VALUE_TYPE*
GCL_FUNC(_get)(GCL_TYPE* v, uint32_t i)
{
    return v->buf + i;
}

#undef GCL_IMPLEMENTATION
#endif


#undef GCL_PREFIX
#undef GCL_TYPE
#undef GCL_VALUE_TYPE
#undef GCL_INIT_CAP
#undef GCL_GROWTH_FACTOR
#undef GCL_FUNC
#undef GCL_FUNC_
#undef GCL_GLUE
#undef GCL_GLUE_
