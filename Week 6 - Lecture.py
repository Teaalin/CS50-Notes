#================================================================
#						   Week 6 Lecture		               
#						      Python
#================================================================

print("Hello, world.")

answer = get_string("What's your name?\n")
print("hello, ", answer) #concatonation operator

# or print(f"hello, {answer}") can also use ''

counter = 0
counter += 1

x = 3
y = 0
if x < y:
    print("x is less than y")
else:
    print("x is not less than why")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x and y are equal")

while True:
    print("wassssup!")
# CAFFING
i = 3
while i > 0:
    print("cough")
    i -= 1

#for loops...
for i in [0, 1, 2]:
    print("cough")

# or
for i in range(3):
    print("cough")

# NO: char, double, long, pointers
# string = str

# yes:
# range:    sequence of numbers
# list:     sequence of mutable values (values that canbe changed), like an array that can change size
# tuble:    sequence of immutable values
# dict:     collection of key/value pairs (built like a hash table)
# set:      collection of unique values, tosses dupes

#docs.python.org




#------Blur example
from PIL import Image, ImageFilter

before = Image.open("yard.bmp")
after = before.filter(ImageFilter.BLUR)
after.save("out.bmp")

#------Ditionary.py example
words = set()

def check(word):
    # words.lower() goes into words and calls lower on the string there
    if words.lower() in words:
        return True
    else:
        return False
   
