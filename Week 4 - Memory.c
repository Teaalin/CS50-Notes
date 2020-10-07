
/////////////////////////////////////////////////////
//					Week 4 Memory		           //    
/////////////////////////////////////////////////////

// Hexadecimal
// Goes up to 15, but does not use conventional method
0 1 2 3 4 5 6 7 8 9 A B C D E F

// 8 bit binary goes up to 255
// to represent 255 in HEX
16 1
F  F
// Each place is to the power of 16
00 = 0
0F = 15
10 = 16
1F = 31
20 = 32

// RGB YEEEE
color is in HEX
00 00 00 = black
ff 00 00 = red
00 ff 00 = green
00 00 ff = blue
ff ff ff = white

// So this looks like...
0   1   2   3   4   5   6   7   
8   9   A   B   C   D   E   F
10  11  12  13  14  15  16  17  
18  19  1A  1B  1C  1D  1E  1F

// People decided that to represent tha tit is HEX, that they'd pu 0x infront of each number
0x0   0x1   0x2   0x3   0x4   0x5   0x6   0x7   
0x8   0x9   0xA   0xB   0xC   0xD   0xE   0xF
0x10  0x11  0x12  0x13  0x14  0x15  0x16  0x17  
0x18  0x19  0x1A  0x1B  0x1C  0x1D  0x1E  0x1F

// That's it for decimals
// apparently there's something called "octal" but wont look at that

//// Example "address.c"
#include <stdio.h>

int main(void)
{
	int n = 50;
	printf("%i", n);
}

// n is stored in an "address" in the PC's ram at a hex location
#include <stdio.h>

int main(void)
{
	int n = 50;
	printf("%p", &n);
}
// & is the "address of" operator
// Means, go and figure out what its address is
// %p is the required format for printing this address

// this is a "pointer" to that value

// * means "go to an address"
#include <stdio.h>

int main(void)
{
	int n = 50;
	printf("%i", *&n);
}
// This gets the value that is stored at the addres of n lol

int main(void)
{
	int n = 50;
	// This basically means, this is the address of an int
	int *p = &n;
	printf("%i", *p);
}

// technically this is what this "looks" like in ram
[0x12345678] // stores
[     p    ] //var
   
   
[     n    ] //var
[0x12345678] //address

// in normal discussion about pointers, we don't actually care about the address itself, we just care that it "points" to the variable
[     p    ]
//    |
//    v
[     n    ]
[0x12345678]
// This can be used for various types of data structures
// lists, trees, family trees, fancy algorithms(google, fb etc)

// also pointers use 64 bits, the equivilent of a long

//// Strings are pointers
|		      0x123               | // 64bits
|                s                | 
//               |
//               v
 _________________________________
| s[0] | s[1] | s[2] | s[3] | s[4]| // 40bits
|E     |M     |M     |A     |\0   |
|0x123 |0x124 |0x125 |0x126 |0x127|

// Insert matrix meme about "there is no string"

char *s = "EMMA";

// Coming back to how strings are made
// Declares a type 
typedef char *string;
// "char star"
// A string is simply an address of a character

//// Example address continued
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string s = "EMMA";
	printf("%s\n", s);
}
// this is with the training wheels of cs50, begining to take them off..
#include <stdio.h>

int main(void)
{
	char *s = "EMMA";
	printf("%s\n", s);
}
// for curiousities sake... what's the address for these things?
#include <stdio.h>

int main(void)
{
	char *s = "EMMA";
	printf("%p\n", s); // smthing like 0x12345678
	printf("%p\n", &s[0]); // Finds the address of the first char
	// this will print the same thing
}
// what will be found here?
printf("%c\n", *s)
// in this case, "E"
printf("%c\n", *s + 1)
// in this case, "M"
printf("%c\n", *s + 2)
// in this case, "M"
printf("%c\n", *s + A)
// in this case, "A"
printf("%c\n", *s + 3)
// in this case, "\0"

// So the "bracket" symbol is..
// Syntactic sugar!!
// A handy feauture for easy access
technically each time you access with bracket, it's coverting it to the likes of the above


//// pointer arithmatic
// means to take an address and add to them


// Also printf is special and knows that printing a string means to go to that location and print everything up to the null char

