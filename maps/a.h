#ifndef GCL_PREFIX
#error "GCL_PREFIX must be defined"
#endif

#ifndef GCL_VALUE_TYPE
#error "GCL_VALUE_TYPE must be defined"
#endif

#ifndef GCL_KEY_TYPE
#error "GCL_KEY_TYPE must be defined"
#endif

#ifndef GCL_TYPE
#error "GCL_TYPE must be defined"
#endif

#ifndef GCL_HASH_FUNCTION
#error "GCL_HASH_FUNCTION must be defined"
#endif

#ifndef GCL_IS_EQUAL_FUNCTION
#error "GCL_IS_EQUAL_FUNCTION must be defined" 
#endif

#ifndef GCL_GROWTH_FACTOR
#define GCL_GROWTH_FACTOR 2
#endif

#ifndef GCL_MAX_LOAD_FACTOR
#define GCL_MAX_LOAD_FACTOR .75f
#endif

#ifndef GCL_MID_LOAD_FACOTR
#define GCL_MID_LOAD_FACTOR .5f
#endif

#ifndef GCL_MIN_LOAD_FACTOR
#define GCL_MIN_LOAD_FACTOR .25f
#endif

#ifndef GCL_INIT_CAP
#define GCL_INIT_CAP 4
#endif

#define GCL_GLUE_(A, B) A##B
#define GCL_GLUE(A, B) GCL_GLUE_(A, B)
#define GCL_FUNC_(A, B) GCL_GLUE(A, B)
#define GCL_FUNC(A) GCL_FUNC_(GCL_PREFIX, A)

#define GCL_ENTRY_TYPE GCL_GLUE(GCL_PREFIX, _Entry)

#include <gcl/type.h>
#include <stdlib.h>

typedef void* GCL_ITERATOR;

typedef struct GCL_ENTRY_TYPE GCL_ENTRY_TYPE;
struct GCL_ENTRY_TYPE {
    GCL_ENTRY_TYPE* next;
    GCL_ENTRY_TYPE* prev;
    GCL_ENTRY_TYPE* chain;
    GCL_KEY_TYPE key;
    GCL_VALUE_TYPE value;
    u32 hash;
};

typedef struct GCL_TYPE GCL_TYPE;
struct GCL_TYPE {
    GCL_ENTRY_TYPE** map;
    GCL_ENTRY_TYPE* begin;
    u32 size;
    u32 cap;
};

GCL_TYPE*
GCL_FUNC(_create)(void);

void
GCL_FUNC(_free)(GCL_TYPE* m);

int
GCL_FUNC(_init)(GCL_TYPE* m);

void
GCL_FUNC(_deinit)(GCL_TYPE* m);

u32
GCL_FUNC(_size)(GCL_TYPE* m);

u32
GCL_FUNC(_capacity)(GCL_TYPE* m);

bool
GCL_FUNC(_contains)(GCL_TYPE* m, GCL_KEY_TYPE key);

int
GCL_FUNC(_reserve)(GCL_TYPE* m, u32 to_reserve);

int
GCL_FUNC(_shrink_to_fit)(GCL_TYPE* m);

int
GCL_FUNC(_update_key)(GCL_TYPE* m, GCL_KEY_TYPE key);

GCL_KEY_TYPE*
GCL_FUNC(_get_key)(GCL_TYPE* m, GCL_KEY_TYPE key);

int
GCL_FUNC(_insert)(GCL_TYPE* m, GCL_KEY_TYPE key, GCL_VALUE_TYPE value);

int 
GCL_FUNC(_remove)(GCL_TYPE* m, GCL_KEY_TYPE key);

int
GCL_FUNC(_move_pair)(GCL_TYPE* m, GCL_KEY_TYPE key, 
                     GCL_KEY_TYPE* dest_key, GCL_VALUE_TYPE* dest_value);
int 
GCL_FUNC(_copy_pair)(GCL_TYPE* m, GCL_KEY_TYPE key, 
                     GCL_KEY_TYPE* dest_key, GCL_VALUE_TYPE* dest_value);

GCL_VALUE_TYPE* 
GCL_FUNC(_get)(GCL_TYPE* m, GCL_KEY_TYPE key);

GCL_VALUE_TYPE*
GCL_FUNC(_get_or_insert)(GCL_TYPE* m, GCL_KEY_TYPE key, GCL_VALUE_TYPE value);

void*
GCL_FUNC(_iter_begin)(GCL_TYPE* m);

void*
GCL_FUNC(_iter_end)(GCL_TYPE* m);

void*
GCL_FUNC(_iter_next)(void* iter);

GCL_VALUE_TYPE*
GCL_FUNC(_iter_value)(void* iter);

GCL_KEY_TYPE*
GCL_FUNC(_iter_key)(void* iter);

