
//================================================================
//						   Week 4 Shorts		               
//================================================================
//
//    line   CONTENTS
//================================================================
//    017  - Hexadecimals
//    071  - Pointers
//    195  - Defining custom types
//    247  - Dynamic Memory Allocation
//    335  - Call Stacks
//    424  - File Pointers
//================================================================


//    017   Hexadecimals
//----------------------------------------------------------------
//	HEX is mostly used as memory "addresses" and not for math or anything spoopy

//	Ordinary decimal system is called "base-10"
		0  1  2  3  4  5  6  7  8  9

//	Computers use binary, "base-2", to represent ALL data
		0  1
//    This is ofcourse, represented in bits
		...  8  4  2  1
	  
//	Hexadecimal come sin handy as...
//		It's useful to be able to express data the way computers do
//		problem: parsing a "huge chain" of 0's and 1's as a human is difficult

// Hexadecimal is "base-16" and goes as follows:
		0  1  2  3  4  5  6  7  8  9  A  B  C D  E  F
//		A group of 4 binary digits are needed to store the same value as 1 hex value

//	Decimal
		0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15
//	Binary
		0000	0001	0010	0011	0100	0110	0101	0111	1000	1001	1010	1011	1100	1101	1110	1111
//	Hexadecimal
		0x0		0x1		0x2		0x3		0x4		0x5		0x6		0x7		0x8		0x9		0xA		0xB		0xC		0xD		0xE		0xF


//	A number like
		397
//	Means something different than it seems, as it is to the 16th power
//			256  16  1
		0x  3 	 9 	 7

//	Binary is also easy to convert to HEX
//		group four binary digits(bits) from right to left
//			- Pad leftmost with extra 0's in necessary
//		Then convert ro the Hex value
		
//	Given:
		01000110101000101011100100111101
//	Break into groups from right:
//		Binary
		0100 0110 1010 0010 1011 1001 0011 1101
//		Decimal
		4	 6	  10   2    11	 9    3	   13
//		Hexadecimal
		0x4	 0x6  0xA  0x2  0xB  0x9  0x3  0xD

//	The whole thing in HEX is:
		0x46A2B93D // Which is a pretty big number...



//    071   Pointers
//----------------------------------------------------------------
//	Pointers are 64bits of data that store the "address" of the wanted data in memory

//	Pointers are an alternative way to pass data between functions
//		So far, the data that we have been passing into functions have been copies

//	Using this, we can make the swap function, that otherwise ins't possible

// Computer memory
//		Files all live on pc in HDD/SSD, byb itself, data can't be changed here
//		all manipulation of data is in the ram
//		memory == ram, which is basically giant arrays

//			data type		size (bytes)
//			int 			4
//			char			1
//			float			4
//			double			8
//			long long		8
//			strings			n+1...    	strings aren't real, they're "char star"s
//			char*           4 or 8

//			So strings really take up n+1 + (4 or 8) bytes, yikes

//		Arrays are not only useful for storage of information, but for "random access"
//			Can access individual elements of the array by indicating which index we want
//		similarly, each location in memory has an address.

//	20 bytes of memory thorectically, is an array like this
[   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   ]
  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
  
//	The computer will decide where to store data
//	Wont necessarily store the memory back to back
//	Given the variables...
char c = 'h';
int speedlimit = 65;
string surname = "Lloyd";
//	May store them like so
[   |   |   |   | H |   |   |   |       65      | L | l | o | y | d | \0|   |   ]
  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19

//	ofcourse, these places in RAM are actually HEXA, so
[   |   |   |   | H |   |   |   |       65      | L | l | o | y | d | \0|   |   ]
0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xA 0xB 0xC 0xD 0xE 0xF 0x10 0x11 0x12 0x13

//	Ofcourse, computers don't actually store these values, the store binary
//	And although 65 is treated as one value, it is seperate bytes at low-level

//	And even this isn't entirely true due to something called
endianness, little and big endianness...

//	Visual representation
int k;
//	imagine a green box, int's go in green boxes, 
	[    ]
      k
