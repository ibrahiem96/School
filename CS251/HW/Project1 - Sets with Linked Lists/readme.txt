
Mulitple file compilation, etc.


Notice that sset.c contains no main function.  This is because it is a set
of utility functions (implementing a Sorted Set ADT).  These functions can
be used by "client" programs much in the same way that programs you've
written use the standart C library functions.

There are three files here:

  - sset.h defines the interface (functions) to the SSET ADT.  It also has a 
    typedef for SSET which is "incompletely specified" -- the actual struct
    is hidden in the file sset.c

    In principle, a client program only needs to know the set of functions 
    available, not their actual implementation.

  - sset.c contains the actual implementations of the functions.  Some of these
    are currently empty "stubs" which you are to complete.  It also contains the
    specification of struct sset_struct referred to in the .h file.

  - toy.c is a trivial client program.  You will write a similar program for 
    testing pourposes.

Compilation:

  Step 1:  compile sset.c.  Remember this does not become an executable.

         % gcc -c sset.c

      This produces an "object file" sset.o

  Step 2:  

         % gcc toy.c sset.o -o toy


      This compiles the program toy.c and links it with the object file
      sset.o.  It produces the executable toy.


