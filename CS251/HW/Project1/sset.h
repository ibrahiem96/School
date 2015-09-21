
// File:  sset.h

// Note:  struct sset_struct is "hidden" in
//   sset.c
typedef struct sset_struct SSET;

/**
* Function:  sset_create
* Status:  DONE
* Returns an empty set
*/
extern SSET *sset_create();

/**
* Function:  sset_singleton
* Status:  DONE
* Returns the set {x}
*/
extern SSET *sset_singleton(int x);


/**
* Fuction:  sset_from_array
*
* Status:  DONE (but subroutine from_sorted_array needs
*   implementation)
*
* Parameters:
*
*   a:  base address of an array of integers
*   n:  array length
*
* Returns the SSET * representation of the elements.
*
* Notes:  given array not necessarily sorted and
*  may have duplicates.
*/
extern SSET *sset_from_array(int *a, int n);

/**
* Function:  sset_isempty
* Status:  DONE
* 
* Description:  self-evident
*/
extern int sset_isempty(SSET *s);

/**
* Function:  sset_size
* Status: DONE
*
* Description:  returns the cardinality of the
*   given set.
*/
extern int sset_size(SSET *s);

/**
* Function:  sset_display
* Status:  DONE
*
* Description:  prints the contents of the set s in 
*   curly-brace style.
*/
extern void sset_display(SSET *s);

/**
* Function  sset_contains
* Status: TODO
*
* Description:  Returns 0 or 1 accordingly
*
* Requirement:  linear time
* Recommendation:  recursion
*/
extern int sset_contains(SSET *s, int x);

/**
* Function:  sset_clone
* Status:  DONE
*
* Description:  creates and returns a clone of the set s.  
*   Afterwards, there are two distinct sets which happen
*   to have the same contents.
*/
extern SSET *sset_clone(SSET *s);


/**
* Function:  sset_free
* Status:   TODO
*
* Description:  de-allocates all memory associated with the
*   parameter set.
*
* Requirements:  linear time
*                recursive
*/
extern void sset_free(SSET *s);

/**
* Function:  sset_union
* Status:  DONE
*
* Description:
*   
*   self evident (?)
*/
extern SSET *sset_union(SSET *a, SSET *b);

/**
* Function:  sset_intersection
* Status:  TODO
*
* Description:  returns a new sorted set which is the 
*   intersection of the given sets a and b.
*
* Requirements:  linear time
*                recursive
*/
extern SSET *sset_intersection(SSET *a, SSET *b);

/**
* Function:  sset_diff
* Status:  TODO
* 
* Description:  constructs and returns the difference 
*    of set a with set b.
*    Recall that  A - B = {x in A s.t. x NOT-IN B}
*
*    Example:  {3, 7, 11, 14} - {3, 5, 11, 20} = {7, 14}
*
* Requirements:  linear time
*                recursive
*
*/
extern SSET *sset_diff(SSET *a, SSET *b);

/**
* Function  sset_toarray
* Status:  TODO
* Description:  allocates and returns an array containing the 
*   elements of the given set.
*
* Requirement:  linear time
*/
extern int *sset_toarray(SSET *a);


/**
* Function:  sset_cmp
* Status:  TODO
*
* Compares sets a and b lexicographically (essentially like alphabetical).
*
*    If "a < b", a negative number is returned.
*    if "a > b", a positive number is returned.
*    if a and b are identical, zero is returned.
*
*    Lex rules:
*       The empty set precedes all other sets
*       For non-empty A={a0, ...}, B={b0, ...}, compare a0 and b0
*
*           - if a0 != b0 set with smallest first elem "wins"
*           - otherwise, compare A-{a0} with B-{b0}
*            
*     Example:
*              A = {2, 3, 5, 8, 10, 11}
*              B = {2, 3, 5, 7, 1000, 2000, 30000}
*
*             we have ties on frst 3 elements; then 7<8 so B < A.
*
*     Example:
*              A = {2, 3, 5}
*              B = {2, 3, 5, 7, 1000 }
*
*             Again, ties on first three elements; then we are comparing {} with
*             {7, 1000} so A < B
*
*  Note:  you will use this function to complete the sset_sort_sets
*    function (which will use qsort).
*          
* Requirements:  linear time
*                recursive
*/
extern int sset_cmp(const void *set_a, const void *set_b);

/**
* Function:  sset_sort_sets
* Status:  TODO
* Description:  Takes an array of sets (array element type:  
*   SSET *) and sorts  the sets according to the lexicographic 
*   rules of the  sset_cmp function.
*
* This should be a very short function!!  It really just act as 
*   a "wrapper" function which calls the qsort library routine.
*
* Hint:  you need to get sset_cmp working first
*/
extern void sset_sort_sets(SSET * sets[], int n);
  	
extern void sset_sort_sets(SSET * sets[], int n);
