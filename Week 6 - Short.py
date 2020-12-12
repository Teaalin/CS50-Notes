#================================================================
#						   Week 6 Short		               
#						      Python
#================================================================

- python is very commonly used
- versatile for making complex operations easier

- can be run without compile
- also there's other versions of python, this is python 3, python 2 is also popular


variables are "easier"
no semicolons
strings can be "" and ''

## Conditionals

if y < 43 or z == 15:
	#code
elif y > 43 or z == 16:
	#code
else:
	#code


if coursenum == 50:
    #code
elif not coursenum == 51:
    #code

#ternary statements are like:
letters_only: True if input().isalpha() else False


## Loops
counter = 0
while counter < 100:
    print(counter)
    counter += 1

for i in range(100):
    print(x)

# To count in 2's, for whatever reason
for i in range(0, 100, 2): #start, end, skip
    print(x)


## arrays
(more appropritely called a list)
not fixed in size, easy to expandtabs

nums = [] OR nums = list()
nums = [1,2,3,4]
# also list comprehension
# this generates a list of numbers, 500 elements, with numbers stored
nums = [x for x in range (500)]
#so... if we have
nums = [1,2,3,4]
# to add a element to the list,
nums.append(5) #taks onto the end of the list
# insert an element
num.insert(4,5) #adds another element with 5 at the 4th postition
# This also does the same thing...
nums[len(nums):] = [5] # num list from pos 4 attaches another list to it


## tuples
an ordered, immutable set of data. 
Great for associating collections of data, sort of like a struct in C,
but where those values are unlikely to change.

# A list of tuples:
presidents = [
    ("George Washington", 1789), #() indicate a touple
    ("John Adams", 1797),
    ("Thomas Hefferson", 1801),
    ("James Madison", 1809)
]
# prez, year    relates to the above   "name", year
for prez, year in predidents:
    print("In {1}, {0} took office.".format(prez, year)
    # this is similar to C's print f, in that you put in values


## dictionaries
Close to a hash table. Associate indexs with keys rather than numbers.

pizzas = {
    "sheese": 9,
    "pepperrooni":10,
    "tofu": 11,
    "buffalo chyaken":12
}

# to change the values
pizzas["sheese"} = 8

if pizzas["tofu"] < 12:
    # do something
    
# to add new key pairs
pizzas["mushroom"} = 8

# how to iterate over the keys? they're not indexs like an array, but...
for pie in pizzas:
    # pie is a stand in for i, basically the same behaviour as an array, but returns key

# will print out each KEY
for pie in pizzas:
    print(pie)

# to print the value:
# pizzas.items() allows itterating over the VALUES of the dict
for pie, price in pizzas.items(): 
    print(price)

# bring it together:
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}.".format(pie, price))
#note to self, i'd like to test if print(f"bla {pie}") would work here, as I prefer it

# of course theres always concatinate method, but bleh
print("A whole " + pie + " pizza costs $" + str(price) + ".")

#deprecated in python 3 :c this is similar to how it works in godot
print("A whole %s pizza costs $%2d." % (pie, price))

## Functions
dont have to specify return values, but need input values if used

def main():
    crap()

def crap():
    # lol 
    
# don't forget to call main at the bottom so it'll actually run!!
main()

# heres the shorts examples
# define the square of x
def square(x):
    #return x * x    OR
    return x ** 2

## OBJECTS
"""
python is an object oriented lang
"an object is sort of analogous to a C struct"
C structures xontain a number of fields/properties
and ofc, these properties can never be standalone if defined in a struct

They also have methods, aka functions.
These can only be called with the object like: object.func()

in python, this is done with the class keyword
it requires an initialization function, also known as a "constructor", which sets the starting values of the properties of the object.
in defining each method of an object, self should be its first parameter, which stipulates on what object the method is called.
"""

class student():
    
    # ALWAYS __init__
    def __init__(self, name, id):
        #this sets these to whatever is passed in on creation I assume
        self.name = name
        self.id = id
    
    def changeID(self, ID):
        # an example of how to change it's properties?
        self.id p id
    
    def print(self):
    print("{} - {}".format(self.name, self.id))

# in use
jane = student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()

## Style
good style is a must lol, or you die


## actually running python scripts
# can be in py files but can also test short python snippets in the command line
# just need to install python (I haven't yet)

# to use the interpriter
python <file>

# to run it more like how we did in C...
# include a "shebang" at the top of the file: 
"  #!/usr/bin/env python3  " # (minus the "")
# this finds and runs the interpriter for you

# the permissions will need to be changed to do this using:
chmod a+x <file>

# following this, the file can be accessed with
./<file>
