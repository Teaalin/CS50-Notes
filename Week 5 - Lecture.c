
//================================================================
//						   Week 5 Lecture		               
//						  Data Structures
//================================================================

//	buggy example
int main(void)
{
	int *x;
	int *y;
	
	x = malloc(sizeof(int)); // allocates size of int into the x pointer
	
	*x = 42; //goto the address of x and set it to 42
	*y = 13; // haven't allocated the memory yet so the address is a garbage value
}

//	"fixing" int
int main(void)
{
	int *x;
	int *y;
	
	x = malloc(sizeof(int));
	
	*x = 42;
	
	// what if instead 
	y = x; // sets y to equal the same pointer of x
	*y = 13; // sets the information at both x and y to 13, overriding 42
}
//	what if we want to grow an array?
//	need to move to a new space in memory that has the space

[1, 2, 3] adding a fourth position with value of 4...
reallocate...
one by one
to a new array and
clear the old array
[1, 2, 3, 4]
//	 but this takes a lot of work!

insert
//	the steps to achieve this are...
O(n) // it must take n steps
Ω(...)

//	list.c example
#include <stdio.h>

int main(void)
{
	int list[3];
	
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	for (int i = 0; i < 3; i ++)
	{
		printf("%i\n", list[i]);
	}
}
//	malloc
int main(void)
{
	int *list = malloc(3 * sizeof(int));
	
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	for (int i = 0; i < 3; i ++)
	{
		printf("%i\n", list[i]);
	}
}
//	malloc cal fail to allocate memory so a check should be used
if (list == NULL)
{
	return 1;
}

#include <stdlib.h>

int main(void)
{
	int *list = malloc(3 * sizeof(int));
	if (list == NULL)
	{
		return 1;
	}
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	//	Say we want to allocate more memory later
	int *tmp = malloc(4 * sizeof(int));
	if (tmp == NULL)
	{
		return 1;
	}
	//list = tmp;
	
	// copy integers from old array into new array
	for (int i = 0; i < 3; i++)
	{
		tmp[i] = list[i];
	}
	tmp[3] = 4;
	
	free(list);
	list = tmp;
	free(tmp)
	
	for (int i = 0; i < 4; i ++)
	{
		printf("%i\n", list[i]);
	}
}

//	there is a funtion for this
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *list = ralloc(3 * sizeof(int));
	if (list == NULL)
	{
		return 1;
	}
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	//	Say we want to allocate more memory later
	int *tmp = realloc(4 * sizeof(int));
	if (tmp == NULL)
	{
		return 1;
	}
	list = tmp;
	
	tmp[3] = 4;
	
	for (int i = 0; i < 4; i ++)
	{
		printf("%i\n", list[i]);
	}
	free(list);
}
// realloc takes the old data, copies it over

//	this lesson will focus on...
struct
. (dot operator)
* (dereffernce operator)

constant time access = random access (accessing arrays and stuff)


//	one can have items scattered in memory  but linked with pointers
|1|
|p|		|2|		|3|
		|p|		|p|

//	this can be achieved with structs
typedef struct node
{
	int number;
	struct node *next;
}
node; // A chunk of mem that does stuff

// can change the name of the original to anthing but it kinda loses the point
typedef struct butts
{
	int number;
	struct butts *next;
}
node;

//	list idea again

node *list = NULL;
node *n = malloc(sizeof(node));
(*n).number = 2; // set the number of this node to 2
//can actually be a lot cleaner thanks to syntactic sugar
n->number = 2;
n->next = NULL;

//	clean it up
node *n = malloc(sizeof(node));
if (n != NULL)
{
	n->number = 2;
	n->next = NULL;
}
//	looks like this
|list|		
|    |     	| 2 |
			|	|
//	how to link it up?
list = n;

|list|		
|    | --->	| 2 |
			|	|
//	how do we go about adding another node to this list?
|list|		
|    | --->	| 2 |
			|	|->	| 4 |
					|   |
//	to update the list, follow the list and see if the pointers are NULL
node *tmp = list;
while (tmp->next != NULL)
{
	tmp = tmp->next; // go to the next node
}
// what if we want to bring in a new node that's earlier in the list?

//	|list|		
//	|    | --->	| 2 |
//		|		|	|->	| 4 |
//		v				|   |
//		| 1 |
//		|	|

//	DO not just point list at 1 as that abandons all the other values!!
//	instead, point 1->next to 2, THEN point list to 1
n->next = list;
list = n;

//	middle add?
//	|list|		
//	|    | 		| 2 |
//		|		|	|	->	| 4 |
//		v	   /			|   |
//		| 1 |/		| 3 |
//		|	|		|   |

