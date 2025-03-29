#include <sys/time.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <pthread.h>
#include <string.h>
#include <stdatomic.h>
#include <stdio.h>
#ifdef __linux__
#include <sys/personality.h>
#endif
#include "xmalloc.h"

typedef struct size24_block {
	size_t size;
	struct size24_block *next;
	size_t _unused;
} size24_block;

typedef struct size32_block {
	size_t size;
	struct size32_block *next;
	size_t _unused[2];
} size32_block;

typedef struct size40_block {
	size_t size;
	struct size40_block *next;
	size_t _unused[3];
} size40_block;

typedef struct size64_block {
	size_t size;
	struct size64_block *next;
	size_t _unused[6];
} size64_block;

typedef struct size72_block {
	size_t size;
	struct size72_block *next;
	size_t _unused[7];
} size72_block;

typedef struct size128_block {
	size_t size;
	struct size128_block *next;
	size_t _unused[14];
} size128_block;

typedef struct size136_block {
	size_t size;
	struct size136_block *next;
	size_t _unused[15];
} size136_block;

typedef struct size256_block {
	size_t size;
	struct size256_block *next;
	size_t _unused[30];
} size256_block;

typedef struct size264_block {
	size_t size;
	struct size264_block *next;
	size_t _unused[31];
} size264_block;

typedef struct size512_block {
	size_t size;
	struct size512_block *next;
	size_t _unused[62];
} size512_block;

typedef struct size520_block {
	size_t size;
	struct size520_block *next;
	size_t _unused[63];
} size520_block;

typedef struct size1024_block {
	size_t size;
	struct size1024_block *next;
	size_t _unused[126];
} size1024_block;

typedef struct size1032_block {
	size_t size;
	struct size1032_block *next;
	size_t _unused[127];
} size1032_block;

typedef struct size2048_block {
	size_t size;
	struct size2048_block *next;
	size_t _unused[254];
} size2048_block;

typedef struct size2056_block {
	size_t size;
	struct size2056_block *next;
	size_t _unused[255];
} size2056_block;

/*
 * function cas(p: pointer to int, old: int, new: int) is
 *   if *p ≠ old
 *       return false
 *
 *   *p ← new
 *
 *   return true
 */
 

static pthread_mutex_t lock_24s = PTHREAD_MUTEX_INITIALIZER;
static size24_block* size24s = 0;

void* size24_free(void* ptr) {
	size24_block* point = (size24_block*)(ptr);
	point->size = 24;
	
	size24_block* prev = NULL;
	while ((void*)point<(void*)size24s && size24s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size24s;
		size24s = size24s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size24s;
	}
	else {
		point->next = size24s;
		size24s = point;
	}
	return 0;
}

void* size24_setup() {
	size24_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 19418; ii++) {
		size24_free(&(page[ii]));
	}
	return 0;
}

void* size24_malloc() {
	if (size24s==0) {
		size24_setup();
	}
	size_t* ptr = (void*)size24s;
	size24s = size24s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_32s = PTHREAD_MUTEX_INITIALIZER;
static size32_block* size32s = 0;

void* size32_free(void* ptr) {
	size32_block* point = (size32_block*)(ptr);
	point->size = 32;
	
	size32_block* prev = NULL;
	while ((void*)point<(void*)size32s && size32s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size32s;
		size32s = size32s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size32s;
	}
	else {
		point->next = size32s;
		size32s = point;
	}
	return 0;
}

void* size32_setup() {
	size32_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 14563; ii++) {
		size32_free(&(page[ii]));
	}
	return 0;
}

void* size32_malloc() {
	if (size32s==0) {
		size32_setup();
	}
	size_t* ptr = (void*)size32s;
	size32s = size32s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_40s = PTHREAD_MUTEX_INITIALIZER;
static size40_block* size40s = 0;

void* size40_free(void* ptr) {
	size40_block* point = (size40_block*)(ptr);
	point->size = 40;
	
	size40_block* prev = NULL;
	while ((void*)point<(void*)size40s && size40s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size40s;
		size40s = size40s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size40s;
	}
	else {
		point->next = size40s;
		size40s = point;
	}
	return 0;
}

void* size40_setup() {
	size40_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 11650; ii++) {
		size40_free(&(page[ii]));
	}
	return 0;
}

void* size40_malloc() {
	if (size40s==0) {
		size40_setup();
	}
	size_t* ptr = (void*)size40s;
	size40s = size40s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_64s = PTHREAD_MUTEX_INITIALIZER;
static size64_block* size64s = 0;

void* size64_free(void* ptr) {
	size64_block* point = (size64_block*)(ptr);
	point->size = 64;
	
	size64_block* prev = NULL;
	while ((void*)point<(void*)size64s && size64s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size64s;
		size64s = size64s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size64s;
	}
	else {
		point->next = size64s;
		size64s = point;
	}
	return 0;
}

void* size64_setup() {
	size64_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 7281; ii++) {
		size64_free(&(page[ii]));
	}
	return 0;
}

