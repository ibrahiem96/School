int is_sorted(NODE* list){
	
	NODE *p = list;

	if (p==NULL) return 1;

	while (p->next!=NULL){
		if (p->val > p->next->val)
			return 0;
		p = p->next;
	}

	return 1;
}

NODE *append(NODE *list, int val){ //insertion may also be done likewise

	NODE *temp = (NODE*)malloc(sizeof(NODE)); //assign temp node memory
	temp->val = val; //value in temp node is assigned
	temp->next = NULL; //there is no node after temp

	if (list == NULL){
		list = temp; //list is equal to the temp node
		return list;
	} 

	NODE *prev = NULL;
	NODE *curr = list;

	while (curr!=NULL){

		prev = curr; //current node becomes previous node
		curr = curr->next; //next node becomes current node
	}

	prev->next = temp; //once end of list is reached, curr is NULL, so temp must be appended using the previous node
	temp->next = curr; //because curr is NULL

	return list;
}

NODE *merge(NODE *list1, NODE *list2){ //intersection and difference can also be done with use of recursion

	if (list1==NULL) return list2;
	if (list2==NULL) return list1;

	if (list1->val <= list2->val){
		list1->next = merge(list1->next, list2); 
		return list1;
	}

	else{
		list2->next = merge(list1, list2->next);
	} 
}

/*
What's left:
- linked list functions
- Big O proofs
- Runtime analyses
- Proving #12 algorithm for other cases
- #9 and #10