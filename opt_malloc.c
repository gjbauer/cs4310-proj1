#include <sys/time.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <string.h>
#include <stdbool.h>
#ifdef __linux__
#include <sys/personality.h>
#endif
#include "xmalloc.h"

bool first_run = true;

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

typedef struct size136_block {
	size_t size;
	struct size136_block *next;
	size_t _unused[15];
} size136_block;

typedef struct size264_block {
	size_t size;
	struct size264_block *next;
	size_t _unused[31];
} size264_block;

typedef struct size520_block {
	size_t size;
	struct size520_block *next;
	size_t _unused[63];
} size520_block;

typedef struct size1032_block {
	size_t size;
	struct size1032_block *next;
	size_t _unused[127];
} size1032_block;

static __thread size24_block* size24s = 0;

void size24_free(void* ptr) {
	size24_block* point = (size24_block*)(ptr);
	point->size = 24;
	
	point->next = size24s;
	size24s = point;
}

void size24_setup() {
	size24_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 19418; ii++) {
		size24_free(&(page[ii]));
	}
}

void* size24_malloc() {
	if (size24s==0) {
		size24_setup();
	}
	
	size_t* ptr = (void*)size24s;
	size24s = size24s->next;
	return ptr + 1;
}

static __thread size32_block* size32s = 0;

void size32_free(void* ptr) {
	size32_block* point = (size32_block*)(ptr);
	point->size = 32;
	
	point->next = size32s;
	size32s = point;
}

void size32_setup() {
	size32_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 14563; ii++) {
		size32_free(&(page[ii]));
	}
}

void* size32_malloc() {
	if (size32s==0) {
		size32_setup();
	}
	size_t* ptr = (void*)size32s;
	size32s = size32s->next;
	return ptr + 1;
}

static __thread size40_block* size40s = 0;

void size40_free(void* ptr) {
	size40_block* point = (size40_block*)(ptr);
	point->size = 40;
	
	point->next = size40s;
	size40s = point;
}

void size40_setup() {
	size40_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 11650; ii++) {
		size40_free(&(page[ii]));
	}
}

void* size40_malloc() {
	if (size40s==0) {
		size40_setup();
	}
	size_t* ptr = (void*)size40s;
	size40s = size40s->next;
	return ptr + 1;
}

static __thread size64_block* size64s = 0;

void size64_free(void* ptr) {
	size64_block* point = (size64_block*)(ptr);
	point->size = 64;
	
	point->next = size64s;
	size64s = point;
}

void size64_setup() {
	size64_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 7281; ii++) {
		size64_free(&(page[ii]));
	}
}

void* size64_malloc() {
	if (size64s==0) {
		size64_setup();
	}
	size_t* ptr = (void*)size64s;
	size64s = size64s->next;
	return ptr + 1;
}

static __thread size72_block* size72s = 0;

void size72_free(void* ptr) {
	size72_block* point = (size72_block*)(ptr);
	point->size = 72;
	
	point->next = size72s;
	size72s = point;
}

void size72_setup() {
	size72_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 6472; ii++) {
		size72_free(&(page[ii]));
	}
}

void* size72_malloc() {
	if (size72s==0) {
		size72_setup();
	}
	size_t* ptr = (void*)size72s;
	size72s = size72s->next;
	return ptr + 1;
}

static __thread size136_block* size136s = 0;

void size136_free(void* ptr) {
	size136_block* point = (size136_block*)(ptr);
	point->size = 136;
	
	point->next = size136s;
	size136s = point;
}

void size136_setup() {
	size136_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 3426; ii++) {
		size136_free(&(page[ii]));
	}
}

void* size136_malloc() {
	if (size136s==0) {
		size136_setup();
	}
	size_t* ptr = (void*)size136s;
	size136s = size136s->next;
	return ptr + 1;
}

static __thread size264_block* size264s = 0;

void size264_free(void* ptr) {
	size264_block* point = (size264_block*)(ptr);
	point->size = 264;
	
	point->next = size264s;
	size264s = point;
}

void size264_setup() {
	size264_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 1765; ii++) {
		size264_free(&(page[ii]));
	}
}

void* size264_malloc() {
	if (size264s==0) {
		size264_setup();
	}
	size_t* ptr = (void*)size264s;
	size264s = size264s->next;
	return ptr + 1;
}

static __thread size520_block* size520s = 0;

void size520_free(void* ptr) {
	size520_block* point = (size520_block*)(ptr);
	point->size = 520;
	
	point->next = size520s;
	size520s = point;
}

void size520_setup() {
	size520_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 896; ii++) {
		size520_free(&(page[ii]));
	}
}

void* size520_malloc() {
	if (size520s==0) {
		size520_setup();
	}
	size_t* ptr = (void*)size520s;
	size520s = size520s->next;
	return ptr + 1;
}

static __thread size1032_block* size1032s = 0;

void size1032_free(void* ptr) {
	size1032_block* point = (size1032_block*)(ptr);
	point->size = 1032;
	
	point->next = size1032s;
	size1032s = point;
}

void size1032_setup() {
	size1032_block* page = mmap(0, 466033, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	for (int ii = 0; ii < 451; ii++) {
		size1032_free(&(page[ii]));
	}
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
  	size24_free(ptr);
  	break;
  case 32:
  	size32_free(ptr);
  	break;
  case 40:
  	size40_free(ptr);
  	break;
  case 64:
  	size64_free(ptr);
  	break;
  case 72:
  	size72_free(ptr);
  	break;
  case 136:
  	size136_free(ptr);
  	break;
  case 264:
  	size264_free(ptr);
  	break;
  case 520:
  	size520_free(ptr);
  	break;
  case 1032:
  	size1032_free(ptr);
  	break;
  default:
  	xfree_helper(ap);
  	break;
  }
}

void*
xmalloc_helper(size_t nbytes)
{
  size_t* block = mmap(0, nbytes, PROT_READ|PROT_WRITE,
           MAP_ANONYMOUS|MAP_SHARED, -1, 0);
  *block = nbytes;
  return block + 1;
}


void*
xmalloc(size_t nbytes)
{
  if (first_run == true) {
  	personality(ADDR_NO_RANDOMIZE);
  	first_run = false;
  }
  nbytes += sizeof(size_t);
  //printf("xmalloc(%ld)\n", nbytes);
  switch (nbytes) {
  case 24:
  	return size24_malloc();
  	break;
  case 32:
  	return size32_malloc();
  	break;
  case 40:
  	return size40_malloc();
  	break;
  case 64:
  	return size64_malloc();
  	break;
  case 72:
  	return size72_malloc();
  	break;
  case 136:
  	return size136_malloc();
  	break;
  case 264:
  	return size264_malloc();
  	break;
  case 520:
  	return size520_malloc();
  	break;
  case 1032:
  	return size1032_malloc();
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



