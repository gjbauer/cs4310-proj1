#include <sys/time.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#ifdef __linux__
#include <sys/personality.h>
#endif
#include "xmalloc.h"

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

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

typedef struct size256_block {
	size_t size;
	struct size256_block *next;
	size_t _unused[30];
} size256_block;

typedef struct size512_block {
	size_t size;
	struct size512_block *next;
	size_t _unused[62];
} size512_block;

typedef struct size1024_block {
	size_t size;
	struct size1024_block *next;
	size_t _unused[126];
} size1024_block;

typedef struct size2048_block {
	size_t size;
	struct size2048_block *next;
	size_t _unused[254];
} size2048_block;

static pthread_mutex_t lock_24s = PTHREAD_MUTEX_INITIALIZER;
static size24_block* size24s = 0;

void* size24_free(void* ptr) {
	size24_block* point = (size24_block*)((size_t*)ptr - 1);
	point->next = size24s;
	size24s = point;
	return 0;
}

void* size24_malloc() {
	if (size24s == 0) {
		size24_block* page = mmap(0, 2048, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 85; ii++) {
			size24_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size24s;
	size24s = size24s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_32s = PTHREAD_MUTEX_INITIALIZER;
static size32_block* size32s = 0;

void* size32_free(void* ptr) {
	size32_block* point = (size32_block*)((size_t*)ptr - 1);
	point->next = size32s;
	size32s = point;
	return 0;
}

void* size32_malloc() {
	if (size32s == 0) {
		size32_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 128; ii++) {
			size32_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size32s;
	size32s = size32s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_64s = PTHREAD_MUTEX_INITIALIZER;
static size64_block* size64s = 0;

void* size64_free(void* ptr) {
	size64_block* point = (size64_block*)((size_t*)ptr - 1);
	point->next = size64s;
	size64s = point;
	return 0;
}

void* size64_malloc() {
	if (size64s == 0) {
		size64_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 64; ii++) {
			size64_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size64s;
	size64s = size64s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_72s = PTHREAD_MUTEX_INITIALIZER;
static size72_block* size72s = 0;

void* size72_free(void* ptr) {
	size72_block* point = (size72_block*)((size_t*)ptr - 1);
	point->next = size72s;
	size72s = point;
	return 0;
}

void* size72_malloc() {
	if (size72s == 0) {
		size72_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 56; ii++) {
			size72_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size72s;
	size72s = size72s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_128s = PTHREAD_MUTEX_INITIALIZER;
static size128_block* size128s = 0;

void* size128_free(void* ptr) {
	size128_block* point = (size128_block*)((size_t*)ptr - 1);
	point->next = size128s;
	size128s = point;
	return 0;
}

void* size128_malloc() {
	if (size128s == 0) {
		size128_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 32; ii++) {
			size128_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size128s;
	size128s = size128s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_256s = PTHREAD_MUTEX_INITIALIZER;
static size256_block* size256s = 0;

void* size256_free(void* ptr) {
	size256_block* point = (size256_block*)((size_t*)ptr - 1);
	point->next = size256s;
	size256s = point;
	return 0;
}

void* size256_malloc() {
	if (size256s == 0) {
		size256_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 16; ii++) {
			size256_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size256s;
	size256s = size256s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_512s = PTHREAD_MUTEX_INITIALIZER;
static size512_block* size512s = 0;

void* size512_free(void* ptr) {
	size512_block* point = (size512_block*)((size_t*)ptr - 1);
	point->next = size512s;
	size512s = point;
	return 0;
}

void* size512_malloc() {
	if (size512s == 0) {
		size512_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 8; ii++) {
			size512_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size512s;
	size512s = size512s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_1024s = PTHREAD_MUTEX_INITIALIZER;
static size1024_block* size1024s = 0;

void* size1024_free(void* ptr) {
	size1024_block* point = (size1024_block*)((size_t*)ptr - 1);
	point->next = size1024s;
	size1024s = point;
	return 0;
}

void* size1024_malloc() {
	if (size1024s == 0) {
		size1024_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 4; ii++) {
			size1024_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size1024s;
	size1024s = size1024s->next;
	return ptr + 1;
}

static pthread_mutex_t lock_2048s = PTHREAD_MUTEX_INITIALIZER;
static size2048_block* size2048s = 0;

void* size2048_free(void* ptr) {
	size2048_block* point = (size2048_block*)((size_t*)ptr - 1);
	point->next = size2048s;
	size2048s = point;
	return 0;
}

void* size2048_malloc() {
	if (size2048s == 0) {
		size2048_block* page = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
		for (int ii = 0; ii < 2; ii++) {
			size2048_free(&(page[ii]));
		}
	}
	
	size_t* ptr = (void*)size2048s;
	size2048s = size2048s->next;
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
  if (*ptr == 24) {
  	pthread_mutex_lock(&lock_24s);
  	size24_free(ap);
  	pthread_mutex_unlock(&lock_24s);
  }
  else if (*ptr == 32) {
  	pthread_mutex_lock(&lock_32s);
  	size32_free(ap);
  	pthread_mutex_unlock(&lock_32s);
  }
  else if (*ptr == 64) {
  	pthread_mutex_lock(&lock_64s);
  	size64_free(ap);
  	pthread_mutex_unlock(&lock_64s);
  }
  else if (*ptr == 128) {
  	pthread_mutex_lock(&lock_128s);
  	size128_free(ap);
  	pthread_mutex_unlock(&lock_128s);
  }
  else if (*ptr == 256) {
  	pthread_mutex_lock(&lock_256s);
  	size256_free(ap);
  	pthread_mutex_unlock(&lock_256s);
  }
  else if (*ptr == 512) {
  	pthread_mutex_lock(&lock_512s);
  	size512_free(ap);
  	pthread_mutex_unlock(&lock_512s);
  }
  else if (*ptr == 1024) {
  	pthread_mutex_lock(&lock_1024s);
  	size1024_free(ap);
  	pthread_mutex_unlock(&lock_1024s);
  }
  else if (*ptr == 2048) {
  	pthread_mutex_lock(&lock_2048s);
  	size2048_free(ap);
  	pthread_mutex_unlock(&lock_2048s);
  }
  else if (*ptr == 72) {
  	pthread_mutex_lock(&lock_72s);
  	size72_free(ap);
  	pthread_mutex_unlock(&lock_72s);
  }
  else {
  	pthread_mutex_lock(&lock);
  	xfree_helper(ap);
  	pthread_mutex_unlock(&lock);
  }
}

void*
xmalloc_helper(size_t nbytes)
{
  #ifdef __linux__
  personality(ADDR_NO_RANDOMIZE);
  #endif
  //printf("xmalloc(%ld)\n", nbytes);
  size_t* block = mmap(0, nbytes, PROT_READ|PROT_WRITE,
           MAP_ANONYMOUS|MAP_SHARED, -1, 0);
  *block = nbytes;
  return block + 1;
}

void*
xmalloc(size_t nbytes)
{
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
  case 64:
  	pthread_mutex_lock(&lock_64s);
  	ptr = size64_malloc();
  	pthread_mutex_unlock(&lock_64s);
  	return ptr;
  	break;
  case 72:
  	pthread_mutex_lock(&lock_72s);
  	ptr = size72_malloc();
  	pthread_mutex_unlock(&lock_72s);
  	return ptr;
  	break;
  case 128:
  	pthread_mutex_lock(&lock_128s);
  	ptr = size128_malloc();
  	pthread_mutex_unlock(&lock_128s);
  	return ptr;
  	break;
  case 256:
  	pthread_mutex_lock(&lock_256s);
  	ptr = size256_malloc();
  	pthread_mutex_unlock(&lock_256s);
  	return ptr;
  	break;
  case 512:
  	pthread_mutex_lock(&lock_512s);
  	ptr = size512_malloc();
  	pthread_mutex_unlock(&lock_512s);
  	return ptr;
  	break;
  case 1024:
  	pthread_mutex_lock(&lock_1024s);
  	ptr = size1024_malloc();
  	pthread_mutex_unlock(&lock_1024s);
  	return ptr;
  	break;
  case 2048:
  	pthread_mutex_lock(&lock_2048s);
  	ptr = size2048_malloc();
  	pthread_mutex_unlock(&lock_2048s);
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
  void *new = xmalloc(nn);
  size_t *ptr = (size_t*)prev-1;
  
  memset(new, 0, nn);
  memcpy(new, prev, *ptr);
  
  xfree(prev);
  
  return new;
}