#ifdef GCL_IMPLEMENTATION

static inline GCL_ENTRY_TYPE**
GCL_FUNC(_find_)(GCL_TYPE* m, GCL_KEY_TYPE key, u32 hash)
{
    GCL_ENTRY_TYPE** i = &m->map[(hash % m->cap)];

    for (;; i = &(*i)->chain) {
        if (!*i) return i;
        if ((*i)->hash == hash && GCL_IS_EQUAL_FUNCTION((*i)->key, key)) {
            return i;
        }
    }
}

static inline GCL_ENTRY_TYPE**
GCL_FUNC(_find_free_)(GCL_TYPE* m, u32 hash)
{
    GCL_ENTRY_TYPE** i = &m->map[hash % m->cap];
    for (;; i = &(*i)->chain) {
        if (!*i) return i;
    }
}

static inline int
GCL_FUNC(_realloc_)(GCL_TYPE* m, u32 new_cap)
{
    GCL_ENTRY_TYPE** new_map = realloc(m->map, new_cap * sizeof(*new_map));
    if (!new_map) return 1;

    m->map = new_map;
    m->cap = new_cap;
    memset(m->map, 0, m->cap * sizeof(*m->map));

    GCL_ENTRY_TYPE* i = m->begin;
    for (; i; i = i->next) {
        i->chain = NULL;
        *GCL_FUNC(_find_free_)(m, i->hash) = i;
    }
    return 0;
}

static inline GCL_ENTRY_TYPE*
GCL_FUNC(_create_entry_)(GCL_TYPE* m, GCL_KEY_TYPE key, 
                         GCL_VALUE_TYPE value, u32 hash) 
{
    GCL_ENTRY_TYPE* e = malloc(sizeof(*e));
    if (!e) return NULL;

    *e = (GCL_ENTRY_TYPE) {
        .key = key,
        .value = value,
        .hash = hash,
    };

    if (m->begin) {
        m->begin->prev = e;
    }
    e->next = m->begin;
    m->begin = e;
    m->size += 1;
    return e;
}

static inline void
GCL_FUNC(_free_entry_)(GCL_TYPE* m, GCL_ENTRY_TYPE** e)
{
    GCL_ENTRY_TYPE* t = *e;
    *e = t->chain;
    m->size -= 1;

    if (m->begin == t) {
        m->begin = t->next;
    }

    if (t->next) {
        t->next->prev = t->prev;
    }

    if (t->prev) {
        t->prev->next = t->next;
    }

    free(t);
}

GCL_TYPE*
GCL_FUNC(_create)(void)
{
    GCL_TYPE* m = malloc(sizeof(*m));
    int e = GCL_FUNC(_init)(m);
    if (e) {
        free(m);
        return NULL;
    }
    return m;
}

void
GCL_FUNC(_free)(GCL_TYPE* m)
{
    if (!m) return;
    GCL_FUNC(_deinit)(m);
    free(m);
}

int
GCL_FUNC(_init)(GCL_TYPE* m)
{
    *m = (GCL_TYPE) {
        .size  = 0,
        .cap   = GCL_INIT_CAP / GCL_MAX_LOAD_FACTOR,
        .begin = NULL,
    };
    m->map = calloc(m->cap, sizeof(*m->map));
    return m->map ? 0 : 1;
}

void
GCL_FUNC(_deinit)(GCL_TYPE* m)
{
    GCL_ENTRY_TYPE* iter = m->begin;
    while (iter) {
        GCL_ENTRY_TYPE* tmp = iter;
        iter = iter->next;
        free(tmp);
    }
    free(m->map);
}

u32
GCL_FUNC(_size)(GCL_TYPE* m)
{
    return m->size;
}

u32
GCL_FUNC(_capacity)(GCL_TYPE* m)
{
    return m->cap;
}

bool
GCL_FUNC(_contains)(GCL_TYPE* m, GCL_KEY_TYPE key)
{
    return *GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key)) != NULL;
}

int
GCL_FUNC(_reserve)(GCL_TYPE* m, u32 to_reserve)
{
    return  m->cap < to_reserve ? GCL_FUNC(_realloc_)(m, to_reserve) : 0;
}

int
GCL_FUNC(_shrink_to_fit)(GCL_TYPE* m)
{
    u32 new_cap = m->size / GCL_MID_LOAD_FACTOR;
    return new_cap  != m->cap ? GCL_FUNC(_realloc_)(m, new_cap) : 0;
}

int
GCL_FUNC(_update_key)(GCL_TYPE* m, GCL_KEY_TYPE key)
{
    GCL_ENTRY_TYPE* e = *GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key));
    if (!e) return 1;
    e->key = key;
    return 0;
}