k = 5;
	[  5 ]
      k
int* pk; // A "greenish" box
//	[  5 ]				[    ]
      k					  pk
pk = &k;
//	[  5 ]				[0x12]
      k					  pk
//	it's easier to imagine a literal arrow
//	[  5 ]<-------------[----]
      k					  pk
	  
//	So a pointer is a data type whose
//		value is a memory address
//		type describles the data located at that memory address

//	The simplest pointer available is the NULL pointer, which points to nothing
//		When you create a pointer and you don't set its value, you should set it to NULL
//		Can be checked with the equality operator (==)

//	Another easy way to create a pointer is to simply "extract" the address of an already existing variabel.
//		This can be done with the extraction operator (&)

//		If x is an int, the &x is a pointer-to-int whose value is the address of x

//		If arr is an array of doubles, the &arr[i] is a pointer-to-double whose value is the address of the ith element of arr
//			an arrays name is actually just a pointer to ther first element

//	the main purpose of a pointer is to allow us to modify or inspect the location it points to
//		We do this by "dereferenceing" the pointer
		
//	If we have a pointer-to-char called pc, then *pc is the data that lives at the address storec in pc

//	used in this context, * is known as the "dreference operator"
//		it "goes tot eh reference" and accesses the data a tthe memory location

//	This is just like visiting your neighbor. having their address isn't enough. You need to "go to" the address and only then, you can intereact with them

//	What happens if you dereference a NULL pointer?
//		segmentation fault? D:
//	This is actually good behaviour! It defends against accidental manipulation of unknow pointers
//		Just like with making variables and not setting them to anything, they equal garbage values
//		Which could inevitably mess with something you didn't intend to mess with, so a crash or a fault is better than screwin with another function or program

//	Coming back to syntax
int *p
//	the value of p is an address
//	can be dereferenced with *
//	if we do, we'll find an int at that address

//	Annoying thing with *s. they're an important part of both the type name and the variable name
int* px, py, px;
//	Here, px will be a pointer, but the others wont!
int *px, *py, *pz;
//	As if you'd actually use this, declare them individually

//	Back to k & pk problem
*pk = 35
//	This will change k to 35
int m = 4;

pk = &m // pk becomes pointer to m



//    195   Defining custom types
//----------------------------------------------------------------
//	Creating your own types
//	There's a shorthand for the struct lyout

//	typedef
//		the basic idea is to first define a type in the normal way, then alias it to something else.

typedef <old name> <new name>;
// Like this:
typedef unsigned char byte;
// which essentially means that instead of typing "unsigned char", you can just type "byte"
typedef char* string;

struct car
{
	int year;
	char model[10];
	char plate[7];
	int odometer;
	double engine_size;
};
typedef struct car car_t;
// Following this, I can now reference to struct car as just "car_t"

// alternatively, you can do this:
typedef struct car
{
	int year;
	char model[10];
	char plate[7];
	int odometer;
	double engine_size;
}
car_t;

// If I don't do typedef...
struct car mycar;

mycar.year     = 2011;
mycar.plate    = "CS50";
mycar.odometer = 50505;

// 	With the typedef
car_t mycar;

mycar.year     = 2011;
mycar.plate    = "CS50";
mycar.odometer = 50505;



//    247   Dynamic Memory Allocation
//----------------------------------------------------------------
//	We can use pointers to access a block of dynamically alloacted memory at runtime
//	Dynamically allocated memory comes from a pool known as the "heap"
//	Prior to this point, all memory we've been working with comes froim the "stack"

--------------------
|       text       |
--------------------
| Initialized data |
 -------------------
| Unitialized data |
--------------------
|       heap       |
|	      |        | 
|		  v	       |
|		     	   |
|		     	   |
|		  ^	       |
|	      |        | 
|       stack      |
--------------------
| environment vars |
--------------------

//	To access the heap, we need to use malloc(bytes)
//	After obtaining the memory (if it can), malloc() returns a pointer to that mem
//		If it can't, it'll return NULL
//	Always check for NULL after malloc

