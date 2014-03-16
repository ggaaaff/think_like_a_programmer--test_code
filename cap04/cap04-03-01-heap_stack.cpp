//2014.03.16 Gustaf - CTG.


/*

=== INFORMATION ===
IMPORTANT NOTES (copy & paste) FROM CHAPTER 4.

C++ allocates memory in two places: the stack and the heap.


## STACK is organized and neat

once you have allocated a block of memory (a crate) on the stack,
there’s no way to resize it because at any time you may have other memory
blocks immediately following it (other crates on top of it).

Every time a function is called (and this includes the main function),
a block of memory is allocated on the top of the runtime stack.
  > This block of memory is called an activation record.


## HEAP is disjointed and messy.

This storage system is flexible and allows you to get to the contents of any crate at any time.

Over the lifetime of a program with many memory allocations and deallocations,
we’ll end up with lots of gaps between the remaining allocated memory blocks.
  > This problem is known as memory fragmentation.


Every program has its own heap, from which memory is dynamically allocated.

  In C++, this usually means an invocation of the new keyword, but you
  will also see calls to the old C functions for memory allocation, such as malloc.

  Each call to new (or malloc) sets aside a chunk of memory in the heap and
  returns a pointer to the chunk, while each call to delete (or free if the mem-
  ory was allocated with malloc) returns the chunk to the pool of available heap
  memory. Because of fragmentation, not all of the memory in the pool is equally
  useful.



## Memory Size
Programs need to use memory efficiently to avoid overall system SLOWDOWN.

Each program has a limited amount of memory.
The stack and the heap have maximum sizes.



~~~~ This is horrible code written purely to demonstrate a point. ~~~~

// Allocate memory from the heap a kilobyte at a time, until something blows up:

  const int intsPerKilobyte = 1024 / sizeof(int);
  while (true) {
    int *oneKilobyteArray = new int[intsPerKilobyte];
  }

    What should happen is that the program halts and
    your operating system complains that the code generated but did not handle
    a "bad_alloc" exception. This exception is thrown by "new" when no block of unallocated
    memory in the heap is large enough to fulfill the request.
    > Running out of heap memory is called a heap overflow.


- A similar situation exists with the runtime stack. 
// The easiest way to demonstrate this is with a runaway recursive function:

  int count = 0;
  void stackOverflow()
  {
    count++;
    stackOverflow();
  }

  int main()
  {
    stackOverflow();
    return 0;
  }

    Each function call allocates space on the stack, 
    and there is some fixed overhead for each activation record, 
    even for a function with no parameters or local variables.



## The lifetime of a variable is the time span between allocation and deallocation

With a stack-based variable, meaning either a local variable or a parameter,
the lifetime is handled implicitly. The variable is allocated when the function
is called and deallocated when the function ends. 

With a heap-based variable, meaning a variable dynamically allocated using new, 
the lifetime is in our hands.



- Memory leak.
Memory is allocated from the heap but never deallocated and not referenced by any pointer. 

Here’s a simple example:
 int *intPtr = new int;
 intPtr = NULL; //an alias for the number zero.

    If we tried to follow the code above with delete intPtr, 
    we would get an error because intPtr is zero.


- Deallocate the same memory twice.
If multiple variables point to the same memory and we call delete on any of those
variables, we have effectively deallocated the memory for all of the variables. 
If we don’t explicitly clear the variables to NULL, they will be known as "dangling
references", and calling delete on any of them will produce a runtime error.



*/



#include <iostream>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;

  cout << endl;
  return 0;
}
