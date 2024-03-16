## [DAY-109] Touch Typing Day

Touchtyping day!

## [DAY-110] Find Code on TikTok


![game-109.png](./screenshots/game-109.png "game 109 screenshot")

follow zippycode on tiktok https://www.tiktok.com/@zippycode
try some of their ideas, like:

```
from turtle import *
bgcolor('black')
n = 0
colormode(255)
while n < 200:
    right(n)
    forward(n*3)
    color(n,255-n,n%30*8)
    n+=1
```


```
from turtle import *
color('green')
speed(11)
i = 0
while True:
    circle(i*1.5)
    right(4)
    i+=1
```

## [DAY-111] Lists; Random
![game-110.png](./screenshots/game-110.png "game 110 screenshot")

```
import pgzrun
import random

WIDTH = 400
HEIGHT = 400
fox = Actor("c1")
fox.x = WIDTH/2
fox.y =HEIGHT/2

other = [
    Actor("c2", pos=(100,100)),
    Actor("c2", pos=(100,300)),
    Actor("c2",pos=(300,300)),
    Actor("c2",pos=(300,100))
]


def update():
    if keyboard.left:
        for o in other:
            o.x += 5
    if keyboard.right:
        for o in other:
            o.x -= 5
    if keyboard.up:
        for o in other:
            o.y += 5
    if keyboard.down:
        for o in other:
            o.y -= 5

    for o in list(other):
        if o.colliderect(fox):
            other.remove(o)
    if len(other) < 4:
        other.append(Actor("c2",pos=(random.randint(10,WIDTH-10), random.randint(10,HEIGHT-10))))

    for o in other:
        o.y -=1

def draw():
    screen.clear()
    screen.fill("deepskyblue")
    fox.draw()
    for o in other:
        o.draw()
pgzrun.go()
```

## [DAY-112] Use Simple Dictionary

Count the words in a song

```
song = """There once was a ship that put to sea
The name of the ship was the Billy of Tea
The winds blew up, her bow dipped down
O blow, my bully boys, blow (huh)
She had not been two weeks from shore
When down on her a right whale bore
The captain called all hands and swore
He'd take that whale in tow (huh)
Soon may the Wellerman come
To bring us sugar and tea and rum (hey)
One day, when the tonguin' is done
We'll take our leave and go
Take our leave and go
Soon may the Wellerman come
To bring us sugar and tea and rum
One day, when the tonguin' is done
We'll take our leave and go
Before the boat had hit the water
The whale's tail came up and caught her
All hands to the side harpooned and fought her
When she dived down below (huh)
She had not been two weeks from shore
When down on her a right whale bore
The captain called all hands and swore
He'd take that whale in tow (huh)
Soon may the Wellerman come
To bring us sugar and tea and rum (hey)
One day, when the tonguin' is done
We'll take our leave and go
Take our leave and go
Soon may the Wellerman come
To bring us sugar and tea and rum
One day, when the tonguin' is done
We'll take our leave and go
Soon may the Wellerman come
To bring us sugar and tea and rum (hey)
One day, when the tonguin' is done
We'll take our leave and go
Take our leave and go
Take our leave and go
"""

words = {}
word = ''
for c in song:
    if c == ' ' or c == '\n':
        if word not in words:
            words[word] = 1
        else:
            words[word] += 1
        word = ''
    else:
        word += c

for word in words:
    print(words[word],word)
```

This program has a bug, if the file does not end with empty line, it wont count the last word.

Print the length:

```
...
l = 0
for c in song:
    l += 1
print(l)
print(len(song))
```

## [DAY-113] Discover Pythontutor

use https://pythontutor.com/visualize.html with the folloowing code:

```
song = """Soon may the Wellerman come
To bring us sugar and tea and rum (hey)
One day, when the tonguin' is done
We'll take our leave and go
Take our leave and go
Soon may the Wellerman come
To bring us sugar and tea and rum (hey)
One day, when the tonguin' is done
"""

words = {}
word = ''
for c in song:
    if c == ' ' or c == '\n':
        if word not in words:
            words[word] = 1
        else:
            words[word] += 1
        word = ''
    else:
        word += c

for word in words:
    print(words[word],word)

```


![game-113-a.png](./screenshots/game-113-a.png "game 113-a screenshot")
![game-113-b.png](./screenshots/game-113-b.png "game 113-b screenshot")

try it with other programs as well.

## [DAY-114] Simple Turtle
![game-114.png](./screenshots/game-114.png "game 114 screenshot")

random walk

```
from turtle import *
from random import randint,choice

colors = ['red','deepskyblue','lawngreen']

screen = Screen()
width, height = screen.window_width(), screen.window_height()

pensize(5)
speed(20)

while True:
    pencolor(choice(colors))
    setheading(randint(0,360))
    forward(randint(1,100))
    (x,y) = pos()
    if x > width/2 or y > height/2 or x < -width/2 or y < -height/2:
        setpos(0,0)

```

## [DAY-115] Practical Coding, Control Roblox with python

![game-115.png](./screenshots/game-115.jpg "game 115 screenshot")

Control Roblox with python

NB: That might be considered cheating, even though its just for fun, so be ready to get your account banned.

First `pip install pyautogui` and `pip install pydirectinput`.

```
import pyautogui
import pydirectinput
import time

time.sleep(2)

while True:
    for key in ['w','a','s','d']:
        print('executing',key)
        pydirectinput.keyDown(key)
        time.sleep(1.6)
        pydirectinput.keyUp(key)
        time.sleep(0.5)
```

This is a simple program that presses w a s d, each for 1.6 seconds and then waits 0.5 seconds for the next one.

After you start the program, you have 2 seconds to click on Roblox otherwise the sequence will be wrong