//	Requires library
#include <stdlib.h>

int = malloc(4)
etc

//	statically obtain an integer
int x;
//	dynamically obtain an int
int *px = malloc(4);    OR    int *px = malloc(sizeof(int));

//	get_int function:
int x = get_int();

//	array of floats on the stack of size x
float stack_array[x];
//	This is "legal" on C99 & C11, older C, nope

//	dynamically allocate on the HEAP
float* heap_array = malloc(x * sizeof(float));

//	The catch to dynamically allocating is that you have to free() it!!!
//		It is not automatically released when not in use
//	Failing to return memory results in a MEMORY LEAK
//	When you finish working with dynamically-allocated memory, you must free() it.
//	ALL memory is freed when the program is done running
free(pointer to malloc memory)

char *word = malloc(50 * sizeof(char));
//	Do stuff with word
//	When we're done...
free(word);

//	Rules:
//		Every time you use malloc() you must free() it
//		Only malloc memory should be freed
//		do note free() more than once
//			"double free" "inverse memory leak", "memory flow", "where you trick the system into thinking you have more memory than you do" lol

int m;
int *a;
int *b = malloc(sizeof(int));
if (b == NULL)
{
	return 0;
}
a = &m; // A now points ot m

a = b;
//	a will now point to the same place as b is pointing
m = 10;
*b = m + 2; // will access b and set it to m(10) + 2
free(b);
//	a & b still point there
*a = 11;    // UNPREDICATABLE behaviour, memory is not ours anymore, seg fault probs



//    335   Call Stacks
//----------------------------------------------------------------
//	How do functions operate and run in conjunction to other code? CALL STACK

//	when you call a function, a chunk of memory will be set assid so that function can do it's job.
//		These "chunks" are called "stack frames" or "function frames"
//		More than one function's stack frame may exist in memory at a given time. if main() calls move(), which calls direction(), all three functions have open frames.

//		These frames are arranged in a STACK. the frame for the most recently called function is always on the top of the stack
//		When a new function is called, a new frame is pushed onto the top of the stack and becomes the active frame.
//		When a funtion finishes its work, its frame is popped off of the stack, and the frame below becomes the new active frame and the function starts wher eit left off

--------------------
|	 direction()   | // This will run FIRST, when complete, it "pops off" and...
--------------------
|	    move()     | // This frame becomes the active frame...
--------------------
|       main()     | // When both ar ecomplete, main resumes
--------------------

//		Each is waiting to become the top of the stack again and are "on pause" until the active frame executes

//	Example with factorial function

int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n-1);
}
int main(void)
{
	printf("%i\n", fact(5));
}

   --------------------
   |	   fact(1)     | // Reaches base case and returns 1
   --------------------
🠉  |	   fact(2)     | // calls ^, pause
   --------------------
🠉  |	   fact(3)     | // calls ^, pause
   --------------------
🠉  |	   fact(4)     | // calls ^, pause
   --------------------
🠉  |	   fact(5)     | // calls ^, pause
   --------------------
🠉  |	   printf()    | // printf() calls fact(5) ^ and pauses...
   --------------------
🠉  |       main()     | // main() calls ^ and pauses...
   --------------------
   
// The actice frame (fact(1)) gets destroyed and fact(2) becomes the active frame, now unpausing

   --------------------
🠋  |	   fact(2)    | (n * fact(1)) = 2 * 1 
   --------------------
🠉  |	   fact(3)    | // calls ^, pause
   --------------------
🠉  |	   fact(4)    | // calls ^, pause
   --------------------
🠉  |	   fact(5)    | // calls ^, pause
   --------------------
🠉  |	   printf()   | // printf() calls fact(5) ^ and pauses...
   --------------------
🠉  |       main()     | // main() calls ^ and pauses...
   --------------------
   
//	Repeat...
   --------------------
🠋  |	   fact(3)    | (n * fact(2)) = 3 * 2
   --------------------
