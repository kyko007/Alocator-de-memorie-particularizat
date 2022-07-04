
#ifndef _CUSTOM_ALLOCATOR_H_
#define _CUSTOM_ALLOCATOR_H_

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

//----------------------------------------------------------------------------

void * __cdecl CustomAllocator_New   (size_t aSize,  int aBlockUse = _NORMAL_BLOCK, char const * aFileName = __FILE__, int aLineNumber = 0);
void   __cdecl CustomAllocator_Delete(void * aBlock, int aBlockUse = _NORMAL_BLOCK, char const * aFileName = __FILE__, int aLineNumber = 0) noexcept;

void * __cdecl CustomAllocator_Malloc(size_t aSize,  int aBlockUse, char const * aFileName, int aLineNumber);
void __cdecl   CustomAllocator_Free  (void * aBlock, int aBlockUse, char const * aFileName, int aLineNumber);

void __cdecl memoryVisualise();
size_t __cdecl memoryUsage();

void _cdecl beginSnapShot();
bool _cdecl endSnapShot();

size_t __cdecl maxAvailable();
double _cdecl metricFragmentation(int index);
//----------------------------------------------------------------------------

#endif  // _CUSTOM_ALLOCATOR_H_
