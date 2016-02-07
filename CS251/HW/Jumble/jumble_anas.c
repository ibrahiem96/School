#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hmap.c"


//char word[128];

NODE *create_List(char *a, char *b)
	{
	NODE *new = (NODE *) malloc(sizeof(NODE));
	new->key = a;
	new->val = b;
	new->next = NULL;
	return new;
	}


void myprint(void *a, char *b)
	{

	int l;

	printf("Sorted array is...\n");

                for (l = 0; l < 128; l++)
                        printf("%c", b[l]);
			
                printf("\n");
	}


void mysort(char *a)
	{
	int j, k;
                char temp;
	int size = strlen(a);

                for (j = 0; j < size; j++)
                        {
                        for (k = 0; k < size - 1; k++)
                                {
                                if (a[k] > a[k + 1])
                                        {
                                        temp = a[k];
                                        a[k] = a[k + 1];
                                        a[k + 1] = temp;
                                        }
                                }
			}
	
	
	}


void mylowercase(char *word)
	{
	for(int i = 0; word[i]; i++)
        	word[i] = tolower(word[i]);
        
	}


		





int main(int argc, char* argv[])
	{
	char word[128];

	NODE *list;

	HMAP_PTR dict = hmap_create(0, 1.0);
	hmap_set_hfunc(dict, NAIVE_HFUNC);

	int i, x, lenght;
	char nword[128];

	if(argc == 2)
		{
		FILE *fp;
		fp = fopen(argv[1], "r");
		if(fp == 0)
			{
			printf("the file is empty\n");
			return 0;
			}
		else
			{
			

		while(fgets(word, 128, fp) != NULL)
				{
						
				lenght = strlen(word);

				char *nword = (char *) malloc(sizeof(char) * lenght);
				char *key = (char *) malloc(sizeof(char) * lenght);
				strcpy(nword, word);
			//	nword = word;
				mylowercase(word);
				mysort(word);

			//	key = word;		
				strcpy(key, word);
				printf("The key is %s\n", key);
				printf("The word is %s\n", nword);

				list = create_List(key, nword);
				if(hmap_contains(dict, list->key)==0)
					hmap_set(dict, list->key, list);

				else
					{
					NODE *temp;
					temp = hmap_get(dict, list->key);

					NODE *insert = temp;
					while(temp->next != NULL)
						temp = temp->next;

					temp->next = list;
					hmap_set(dict, list->key, insert);
					}
				}
		

			}
		}




	printf("Please Enter a string to display it's sister strings, or '.' to terminate\n");
	char user[128];
	char key2[128];
	
	scanf("%s", user);
	if(strcmp(user, ".") == 0)
		{
		printf("The program has been terminated\n");
		hmap_display(dict);
	        hmap_print_stats(dict);
		return 0;
		

		}

	while(strcmp(user, ".") != 0)
		{
		strcpy(key2, user);	

		mylowercase(user);
		mysort(user);

		printf("user: %s\n", user);
		printf("key2: %s\n", key2);
//		hmap_display(dict);
//		NODE *tmp = hmap_get(dict, "aaigglnr");
//		printf("hmap: %i\n", hmap_contains(dict, user) );
//		return 0;	
		if(hmap_contains(dict, user) == 1)
			{
			printf("key is found");

			NODE *new;
			new = hmap_get(dict, user);
			

			if(new == NULL)
				printf("NULL");
			else
				printf("%s", new->val);		

			while(new != NULL)
  				{
    				printf("%s p \n", new->val);
    				new = new->next;
  				}
			
			}
		else if(hmap_contains(dict, user) == 0)
			{
			printf("key not found\n"); 
			}

		scanf("%s", user);
		}
	
		hmap_display(dict);
                hmap_print_stats(dict);



	}
		