🠋  |	   fact(4)    | (n * fact(3)) = 4 * 6
   --------------------
🠋  |	   fact(5)    | (n * fact(4)) = 5 * 24
   --------------------
🠋  |	   printf()   | printf(120)
   --------------------
🠋  |       main()     | // main() calls ^ and pauses...
   --------------------

//	main() becomes the active frame 
--------------------
|       main()     | 
--------------------
//	if it has nothing to do, it will pop off the frame and the program terminates



//    424   File Pointers
//----------------------------------------------------------------
//	Reading, Writing, appending
//	Allows for persistent data that remains when the program terminates

//	The abstraction of files that C provides is implemented in the data structure FILE.
//		Generally, files are accessed using pointers
FILE *filename;

//	All of these functions that work with creating and accessing files live in stdio.h
#include <stdio.h>
//	All of them accept FILE* as parameters, except fopen() which gets the file pointer in the first place

//	Some of these functions that this will look at:
fopen() fclose() fgetc() fputc() fread() fwrite()


/// file open ///
fopen(<filename>, <operation>)
//	opens a file and returns a file pointer to it.
//	always check the return value to make sure you don't get NULL
//	ptr is a generic file pointer name
FILE *ptr1 = fopen(file1.txt, "r"); //read
FILE *ptr2 = fopen(file2.txt, "w"); //write
FILE *ptr3 = fopen(file3.txt, "a"); //append
//	Write will overwrite file, append will add to the end of it.


/// file close ///
fclose(<file pointer>); 
//	closes the file pointed to by the given file pointer
fclose(ptr);


/// file get character ///
fgetc(<file pointer>)
//	reads and returns the next character from the file pointed to. (or first if first time calling)
//	The opperation of the file pointer passed in as a parameter must be "r"  or you will get an error
char ch = fgetc(ptr1);
// wrapped in a loop, this gives the ability to print characters to the screen one by one.
char ch; /// int ch;
//		if this character in file is not "end of file" character
while ((ch = fget(ptr1)) != EOF)
	print("%c", ch);
//	the linux command "cat" does exactly this "concatonated"
// COMMENTS pointed out that this code is incorrect as char cannot be EOF... use int ch;


/// file put character ///
fputc(<character>, <file pointer>)
//	Writes or appends the specified character to the pointed-to-file
//	operation on the file pointer must be "w" or "a"
fput('A', ptr2);
fput('!', ptr3);
//	We can use this to copy one file to another

int ch;
while((ch = fgetc(ptr)) != EOF)
	fputc(ch, ptr2);
//	This essentially does what the cp command in linux does

/// file read ///
fread(<buffer>, <size>, <qty>, <file pointer>)
//	file -> buffer
//	reads <qty> units of <size> from the file pointed to and stores them in memory in a buffer (usually an array) pointed to by <buffer>
//	operation must be in "r"
int arr[10];
fread(arr, sizeof(int), 10, ptr2);
// Reads 40 bytes of info and stores into arr
//	Array's are address so don't need &arr

double *arr2[80] = malloc(sixeof(double) * 80);
fread(arr2, sizeof(double), 80, ptr2);
//	Can use this like fgetc()
char c;


/// file read ///
fread(<buffer>, <size>, <qty>, <file pointer>)
//	buffer -> file
//	writes <qty> units of <size> to the <buffer
//	Operation must be "w" or "a"
int arr[10];
...
fwrite(arr, sizeof(int), 10, ptr);
//	single var
char c;
//	Must use address!!
fwrite(&c, sizeof(char),1, ptr);

//	Lots of other useful functions in stdio.h!!
fgets()		reads a full string from a file
fputs()		writes a full string to file
fprintf()	writes a formated string to file // variable subs etc
fseek()		allows you to "rewind or fasforward" within a file // "move around the file" "there's an indicator as to where you are"
ftell()		tells you at what(byte) position you are at within a file 
feof()		tells you wherther you've read to the end of the file
ferror()	indicates whether an error has occurred in working with a file