GCL_KEY_TYPE*
GCL_FUNC(_get_key)(GCL_TYPE* m, GCL_KEY_TYPE key)
{
    GCL_ENTRY_TYPE* e = *GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key));
    return e ? &e->key : NULL;
}

int
GCL_FUNC(_insert)(GCL_TYPE* m, GCL_KEY_TYPE key, GCL_VALUE_TYPE value)
{
    u32 hash = GCL_HASH_FUNCTION(key);
    GCL_ENTRY_TYPE** e = GCL_FUNC(_find_)(m, key, hash);

    if (!*e) {
        if (m->size >= m->cap * GCL_MAX_LOAD_FACTOR) {
            int err = GCL_FUNC(_realloc_)(m, m->cap * GCL_GROWTH_FACTOR);
            if (err) return err;
            e = GCL_FUNC(_find_)(m, key, hash);
        }
        *e = GCL_FUNC(_create_entry_)(m, key, value, hash);
        if (!*e) return 1;
    } else {
        (*e)->value = value;
    }
    return 0;
}

int 
GCL_FUNC(_remove)(GCL_TYPE* m, GCL_KEY_TYPE key)
{
    GCL_ENTRY_TYPE** e = GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key));
    if (!*e) return 1;
    GCL_FUNC(_free_entry_)(m, e);
    return 0;
}

int
GCL_FUNC(_move_pair)(GCL_TYPE* m, GCL_KEY_TYPE key, 
                     GCL_KEY_TYPE* dest_key, GCL_VALUE_TYPE* dest_value)
{
    GCL_ENTRY_TYPE** e = GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key));
    if (!*e) return 1;

    if (dest_key) {
        *dest_key = (*e)->key;
    }
    if (dest_value) {
        *dest_value = (*e)->value;
    }

    GCL_FUNC(_free_entry_)(m, e);
    return 0;
}

int 
GCL_FUNC(_copy_pair)(GCL_TYPE* m, GCL_KEY_TYPE key, 
                     GCL_KEY_TYPE* dest_key, GCL_VALUE_TYPE* dest_value)
{
    GCL_ENTRY_TYPE* e = *GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key));
    if (!e) return 1;
    if (dest_key) {
        *dest_key = e->key;
    }
    if (dest_value) {
        *dest_value = e->value;
    }
    return 0;
}                     

GCL_VALUE_TYPE* 
GCL_FUNC(_get)(GCL_TYPE* m, GCL_KEY_TYPE key)
{
    GCL_ENTRY_TYPE* e = *GCL_FUNC(_find_)(m, key, GCL_HASH_FUNCTION(key));
    return e ? &e->value : NULL;
}

GCL_VALUE_TYPE*
GCL_FUNC(_get_or_insert)(GCL_TYPE* m, GCL_KEY_TYPE key, GCL_VALUE_TYPE value)
{
    u32 hash = GCL_HASH_FUNCTION(key);
    GCL_ENTRY_TYPE** e = GCL_FUNC(_find_)(m, key, hash);
    if (!*e) {
        if (m->size >= m->cap * GCL_MAX_LOAD_FACTOR) {
            int err = GCL_FUNC(_realloc_)(m, m->cap * GCL_GROWTH_FACTOR);
            if (err) return NULL;
            e = GCL_FUNC(_find_)(m, key, hash);
        }
        *e = GCL_FUNC(_create_entry_)(m, key, value, hash);
        if (!*e) return NULL;
    }
    return &(*e)->value;
}

void*
GCL_FUNC(_iter_begin)(GCL_TYPE* m)
{
    return m->begin;
}

void*
GCL_FUNC(_iter_end)(GCL_TYPE* m)
{
    return NULL;
}

void*
GCL_FUNC(_iter_next)(void* iter)
{
    return ((GCL_ENTRY_TYPE*)iter)->next;
}

GCL_VALUE_TYPE*
GCL_FUNC(_iter_value)(void* iter)
{
    return &((GCL_ENTRY_TYPE*)iter)->value;
}

GCL_KEY_TYPE*
GCL_FUNC(_iter_key)(void* iter)
{
    return &((GCL_ENTRY_TYPE*)iter)->key;
}

#endif

#undef GCL_GLUE_
#undef GCL_GLUE
#undef GCL_FUNC_
#undef GCL_FUNC

#undef GCL_ENTRY_TYPE
#undef GCL_GROWTH_FACTOR
#undef GCL_HASH_FUNCTION
#undef GCL_INIT_CAP
#undef GCL_IS_EQUAL_FUNCTION
#undef GCL_KEY_TYPE
#undef GCL_MAX_LOAD_FACTOR
#undef GCL_MID_LOAD_FACTOR
#undef GCL_MIN_LOAD_FACTOR
#undef GCL_PREFIX
#undef GCL_TYPE
#undef GCL_VALUE_TYPE