//point 3 to what's higher than it, 4
// then point 2 to 3
node *tmp = list;
node *prv = NULL;

// until the end of the list
while (tmp->next != NULL) //for (int i = 0; i < 3; i++)
{
	//	if this number is greater than the input number
	if (tmp->number > n)
	{
		// set the new number to reference it and break;
	//	n->next = tmp
		break;
	}
	//	set a previous variable to keep track of the one behind
	prv = tmp;
	//	if a number higher than new input isn't found, keep going
	tmp = tmp->next;
	//	need a check to see if the list ends without a match...
	//if (tmp->next == NULL)
	//{
	//	n->next = tmp
	//}
}
// Set to tmp
prv->next = n
n->next = tmp

//	does the above need a case for if the first number is larger >>

//	this loses random access

//	searching through this cannot use binary searching
//	must jump through each

O(n)

//	list 3 example

#include <stdio.h>
#include <stdlib.h>

//	Represents a node
typedef struct node
{
	int number;
	struct node *next;
}
node;

int main(void)
{
	//	list of size 0
	node *list = NULL;
	
	//	add number to list
	node *n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	
	n->number = 1;
	n->next = NULL;
	list = n;
	
	//	add number to list
	n = malloc(sizeof(node);
		if (n == NULL)
	{
		return 1;
	}
	n->number = 2;
	n->next = NULL;
	list->next = n; // Link node 1 to 2
	
	//	add number to list
	n = malloc(sizeof(node);
		if (n == NULL)
	{
		return 1;
	}
	n->number = 3;
	n->next = NULL;
	list->next->next = n; // Link node 1 to 2
	// A better solution would be to loop through...
	
	//	print list
	for (node *tmp = list; tmp != NULL; tmp = tmp->next)
	{
		printf("%i\n", tmp->number);
	}
	
	//	free list
	while (list != NULL)
	{
		node *tmp = list->next;
		free(list);
		list = tmp;
	}
}
//	could dedicate a fuction instead of repeat...


//	but anyway, back to the issue of no ranom access
trees

////	binary search trees...

//	in a 1d array setup it goes something like this
| 1 | 2 | 3 | 4 | 5 | 7 |
// where 4 comes first, it may then do 2 or 6, then 1,3,5 or 7...
//	but what if we look at it like a 2d tree?
//            | 4 |
//			
//    | 2 |           | 6 |   
//	
//| 1 |   | 3 |   | 5 |   | 7 |
//	we could break it down and add more pointers

typedef struct node
{
	int number;
	struct node *left;
	struct node *right;
}node;

//	where each references a left or right neighbor creating a tree
//          4
//       /      \
//     2         6
//   /   \     /   \
//  1     3   5     7 

//	this is apparently the best use of recursion

//	tree example
bool search(node *tree)
{
	//	base case
	if (tree == NUll)
	{
		return false;
	}
	//	recursive case
	else if (50 < tree->number)
	{
		return search(tree->left);
	}
	else if (50 > tree->number)
	{
		return search(tree->right);
	}
	else
	{
		return true;
	}
}

//	we gain back binary search
O(log n)
//	there is oppertunity to insert data but it would need to be shifted around a good bit
//	shifting as in, changing the pointers
//	and ballancing it out

//	wouldn't it be cool if you could just jump to a position?
Hash tables are cool
is a combination of an array and linked lists inside of it

//	pset5 implements a hash table that lets you spell check super fast
//		searching a dictionary for a word with the other methods would take a stupid amount of time!!

//	common to look at he characters of words in hash tables

//	it's called a "collision" when you're trying to put a value somewhere where there is already a value
https://youtu.be/4IrUAqYKjIA?t=5068

// a hash fuction "bucketises" the given information and figures where to store it

//	"ideal has function" where none of the data collides
O(n) //	at worst worst

tries (spoken as "try", short for retrieval)
//	uses names or words
is a tree, each or whose nodes is a tree
//	the base node may look like...
[ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ]
// so to store / find hagred..
[               H                                     ]
// <------------
[ A                                                   ]
//  --------->
[             G                                       ]
//				----------------->
[                                   R                 ]
//				   <---------------
[                 I                                   ]
//		 <-------
[       D                                             ]
//	some kind of bool to say someones name exists here

//	for each, the steps are the same as the count of chars

//	so for this, it's big o of (1) at the cost of memory

queue = data structure that is fifo (first in first out)
//oppostie is lifo (last in first out)
enqueue = get in line
dequeue = get out of line

stacks
usually lifo
push = adding to the stack
pop  = removing from the stack

dictionaries
//	is a data structure that has keys and values
//	I LOVE ME SOME DICTIONARIES
//	