//// EXAMPLE: compare.c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int i = get_int("i: ");
	int j = get_int("j: ");
	
	if (i == j)
	{
		printf("same\n");
	}
	else
	{
		printf("different");
	}
}

// Comapare strings#include <cs50.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string s = get_string("s: ");
	string t = get_string("t: ");
	
	if (s == t)
	{
		printf("same\n");
	}
	else
	{
		printf("different");
	}
}
// This will always print "different"
// This is because the "string" is a pointer!
// therefor s may equal 0x12345
// and t may equal 0x54321
// therefore, different.

// This is the same as...
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	char *s = get_string("s: ");
	char *s = get_string("t: ");
	
	if (s == t)
	{
		printf("same\n");
	}
	else
	{
		printf("different");
	}
}
// get_string() returns the address of the first character

//// EXAMPLE: copy.c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	string s = get_string("s: ");
	string t = s;
	
	t[0] = toupper(t[0]);
	
	printf("%s\n", s);
	printf("%s\n", t);
}
// this will print the same thing because t IS the same string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// Get the string from user
	char *s = get_string("s: ");
	
	// Keep the string length cause it's reused
	int n = strlen(s);
	
	// Memory allocate the same bytes
	char *t = malloc(n + 1); 
	
	// must be one more step to copy the null character
	//                <=
	for (int i = 0; i <= n; i++)
	{
		// Copy each char over to t
		t[i] = s[i];
	}
	
	// Set the first character of the copy to be a capital letter
	t[0] = toupper(t[0]);
	
	//print both
	printf("%s\n", s);
	printf("%s\n", t);
}

// Can simplify
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = get_string("s: ");
	char *t = malloc(strlen(s) + 1); // Memory allocate the same bytes
	
	strcpy(t, s);
	
	t[0] = toupper(t[0]);
	
	printf("%s\n", s);
	printf("%s\n", t);
}

// If you forgot to copy over the null character...
// The results would vary
// if there happened to be something there... it'll run until htere's a \0
// And print a heap of "garbage values" instead

// Malloc will return the address of the chnk of data that it reserves
// If you malloc, you MUST free the memory!!

// There is debuggin tool (not CS50 specific) that can be used to find issues like these

////    Valgrind (val-grin-d)
// Not the easiest thing to understand at first glance

usage:
valgrind ./copy
// will run the program with the check
// Will tell you that there is a memory issue
s: emma
// will spit out a loooong error about the memory leak

// Focus on the important part of the error
// leak = BAD lol
// Look for the line that is the source
// find the amount of leak

// deallocate the memory after use simply with
free(t);

// So...
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = get_string("s: ");
	char *t = malloc(strlen(s) + 1); // Memory allocate the same bytes
	
	strcpy(t, s);
	
	t[0] = toupper(t[0]);
	
	printf("%s\n", s);
	printf("%s\n", t);
	
	free(t);
}

// if run in valgrind again it will still spit out a wall of text, but will say 0 bytes in 0 blocks


////    EXAMPLE: Memory.c
// http://valgrind.org/docs/manual/quick-start.html#quick-start.prepare

#include <stdlib.h>

void f(void)
{
	// int address = allocated a block of 10 x sizeof(int:4 bytes)
    int *x = malloc(10 * sizeof(int));
	// A "buffer overflow", going outside of the bounds of the allocated memory
    x[10] = 0;
}

int main(void)
{
    f();
    return 0;
}
// Straight away, this needs to be fixed as so to free the 40bytes of memory being hogged
#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    x[10] = 0;
	free(x);
}

int main(void)
{
    f();
    return 0;
}
// This will still have the issue of "line 8", "invalid write of size 4"
// this is again, because it is going outside the bound sof the array
#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    x[9] = 0;
	free(x);
}

int main(void)
{
    f();
    return 0;
}


// PC's store memory methodically, storing differnet types of data in different areas
// Kinda like this
 --------------
[ machine code ]
 --------------
[   globals    ] // All the global variables
 --------------
[     heap     ]  // big chunk of memory where you can allocate memory from
[		|	   ]  // Grows downward
[		v	   ]
[			   ]
[			   ]
[		^	   ]
[		|	   ] // the storage of local variables
[     stack    ] // grows upward
 --------------
 
 
////    EXAMPLE: noswap
// Fails to swap two integers

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
 
 // when run main (stack)
 // it get's its own "frame stack
 // Functions you call from there, build on top
 
 --------------
