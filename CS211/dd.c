void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = start;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
 
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}