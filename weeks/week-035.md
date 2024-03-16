## [DAY-241] lists

![game-241.jpg](./screenshots/game-241.jpg "game 241 screenshot")


Make a line edittor that can add lines to a list, save this list to a file file and open a file and read the lines into the list.

It looks like this:

```
C:\Users\jackie\Desktop>python3 editor.py
> example file
========================================
0: example file
========================================
> with many lines
========================================
0: example file
1: with many lines
========================================
> save a.txt
a.txt saved!
>
^C (Ctrl + C)


C:\Users\jackie\Desktop>python3 editor.py
> open a.txt
========================================
0: example file
1: with many lines
========================================
>
```

Here are all the components you need:


```
* read the user input and add it into a list:
  lines = []
  while True:
      a = input("> ")
      lines.append(a)

* print list of lines with their line number, and
some header and footer of =====..x40:
  print("=" * 40)
  for i in range(len(lines)):
      print(str(i) + " " + lines[i])
  print("=" * 40)

* join list of lines into a string:
  lines = ["a","b","c"]
  s = "\n".join(lines)

  will make the string:
  a
  b
  c


* read the lines of a file:
  lines = []
  name = "hello.txt"
  with open(name, "r") as f:
      lines = f.read().splitlines()

* write list of lines to a file:
  name = "hello.txt"
  with open(name, "w") as f:
      f.write("\n".join(lines))


* check if string starts with the word "save"
  s = "save hello.txt"
  if s.startswith("save "):
      print("yes it does")

* split a string into two parts:
  s = "save hello.txt"
  a,b = s.split(" ")

  a is "save"
  b is "hello.txt"
```


Line editors seems silly, but they were the super useful in the 60s and 70s, in fact a lot of the operating systems and laguages back then were written in a line editor called `ed`, there are three fundamental components to make a computer usefful, `assembler` - a program that translate instructions into machine code, `editor` - a program that allows you to write files and a `shell` a program that allows you to start other programs and interact with them.

The C language was written in `ed`, the UNIX operating system was written by `ed` as well.


## [DAY-242] lists

Add the functionality to delete a line. This is how it should look:

```
python3 editor2.py
...
> haha amazing
========================================
000: hello
001: this
002: is
003: one
004: line
005: per
006: word
007: haha amazing
========================================
> d 2
========================================
000: hello
001: this
002: one
003: line
004: per
005: word
006: haha amazing
========================================
> d 4
========================================
000: hello
001: this
002: one
003: line
004: word
005: haha amazing
========================================
>
```

You will need the following:

```
* how to check if string starts with "d "
    if line.startswith("d "):
       print("yey")


* how to split a string
    line = "d 25"
    a,b = line.split(" ")
    # a is "d"
    # b is "25"

* how to convert string to a number:
    x = ["hello","this","is"]
    a = "5"
    n = int(a)

    # access the element at index n from the list x
    print(x[n])

* how to delete a item from a list
    x = ["hello","this","is"]

    # delete the element on index 1
    del x[1]

    # or you can use pop(1) to
    # remove and return the value at index 1
    a = x.pop(1)

    # or just use x.pop(1) if you dont care about
    # the element it is returning
    x.pop(1)


* if you try to access a list beyond its size it will
  crash, so you need to check if a number fits to be
  used as an index

    n = 5
    if n < len(lines):
       print("yey")
```


## [DAY-243] lists

Add goto line functionality.