[              ]
[			   ]
[			   ]
[			   ]
[			   ]
[			   ]
 --------------
[	  Swap	   ] // a, b, tmp
 --------------
[     Main     ] // x(1), y(2)
 --------------
 
 // Once swap has been run and closes, it's mem allocation dissapears
 --------------
[              ]
[			   ]
[			   ]
[			   ]
[			   ]
[			   ]
[	      	   ]
 --------------
[     Main     ] // x(1), y(2)
 --------------
 
 // A solution could be to pass in addresses? access the values of those address?
  --------------
[              ]
[			   ]
[			   ]
[			   ]
[			   ]
[			   ]
 --------------
[	  Swap	   ] // a,    b, tmp
 --------------] // |     |
[     Main     ] // x(1), y(2)
 --------------
 
////    corrected swap

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
	// & is "get the address"
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}
// * is "goto address"
void swap(int *a, int *b)
{
	// tmp = x's address's value
    int tmp = *a;
	// the value of a's address = the value at b's address
    *a = *b;
    *b = tmp;
}
// there's nothing to free cause didn't use malloc
// If there is a function using malloc that returns the value, you have to make sure to free() it after


// the heap / stack image...
 --------------
[     heap     ]
[		|	   ] 
[		v	   ]
[			   ]
[			   ]
[		^	   ]
[		|	   ]
[     stack    ]
 --------------
 // Eventually could collide
 // STACK OVERFLOW
 //     This has already been seen in stack overflow, wher eif you call upon a recursion indefinitely, the stack will overflow into the heap
 // 
 // HEAP OVERFLOW
 //     If you keep calling malloc, eventually the heap wil meat the stack.
 //     Will overwrite memory being used by functions
 
 // Generally known as BUFFER OVERFLOWS
 
 ////////////////////////////////////////////
 ////    get_string/int/float etc...
 ////////////////////////////////////////////
 
 ////    EXAMPLE: scanf.c
 #include <stdio.h>
 
 int main(void)
 {
	 int x;
	 printf("x: ");
	 // scanf does the prompt and human  handling
	 // You pass scanf the address for the same reason that to copy a value
	 scanf("%i", &x);
	 printf("x: %i\n", x);
 }
 
 ////
  #include <stdio.h>
 
 int main(void)
 {
	 char *s = NULL; // Use NULL if you don't know the pointer value
	 // however, there is no memory allocation to put anything here, so it doesn't work
	 printf("s: ");
	 // A char* is already a address, so pass "s" in bellow
	 scanf("%s", s);
	 printf("s: %s\n", s);
 }
 ////
   #include <stdio.h>
 
 int main(void)
 {
	 // Presuming ther human will imput "emma"
	 char s[5]; // you can treat pointers like arrays
	 printf("s: ");
	 scanf("%s", s);
	 printf("s: %s\n", s);
 }
 
////    EXAMPLE: phonebook.c 
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// This will theorectically, store the contents of a given file
	//           file open(  file name  ,  r=read  w=write  a=append)
	FILE *file = fopen("phonebook.csv", "a"); //fopen will return the pointer to this file
	
	char *name   = get_string("Name: ");
	char *number = get_string("Number: ");
	
	// file print (write)
	fprint(file, "%s,%s\n", name, number);
	
	fclose(file);
}
// CSV = "comma sepperate values" lol
// this will generate something like:
Emma, 617-555-100
Rodrigo, 617-555-101
Brian, 617-555-102

////    EXAMPLE: jpeg.c
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	
	FILE *file = fopen(argv[1], "r");
	// Check if the file exists
	if (file == NULL)
	{
		return 1;
	}
	// Reads 3 bytes from file (24bytes)
	// "for arcane reasons, need 0-255 over -128-127
	unsigned char bytes[3];
	fread(bytes, 3, 1, file);
	
	// Check if bytes are 0xff 0xd8 0xff
	if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
	{
		print("Maybe\n");
	}
	else
	{
		print("No\n");
	}
	fclose(file);
}

// this will be explored more....
// with images and what they actually are! woo!
// smiley face XD

// map of bits that represent the pixels in an image, aka bitmap
11000011
10111101
01011010
01111110
01011010
01100110
10111101
11000011