def load(ditonary):
    file = open(dictionary, "r")
    for line in file:
        words.add(line.rstrip("\n")
       file.close()
    return true

def size():
    return len(words)

def unload():
    # its done for you
    return True
# The tradeoff is ofc time to make vs time to run / resources required to run/ use


######### string.py
from cs50 import get_string

s = get_string("What's your name?\n")
print("hello,", s) #or print(f"Hello, {s}")

######### int.py example
from cs50 import get_int
age = get_int("What's your age?\n")
print(f"You are at least {age * 365} days old.")

######### conditions.py
from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x and y are equal")

######### agree.py
from cs50 import get_string

s = get_string("Do you agree? y/n\n)

if s == "Y" or s == "y"
    print("Agreed")
elif s == "N" or s == "n":
    print("Not agreed")

# OR

if s in ["Y", "y", "yes", "Yes"]
    print("Agreed")
elif s in ["N", "n", "No", "no"]:
    print("Not agreed")

# OR

if s.lower() in ["y", "yes", "yep", "ye"]
    print("Agreed")
elif s.lower() in ["n", "no", "nope", "nah"]:
    print("Not agreed")
    
strings in python are structs, which means they not only contain the characters themselves,
but also functions and other stuff

######### Cough
# THERE'S NO PROTOTYPES?! REEEEE BUT IT HAS THE SAME PROBLEM AS C WHEN SOMETING AINT SEEN
# SO HERE'S THE SOLUTION

# Define a main, python will be like "cool, that exists" and move on...
def main():
    for i in range(3):
        cough()

# define cough, move on...
def cough():
    print("cough")

# CALL MAIN TO START THE PROG...
main()


######### Cough n times
def main():
    cough(3)

def cough(n):
    for i in range(n):
        print("cough")
main()

# For the python nerds... This is the "pythonic" way to do it. it's a meme...
this can actually be accomplished simply by...
print("cough\n" * n)

######### positive.py
from cs50 import get_int

def main()"
    i = get_positive_int()
    print(i)
    
def get_positive_int():
    while True:
        n = get_int("Positive integer: ")
        
        if n > 0:
            break
    return n

main()

# this is "buggy" in c cause the n would be lost once while is broken
# variables are isolated to function but span outside their declaration

######### mario.py ????
for i in range(4):
    print("?", end="")
print()

# OR

print("?" * 4)

######### mario.py  #
#                   #
#                   #
print("#\n" * 3, end="")

######### mario.py  ###
#                   ###
#                   ###
for i in range(3)
    for j in range(3)
        print("#", end="")
    print()


##################################################
How to get rid of get_string

s = input("What's your name?\n")
print(f"Hello, {s}")

How to get rid of get_int
age = int(input("What's your age?\n"))
print(f"You are at least {age * 365} days old.")

######### overflow.py
from time import sleep

i = 1
while True:
    print(i)
    sleep(1)
    i *= 2
# This will just go forever and nothing can stop it... except exceedng the RAM lol...
# there are no limits to an int in python
 
######### scores.py
scores = []
scores.append(72)
scores.append(73)
scores.append(33)

print(f"Average: {sum(scores) / len(scores)}")

# OR

scores = [72, 73, 33]
print(f"Average: {sum(scores) / len(scores)}")


######### string2.py
from cs50 import get_string

s = get_string("Input: ")
print("Output: ", end="")
for i in range(len(s)):
    print(s[i], end="")
print()

# OR

from cs50 import get_string

s = get_string("Input: ")
print("Output: ", end="")
for c in s:
    print(c, end="")
print()


#----------- uppercase.py -----------
from cs50 import get_string

s = get_string("Input: ")
print("Output: ", end="")
print(s.upper)

to run command line arguments

#----------- argv.py -----------
# it gets weird
from sys import argv

for i in range(len(argv)):
    print(argv[i])
    
    run with
    python argv.py foo bar baz
    will print each arg
    
# or
from sys import argv
for arg in argv):
    print(arg)


#----------- exit.py -----------
from sys import argv, exit

if len(argv) != 2:
    print("Missing command line argument")
    exit(1)
else:
    print(f"hello, {argv[1]}")


#----------- names.py -----------
from sys import exit

names = ["EMMA", "RODRIGO", "BRIAN", "DAVID"]

if "EMMA" in nanes:
    print("Found")
    exit(0)
print("Not found")
exit(1)

#----------- phonebook.py -----------
from sys import exit

people = {
    "EMMA": "617-555-0100",
    "RODRIGO": "617-555-0101",
    "BRIAN": "617-555-0102",
    "DAVID": "617-555-0103"
}

if "EMMA" in people:
    print(f"Found {people['DAVID']}")
    exit(0)
print("Not found")
exit(1)

#----------- compare.py -----------
from cs50 import get_string

s = get_string("s: ")
t = get_string("t: ")

if s == t:
    print("Same")
else:
    print("Different")

#----------- swap.py -----------
x = 1
y = 2

print(f"(x is {x}, y is {y}"
x, y = y, x
print(f"(x is {x}, y is {y}"


#----------- phonebook2.py -----------
from csv
from cs50 import get_string

file = open("phonebook.csv", "a")

name = get_string("Name: ")
number = get_string("Number: ")

writer = csv.writer(file)
writer.writerow((name, number))

file.close()


# or

from csv
from cs50 import get_string

name = get_string("Name: ")
number = get_string("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow((name, number))
    
 
 
 
 ##----------- Regular expressions -----------
 .      any characters
 .*     0 or more characters
 .+     1 or more characters
 ?      optional
 
 ^      start of input
 $      end of input
 
 
#----------- agree.py again -----------
import re
from cs50 import get_string

s = get_string("Do you agree? y/n\n)

if re.search("y(es)?", s, re.IGNORECASE): #Look for a y, maybe a es
    print("Agreed")
elif re.search("n(o)?", s, re.IGNORECASE):
    print("Not agreed")
    
    
"^y(es)?$" # very ugly but makes it stricter and bound to the one word


 ##----------- voice -----------
 
 words = input("say something!\n").lower()
 
 if "hello" in words:
    print("Hello to you too!")
elif "how are you" in words:
    print("Ia am well, thanks!")
elif "goodbye" in words:
    print("Goodbye to you too")
else:
    print("huh?")
    
 
 ##----------- actual voice -----------
 import speach_recognition
 
 recognizer = speech_recognition.Recognizer()
 with speech_recognition.Microphone() as source:
    print("Say something!")
    audio = recognizer.listen(source)
 
print("Google Speech Recognition thinks you said: ")
print(recognizer.recognize_google(audio))

# He drops a few examples that are extentions of this
# Also facial recogniton lol...

##----------- qr code -----------

import qrcode
image = qrcode.make("https://youtu.be/oHg5SJYRHA0")
image.save("qr.png", "PNG")