void* size64_malloc() {
	if (size64s==0) {
		size64_setup();
	}
	size_t* ptr = (void*)size64s;
	size64s = size64s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_72s = PTHREAD_MUTEX_INITIALIZER;
static size72_block* size72s = 0;

void* size72_free(void* ptr) {
	size72_block* point = (size72_block*)(ptr);
	point->size = 72;
	
	size72_block* prev = NULL;
	while ((void*)point<(void*)size72s && size72s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size72s;
		size72s = size72s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size72s;
	}
	else {
		point->next = size72s;
		size72s = point;
	}
	return 0;
}

void* size72_setup() {
	size72_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 6472; ii++) {
		size72_free(&(page[ii]));
	}
	return 0;
}

void* size72_malloc() {
	if (size72s==0) {
		size72_setup();
	}
	size_t* ptr = (void*)size72s;
	size72s = size72s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_136s = PTHREAD_MUTEX_INITIALIZER;
static size136_block* size136s = 0;

void* size136_free(void* ptr) {
	size136_block* point = (size136_block*)(ptr);
	point->size = 136;
	
	size136_block* prev = NULL;
	while ((void*)point<(void*)size136s && size136s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size136s;
		size136s = size136s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size136s;
	}
	else {
		point->next = size136s;
		size136s = point;
	}
	return 0;
}

void* size136_setup() {
	size136_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 3426; ii++) {
		size136_free(&(page[ii]));
	}
	return 0;
}

void* size136_malloc() {
	if (size136s==0) {
		size136_setup();
	}
	size_t* ptr = (void*)size136s;
	size136s = size136s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_264s = PTHREAD_MUTEX_INITIALIZER;
static size264_block* size264s = 0;

void* size264_free(void* ptr) {
	size264_block* point = (size264_block*)(ptr);
	point->size = 264;
	
	size264_block* prev = NULL;
	while ((void*)point<(void*)size264s && size264s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size264s;
		size264s = size264s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size264s;
	}
	else {
		point->next = size264s;
		size264s = point;
	}
	return 0;
}

void* size264_setup() {
	size264_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 1765; ii++) {
		size264_free(&(page[ii]));
	}
	return 0;
}

void* size264_malloc() {
	if (size264s==0) {
		size264_setup();
	}
	size_t* ptr = (void*)size264s;
	size264s = size264s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_520s = PTHREAD_MUTEX_INITIALIZER;
static size520_block* size520s = 0;

void* size520_free(void* ptr) {
	size520_block* point = (size520_block*)(ptr);
	point->size = 520;
	
	size520_block* prev = NULL;
	while ((void*)point<(void*)size520s && size520s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size520s;
		size520s = size520s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size520s;
	}
	else {
		point->next = size520s;
		size520s = point;
	}
	return 0;
}

void* size520_setup() {
	size520_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 896; ii++) {
		size520_free(&(page[ii]));
	}
	return 0;
}

void* size520_malloc() {
	if (size520s==0) {
		size520_setup();
	}
	size_t* ptr = (void*)size520s;
	size520s = size520s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_1032s = PTHREAD_MUTEX_INITIALIZER;
static size1032_block* size1032s = 0;

void* size1032_free(void* ptr) {
	size1032_block* point = (size1032_block*)(ptr);
	point->size = 1032;
	
	size1032_block* prev = NULL;
	while ((void*)point<(void*)size1032s && size1032s != 0) {	// Keep the blocks sorted by where they appear in memory ;)
		prev = size1032s;
		size1032s = size1032s->next;
	}
	if (prev) {
		prev->next = point;
		point->next = size1032s;
	}
	else {
		point->next = size1032s;
		size1032s = point;
	}
	return 0;
}

void* size1032_setup() {
	size1032_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 451; ii++) {
		size1032_free(&(page[ii]));
	}
	return 0;
}

void* size1032_malloc() {
	if (size1032s==0) {
		size1032_setup();
	}
	size_t* ptr = (void*)size1032s;
	size1032s = size1032s->next;
	return ptr + 1;
}

static
void
xfree_helper(void *ap)
{
	size_t* ptr = (size_t*)ap - 1;
	munmap(ptr, *ptr);
}

