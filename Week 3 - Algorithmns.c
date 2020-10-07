
/////////////////////////////////////////////////////
//               Week 2 Algorithimns               //
/////////////////////////////////////////////////////

"Linear search"
Just going in a line to search for a result

"Binary search"
bi meaning two
if the data is sorted and you know it is sorted, you can go straight for the middle of the data and check what is there to see what to do
Decide to go higher or lower based on that and go to next middle number.
Decide where to go based on that until find number

// Big "O" notation, just means "on the order of" How much time an algoritmn takes
Instead of "it's just n, or n/2"
"on the order of n/2"
O(n) is basically equal to O(n/2)
O(log2 n) might aas well just be O(log n)

// Most expensive
O(n²)		Bubble sort, selection sort
O(n log n)  Merge sort
O(n)		Linear search
O(log n)	Binary search (only sorted data)
O(1)
// Least expensive

// Ω is how many steps in best case
Ω(n²)		unoptimised Bubble sort, selection sort
Ω(n log n)  merge sort
Ω(n)		counting, you have to look at all of them. Optimised bubble sort
Ω(log n)
Ω(1)		linear search, Binary search

// O will be more use in the real world as it can account for worst case / average case

// Also theta lol... means that O and Ω are identical

θ(n²)		Selection sort
θ(n log n)  Merge sort
θ(n)		
θ(log n)
θ(1)	

////    Shorthand assignment of arrays
// "statcially initialised array"
int numbers[6] = {4, 8, 15, 16, 23, 42};


// Code incarnation of linear search
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int numbers[6] = {4, 8, 15, 16, 23, 42};
	
	for (int i = 0; i < 6; i++)
	{
		if (numbers[i] == 50)
		{
			printf("found\n");
		}
	}
	printf("not found\n");
}

////    names.c example
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string names[4] = {"Emma", "Rodrigo", "Brian", "David"};
	
	for (int i = 0; i < 4; i++)
	{
		// Cant use == for strings in strings because it's an array
		//if (names[i] == "Emma")
		// Can use a string comparison function
		if (strcmp(names[i], "Emma") == 0)
		{
			printf("found\n");
		}
	}
	printf("not found\n");
}

// This will print "not found" regardless not because code is not stopped :P
int main(void)
{
	string names[4] = {"Emma", "Rodrigo", "Brian", "David"};
	
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(names[i], "Emma") == 0)
		{
			printf("found\n");
			return 0;
		}
	}
	printf("not found\n");
	return 1;
}

////    Phonebook example
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// A 2D array could work :3
	string names[4]  = {"Emma", "Rodrigo", "Brian", "David"};
	string number[4] = {"617-555-0100", "617-555-0101", "617-555-0102", "617-555-0103"};
	
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(names[i], "Emma") == 0)
		{
			printf("%s: %s\n", names[i], numbers[i]); //printf("%s\n", numbers[i]);
			return 0;
		}
	}
	printf("not found\n");
	return 1;
}

////    Making custom data typesssss
// 		I'm getting hyped cause I'm like "ARE WE GUNNA USE DICTIONARIES OR SOMETHING? I LOVE DICTIONARIES" XD
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define a type (int, string, bool etc are types)
// Structs are... "a container for multiple data types"
typedef struct
{
	string name;
	string number;
}
person; // Name the struct...

int main(void)
{
	// Define an array people as type person
	person people[4];
	
	// You can use curly bracket notation instead
	
	people[0].name   = "Emma";
	people[0].number = "617-555-0100";
	
	people[1].name   = "Rodrigo";
	people[1].number = "617-555-0101";
	
	people[2].name   = "Brian";
	people[2].number = "617-555-0102";
	
	people[3].name   = "David";
	people[3].number = "617-555-0103";
	
	
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(people[i].name, "Emma") == 0)
		{
			printf("%s\n", people[i].number);
		}
	}
	printf("not found\n");
	return 1;
}

// Curly bracket notation can be used but was not demonstrated,
// I looked it up c:
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	string name;
	string number;
}
person;

int main(void)
{
	person people[4] = {
		{"Emma", 	"617-555-0100"},
		{"Rodrigo", "617-555-0101"},
		{"Brian", 	"617-555-0102"},
		{"David", 	"617-555-0103"}
	};

	for (int i = 0; i < 4; i++)
	{
		if (strcmp(people[i].name, "Emma") == 0)
		{
			printf("%s\n", people[i].number);
			return 0;
		}
	}
	printf("not found\n");
	return 1;
}

// Should numbers be sorted then searched? What is the best way to optimise this?
// How does one sort data

You can locally check who is next to you, if larger, switch

This is called bubble sort, where the larger numbers buble to the end and

// SUDO
repeat n-1 times
	for i from 0 to n-2
		if i'th and i+1'th elements out of order
			swap them
in O...
outter loop takes n-1
inner loop n-1
(n - 1) x (n - 1)
n² -1n - 1n + 1
n² - 2n + 1
O(n²)

// Selection sort
looking at each and remembering the smallest
once you have the smallest number, swap it with the first place
And repeat, is this the next smallest, no, is this the...

// SUDO
for i from 0 to n-1
	find smallest item between i'th item and last item
	swap smallest item with i'th item
	repeat...
	
In O...
N + (n -1)+(n-2)+ ... +1
n(n + 1)/2
	
// Can optimise bubble
repeat until no swaps
	for i from 0 to n-2
		if i'th and i+1'th elements out of order
			swap them



// There are many types of sorts, oof


////    Recursion: A funtion that calls itself   ////
recursive function - one that references its own name in its own code

// Iteration.c example
#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
	int height = get_int("Height: ");
	
	draw(height);
}

void draw(int h)
{
	for (int i = 1; i < h; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

// Recursion.c example
#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
	int height = get_int("Height: ");

	draw(height);
}

void draw(int h)
{
	// Endless check
	if (h == 0)
	{
		return;
	}

	// Call upon this function to loop
	// This essentially takes from h as it reiterates
	// if h initialises as 1, 
	draw(h - 1);

	// Print this current line
	for (int i = 0; i < h; i++)
	{
		printf("#");
	}
	printf("\n");
	// If you put draw(h - 1) here, the pyramid will be upside down
}
// Me: it's esentially queuing up printf until it has the beginning step??
// This is part of a concept of "stack"

hehe, searching recursion in google will behave as if it is mispelt and links you to recursion....


////    Merge Sort    ////

// SUDO
if only one item
	return
else
	sort left half of items
	sort right half of items
	merge sorted halves

// Merge sort
7 4 5 2 6 3 8 1

7 4 5 2 | 6 3 8 1
7 4 | 5 2
7 | 4
Cant sort 7, can't sort 4, merge 7 & 4
4 7 -sorted list of size 2
sort right half
5 | 2
Cant sort 5, can't sort 2, merge
4 7 | 2 5
merge...
2 4 5 7...
Original right half
6 3 | 8 1
3 6, 1 8, merge
1 3 6 8
mege final...
2 4 5 7 | 1 3 6 8
1 2 3 4 5 6 7 8
n/2... n/2	logorithm
O(n log n)	
