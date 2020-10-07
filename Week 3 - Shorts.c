
//================================================================
//			 Week 4 Shorts		               
//================================================================
//
//    line   CONTENTS
//================================================================
//    020  - Linear Search
//    038  - Binary Search
//    077  - Bubble Sort
//    110  - Selection Sort
//    138  - Insertion Sort
//    164  - Recursion
//    268  - Merge Sort
//    344  - Summary
//================================================================



//    020   Linear Search
//----------------------------------------------------------------
//	itterate from left to right, searching for the element

//	pseudocode:
	Repeat, starting at the first element
		if the first element is what you are looking for, stop
	otherwise, move to the next element
	
	11  23  8  14  30  9  6  17  22  28  25  15  7  10  19
	// Searching for 9, it will find it
	// Searching for 50, it wont, it will go through the whole array with no results
	
	Worst case: O(n)
	Best case:  Ω(1)



//    038   Binary Search
//----------------------------------------------------------------
//	devide and conquer! muhahaha, devide the search area by half
//	The array must be sorted first

//	pseudocode:
	repeat until (sub)array is of size 0:
		calculate the middle point of the current (sub)array
		if the target is at the middle, stop
		otherwise, if the target is less than what's in the middle, repeat, changing the end point to just be the left of the middle
		otherwise, if the target is greater, repeat, changer the start point to the element right of the middle
	
//	With this array...
//	Target:	Start:	End:	Middle:
	11  23  8  14  30  9  6  17  22  28  25  15  7  10  19
//	Can't do unsorted...

//	Target: 19    Start: 0        End: 14    Middle: [14/2 = 7]
	6  7  8  9  10  11  14  [15]  17  19  22  23  25  28  30
//	19 is greater than 15... so	

//	Target: 19    Start: 7+1 8    End: 14    Middle: [ = 11]	
	6  7  8  9  10  11  14  15  [17  19  22  [23]  25  28  30]
	// That's not the value, it's lower

//	Target: 19    Start: 8        End: 10    Middle: [= 9]	
	6  7  8  9  10  11  14  15  [17  19  22]  23  25  28  30
//	Is it in the middle?
//	YEP

// This process would still run through if the value is no in there,
// this will run until start == end
// end point goes less than startpoint, this will mean that the (sub)array becomes is 0, so the repeat will exit.
	
	Worst case: O(log n)
	Best case:  Ω(1)



//    077   Bubble Sort
//----------------------------------------------------------------
//	Generally want to move higher values to the right, lower to the left

//	pseudocode:
	set swap couter to non-zero value
	repeat until the swap counter is 0:
		reset swap counter to 0
		look at each adjacent pair
			if two adjacent elements are not in order, swap the and add one to the swap counter
	
//	swap counter = 0
	5  2  1  3  6  4
//  5 & 2 are out of order sc=1
	2  5  1  3  6  4
//	5 & 1 are out of order sc=2
	2  1  5  3  6  4
// ETC, at the end of the inner loop: sc=4
	2  1  3  5  4  6
// 6 is the largest value, so it can now be ignored
// so the loop is now n-1

//	swap counter = 0
	1  2  3  5  4  6
//	...
	1  2  3  4  5  6
// Swap counter will = 0 on next iteration and exit

	Worst case: O(n²) //is in reverse order....
	Best case:  Ω(n) //Only has 1 out of place, but it has to check all



//    110   Selection Sort
//----------------------------------------------------------------
// Is shit, don't use it lol
// Find the smallest element, ad it to the start of the list

//	pseudocode:
	repeat until no unsorted elements remain (n = 0)
		search the undorted part of the data (0 to n-1) and find the smallest value
		swap the smallest found value with the first element of the unsorted part
	-> -> o -> -> ->
	[5  2  1  3  6  4]
	
//	1 to n-1
	1 [2  5  3  6  4]
//	Continue...
//	2 to n-1
	1 2 [5  3  6  4]
	
	1 2 3  [5  6  4]
	1 2 3 4 [5  6]
	1 2 3 4 5 [6]
//	n = 0

	Worst case: O(n²)
	Best case:  Ω(n²)



//    138   Insertion Sort
//----------------------------------------------------------------
//	Build a "sorted array" in place, shifting elements out of the way if necessary to make room as you go

//	pseudocode:
	call the first element of the array "sorted"
	repeat until all elements are sorted:
		Look at the next unsorted element. Insert into the "sorted" portion by shifiting the requisite number of elements
	v sorted
	5  [2  1  3  6  4]
//	look at 2, to be sorted, it needs to go before five, so shift 5 over,
	2 5 [1  3  6  4]
//	1 is smallest, shift over 2 & 5
	1 2 5 [3  6  4]
//  3... five needs to move over
	1 2 3 5 [6  4]
//	6 is larger than everything, it's sorted
	1 2 3 5 6 [4]
//	4 needs to shift over 5&6
	1 2 3 4 5 6

	Worst case: O(n²)
	Best case:  Ω(n)



//    164   Recursion
//----------------------------------------------------------------
//	A recursive function calls itself
//	Very elegant wow

//	Factorial... (n!)
	fact(1) = 1
	fact(2) = 2 * 1
	fact(3) = 3 * 2 * 1
	fact(4) = 4 * 3 * 2 * 1
	fact(5) = 5 * 4 * 3 * 2 * 1
	...