void
xfree(void* ap)
{
  size_t *ptr = (size_t*)ap - 1;
  switch (*ptr) {
  case 24:
  	pthread_mutex_lock(&lock_24s);
  	size24_free(ptr);
  	pthread_mutex_unlock(&lock_24s);
  	break;
  case 32:
  	pthread_mutex_lock(&lock_32s);
  	size32_free(ptr);
  	pthread_mutex_unlock(&lock_32s);
  	break;
  case 40:
  	pthread_mutex_lock(&lock_40s);
  	size40_free(ptr);
  	pthread_mutex_unlock(&lock_40s);
  	break;
  case 64:
  	pthread_mutex_lock(&lock_64s);
  	size64_free(ptr);
  	pthread_mutex_unlock(&lock_64s);
  	break;
  case 72:
  	pthread_mutex_lock(&lock_72s);
  	size72_free(ptr);
  	pthread_mutex_unlock(&lock_72s);
  	break;
  case 136:
  	pthread_mutex_lock(&lock_136s);
  	size136_free(ptr);
  	pthread_mutex_unlock(&lock_136s);
  	break;
  case 264:
  	pthread_mutex_lock(&lock_264s);
  	size264_free(ptr);
  	pthread_mutex_unlock(&lock_264s);
  	break;
  case 520:
  	pthread_mutex_lock(&lock_520s);
  	size520_free(ptr);
  	pthread_mutex_unlock(&lock_520s);
  	break;
  case 1032:
  	pthread_mutex_lock(&lock_1032s);
  	size1032_free(ptr);
  	pthread_mutex_unlock(&lock_1032s);
  	break;
  default:
  	xfree_helper(ap);
  	break;
  }
}

void*
xmalloc_helper(size_t nbytes)
{
  //printf("xmalloc(%ld)\n", nbytes);
  size_t* block = 0;
  //nbytes += sizeof(long);
  if (nbytes > 4096) {
  	size_t pages = (nbytes + (4096 - 1)) / 4096;	// Idiom for rounded division...number of pages to allocate
  	block = mmap(0, pages * 4096, PROT_READ|PROT_WRITE,
           MAP_ANONYMOUS|MAP_SHARED, -1, 0);
        *block = pages * 4096;
  } else {
  	block = mmap(0, nbytes, PROT_READ|PROT_WRITE,
           MAP_ANONYMOUS|MAP_SHARED, -1, 0);
        *block = nbytes;
  }
  return block + 1;
}


void*
xmalloc(size_t nbytes)
{
  personality(ADDR_NO_RANDOMIZE);
  nbytes += sizeof(size_t);
  void *ptr;
  //printf("xmalloc(%ld)\n", nbytes);
  switch (nbytes) {
  case 24:
  	pthread_mutex_lock(&lock_24s);
  	ptr = size24_malloc();
  	pthread_mutex_unlock(&lock_24s);
  	return ptr;
  	break;
  case 32:
  	pthread_mutex_lock(&lock_32s);
  	ptr = size32_malloc();
  	pthread_mutex_unlock(&lock_32s);
  	return ptr;
  	break;
  case 40:
  	pthread_mutex_lock(&lock_40s);
  	ptr = size40_malloc();
  	pthread_mutex_unlock(&lock_40s);
  	return ptr;
  	break;
  case 64:
  	pthread_mutex_lock(&lock_64s);
  	ptr = size64_malloc();
  	pthread_mutex_unlock(&lock_64s);
  	return ptr;
  	break;
  case 72:
  	pthread_mutex_lock(&lock_72s);
  	ptr = size72_malloc();
  	//printf("72 Allocs. (%d)\n", ++s72);
  	pthread_mutex_unlock(&lock_72s);
  	return ptr;
  	break;
  case 136:
  	pthread_mutex_lock(&lock_136s);
  	ptr = size136_malloc();
  	pthread_mutex_unlock(&lock_136s);
  	return ptr;
  	break;
  case 264:
  	pthread_mutex_lock(&lock_264s);
  	ptr = size264_malloc();
  	pthread_mutex_unlock(&lock_264s);
  	return ptr;
  	break;
  case 520:
  	pthread_mutex_lock(&lock_520s);
  	ptr = size520_malloc();
  	pthread_mutex_unlock(&lock_520s);
  	return ptr;
  	break;
  case 1032:
  	pthread_mutex_lock(&lock_1032s);
  	ptr = size1032_malloc();
  	pthread_mutex_unlock(&lock_1032s);
  	return ptr;
  	break;
  default:
  	return xmalloc_helper(nbytes);
  	break;
  }
}

void*
xrealloc(void* prev, size_t nn)
{
  // TODO: implement a working realloc
  // This is where we are failing the next test...
  size_t *new = xmalloc(nn);
  size_t *ptr = (size_t*)prev-1;
  
  memset(new, 0, nn);
  if (nn >= *ptr)
  	memcpy(new, prev, *ptr);
  
  xfree(prev);
  
  return new;
}