```
* how to check if string starts with "goto "
    if line.startswith("goto "):
       print("yey")


* how to split a string
  .split(separator) is a method you call on the string
  it returns a list splitted by the separator
    line = "d 25"
    x = line.split(" ")
    x is a list ["d","25"]

  you can also use destructuring to directly assign
  the list into separate variables
    a,b = line.split(" ")
  a is "d"
  b is "25"


* how to convert string to a number:
    x = ["hello","this","is"]
    a = "5"
    n = int(a)

  access the element at index n from the list x
    print(x[n])

* insert into a list in a specific position

    a = ["hello","world"]
    x = 1
    a.insert(x, "beautiful")
    print(a)
  prints ['hello', 'beautiful', 'world']

  if you try to insert beyond the list size, it will
  just add it to the end

    x = 20
    a.insert(x, "zzz")
    print(a)
  prints ['hello', 'beautiful', 'world', 'zzz']


* string formatting
  python has 'f' strings, which are formatted strings

    i = 2
    print(f"hello {i:05}")
  prints 00002, so it will make sure it will occupy
  5 spaces, filling with 0, this is handy if you want
  to print things with the same width.

  e.g. lets say you have this lines:
  0: hello
  1: world
  ...
  9: good
  10: morning


  see how 'morning' is one space to the right, because 10
  has one more symbol than 9, so with print(f"{i:02}")
  it will look like this:

  00: hello
  01: world
  ...
  09: good
  10: morning



* example code:

    x = []
    # start at -1, because we always insert on the "next line"
    # and in the beginning the next line is going to be 0
    # so we need to start at -1
    position = -1
    while True:
        a = input("> ")
        if a == "goto 5":
            position = 5
        else:
            # insert at the next line
            position += 1
            x.insert(position, a)
            for line in x:
                print(line)



* example how to show which line we have the position on
  use f strings in your solution

    def printWithLineNumbers(a, position):
        print("=" * 40)
        for i in range(len(a)):
            if i == position:
                print("*" + str(i) + ": " + a[i])
            else:
                print(" " + str(i) + ": " + a[i])
        print("=" * 40)



```

How it should work:

```
python3 editor2.py
> hello
========================================
*000: hello
========================================
> this is a new
========================================
 000: hello
*001: this is a new
========================================
> file
========================================
 000: hello
 001: this is a new
*002: file
========================================
> with
========================================
 000: hello
 001: this is a new
 002: file
*003: with
========================================
> a lot
========================================
 000: hello
 001: this is a new
 002: file
 003: with
*004: a lot
========================================
> of information
========================================
 000: hello
 001: this is a new
 002: file
 003: with
 004: a lot
*005: of information
========================================
> goto 2
========================================
 000: hello
 001: this is a new
*002: file
 003: with
 004: a lot
 005: of information
========================================
> that i am writing in my new editor
========================================
 000: hello
 001: this is a new
 002: file
*003: that i am writing in my new editor
 004: with
 005: a lot
 006: of information
========================================
> d 4
========================================
 000: hello
 001: this is a new
 002: file
*003: that i am writing in my new editor
 004: a lot
 005: of information
========================================
> which is amazing and it can edit
========================================
 000: hello
 001: this is a new
 002: file
 003: that i am writing in my new editor
*004: which is amazing and it can edit
 005: a lot
 006: of information
========================================
> goto 6
========================================
 000: hello
 001: this is a new
 002: file
 003: that i am writing in my new editor
 004: which is amazing and it can edit
 005: a lot
*006: of information
========================================
> now i will append in the end of the file
========================================
 000: hello
 001: this is a new
 002: file
 003: that i am writing in my new editor
 004: which is amazing and it can edit
 005: a lot
 006: of information
*007: now i will append in the end of the file
========================================
>

```

## [DAY-242] lists

![game-242.jpg](./screenshots/game-242.jpg "game 242 screenshot")

> She was super tired after shool and training, so I had to help out a lot.

Make goto support `goto 7` to go to specific line index, and `goto hello` to go to the first line that contains the word `hello`


```
* check if a string is an integer:

  z = "helloo"
  if z.isdigit():
      print("Z IS A DIGIT")
  else:
      print("Z IS NOT A DIGIT")


* find the first line containing a string

  def find(where, what):
      for i in range(len(where)):
          if what in where[i]:
              return i
      return -1


  x = ['hello world', 'b' ,'hello']
  found = find(x, "b")
  if found >= 0:
     print(f"index {found} matching with value {x[found]}")
```


How it should look:

```
> hello
========================================
*000: hello
========================================
> world
========================================
 000: hello
*001: world
========================================
> this is hello
========================================
 000: hello
 001: world
*002: this is hello
========================================
> how can it be
========================================
 000: hello
 001: world
 002: this is hello
*003: how can it be
========================================
> blabla
========================================
 000: hello
 001: world
 002: this is hello
 003: how can it be
*004: blabla
========================================
> goto world
========================================
 000: hello
*001: world
 002: this is hello
 003: how can it be
 004: blabla
========================================
> goto 3
========================================
 000: hello
 001: world
 002: this is hello
*003: how can it be
 004: blabla
========================================
> z
========================================
 000: hello
 001: world
 002: this is hello
 003: how can it be
*004: z
 005: blabla
========================================
> goto world
========================================
 000: hello
*001: world
 002: this is hello
 003: how can it be
 004: z
 005: blabla
========================================
> m
========================================
 000: hello
 001: world
*002: m
 003: this is hello
 004: how can it be
 005: z
 006: blabla
========================================
>
```


Lookup the documentation for .split(" "), to see how to make "goto hello world" be split into ["goto", "hello world"] instead of ["goto","hello","world"] (hint, .split() takes two parameters, separator which in our case is " ", and maxsplit, which by default is -1, but you can limit how many times you want to split)


## [DAY-243] lists; strings

![game-243.jpg](./screenshots/game-243.jpg "game 243 screenshot")

> today was a 'write this code and lets go over it' kind of lesson

When adding a line, use the number of starting spaces from previous line this is super handy if you are writing python, or a presentation.

This is how it should look:

```

> hello
========================================
*000: hello
========================================
>    testing
========================================
 000: hello
*001:    testing
========================================
> another line
========================================
 000: hello
 001:    testing
*002:    another line
========================================
>
========================================
 000: hello
 001:    testing
 002:    another line
*003:
========================================
> and again
========================================
 000: hello
 001:    testing
 002:    another line
 003:
*004: and again
========================================
> goto 2
========================================
 000: hello
 001:    testing
*002:    another line
 003:
 004: and again
========================================
> zzz
========================================
 000: hello
 001:    testing
 002:    another line
*003:    zzz
 004:
 005: and again
========================================
>

```

use the following function which just iterates the characters of a string and counts spaces and breaks out if it sees the first non space

```
    def countSpaces(string):
        n = 0
        for character in string:
            if character == ' ':
                n += 1
            else:
                break
        return n

```

you need to use this function to modify the 'line' if we have a previous line and the current line has at least 1 character:

```

while True:
     line = input('> ')

     ...
     else:
         if pos >= 0 and pos < len(lines) and len(line) > 0:
              prev = lines[pos]
              prefix = (' ' * countSpaces(prev)) # n spaces
              line = prefix + line
```

## [DAY-244] files; strings

Create 1000 files 1.txt 2.txt etc.. each file should contain "hello\n" 500 times

```
MAKE BIG STRING:

  # make a string containing "hello\n" 500 times:
  a = "hello\n" * 500


WRITE TO A FILE:

  # with open and close
  name = "1.txt"
  f = open(name, "w")
  s = "hello\n"
  f.write(s)
  f.close()


  # or using `with` so it automatically closes the file:
  name = "1.txt"
  s = "hello\n"
  with open(name, "w") as f:
      f.write(s)
```

## [DAY-245] lists

We made a small test:

```
# insert 100000 random integers between 1 and 1000 in a list
# find the smallest number
# find the largest number

def find_smallest(x):
    n = 0

    # ...
    # code that finds the smallest

    return n



def find_largest(x):
    n = 0

    # ...
    # code that finds the largest

    return n


import random
numbers = []

for i in range(100000):
    # append random numbers between 1 and 1000 to the list


smallest = find_smallest(numbers)
largest = find_largest(numbers)

print(f"smallest: {smallest}, largest: {largest}")
```


After the test is done, google for 'how to find smallest/largest numbers from a ist in python' and see how the `min` and `max` functions work.