//	Can be made in recursion by thinking like
	fact(1) = 1
	fact(2) = 2 * fact(1)
	fact(3) = 3 * fact(2)
	fact(4) = 4 * fact(3)
	fact(5) = 5 * fact(4)
	...
	fact(n) = n * fact(n-1)
	
//	Every recursive function has two cases that could apply, given any input.
//		The "base case", which when triggered, will terminate the recursive process.
//		The "recursive case", which is where the recursion will actually occur.

	fact(1) = 1 // this is the base case
//	Don't want to go lower than this so base case = 1
int fact(int n)
{
	// Base case
	if (n == 1)
	{
		return 1;
	}
	else
	{
		// Recursive case
		return n * fact(n - 1);
	}
}
// If we have single line cases like this, it can be reduced to...
int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
//	This will go through, until it reaches 1, returns one, 2 returns 2*1, 3 returns 3*2*1...

//	This can at times, replace loops
int fact2(int n)
{
	int product = 1;
	while (n > 0)
	{
		product *= n;
		n--;
	}
	return product;
}
//	It is possible to have more than one base or recursive case, 
//	if the program might recurse or terminate in different ways, depending on the input being passed in

//	Multiple base cases: The Pibonacci number sequence is defined as follows:
//		the first element is 0
//		the second element is 1
//		the nth element is the sum of the (n-1)th and (n-2)th elements

//	Multiple recursive cases: 
//	The Collatz conjecture...

//	The collatz conjecture applies to pos integers and speculates that it is always possible to get "back to 1"
//	If you follow these steps:
//		if n is 1, stop.
//		otherwise, if n is even, repeat this process on n/2.
//		otherwise, if n is odd, repeat this process on 3n + 1

#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    printf("%i\n", collatz(get_int("int: ")));
}

int collatz(int n)
{
	// Base case
	if (n == 1)
		return 0;		// I had this as 1...
	// recursive even number steps
	else if ((n % 2) == 0)
		return 1 + collatz(n/2);	// Was doing n + ...
	// recursive odd number steps
	else
		return 1 + collatz(3 * n + 1);
}



//    268   Merge Sort
//----------------------------------------------------------------
//	Sorts smaller arrays and combines them in sorted order
//	Uses recursion, has better performance than others, BUT COMPLICATED

//	pseudocode:
	sort the left half of the array (assumeing n > 1)
	sort the right half of the array (assuming n > 1)
	merge the two halves together

//	Given...
	[5  2  1  3  6  4]
//  Sort left
	[5  2  1]// 3  6  4]
//  How do sort? id, do left side
	[5]// 2  1  3  6  4]
//	There's no other numbers (n = 1), so this is sorted... So sort right
	   [2  1]// 3  6  4]
	5
//	how sort? sort left...
	   [2]// 1  3  6  4]
	5
//	2 is sorted... 1 is sorted... So now we must merge these two
	           3  6  4]
	   [2  1] <-----------------
	5
//	Merge these two, who is the lower? 1 is, so it moves to  the first pos of a "hypothetical" array
	           3  6  4]
	    2	<-----------------
		1
	5|
//	Which is lower? 2, it's the only one there! Move it to the "next lowest position"
	           3  6  4]
	5|	1   2 <----------------- sorted!
	
//	Now we must merge again, which one is smaller
//	compare each of each array to find the smaller value, move to the next smallest part of new array
	           3  6  4]
	5|	   2
	1
//	Comapare 5 to 2, 2 is smaller
	           3  6  4]
	5|	   
	1	2
//	 is the last one, merge
	           3  6  4]   
	1	2   5 <--- tada... sorted!

//  repeat this insanity until sorted...
//	RIGHT HALF
	          [3  6  4] 
			   v
			   3|
//
	             [6]//  4 
			   3| v
//
	                  4 
				  6   v
			   3| 
//	Merge 4 & 6...
			   3| 4   6
//	ya whatever
//	ya get it, repeat till final merge
	1	2   5 | 3  4   6
//	compare each to each, 
	1 to 3 ... 2 or 3 ... 5 or 3 ... 5 or 4 ... 5 or 6 ... 6 or nothing...
//	Finally
	1  2  3  4  5  6
//	Worst case: we have to split n elements up and recombine them, effectively doubling the sorted subarrays as we build the.
//	Best case:  The array is already perfectly sorted but we still have to split up and recombine it back together
	Worst case: O(n log n)
	Best case:  Ω(n log n) // I feel like you could inmprove this simply by checking if the array is sorted first...?



//    344   Summary
//----------------------------------------------------------------
//	There are many other searching and sorting algorithms...
//	So much to keept track of, lets break down into core elements

Algorithm			concept					O		Ω
-------------------------------------------------------
Selection sort		smallest value			n²	 	n²
//Find the smallest value in the array, swap it with the first unsorted value.

Bubble sort			swap pairs				n²		n
//Swap adjacent pairs if they are not in order, bubbling larger values to the right, small to left

Insertion sort		shifting				n²		n
//Proceed once through the array from left-to-right, shifting elements as necessary to insert each element into its correct place

Merge sort			split & merge		n log n	   n log n
//Split the full array into sub arrays, then merge those sub arrays back together in the correct order

Linear search		iterate					n		1
//Iterate accross the array from left-to-right, trying to find the target value

Binary search		divide & conquer		log n	1
//	Given a sorted array, devide and conquer by eliminating half of the remaining elements in the search for the target value
