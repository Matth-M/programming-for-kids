## [DAY-82] Lists; Strings

![game-82.png](./screenshots/game-82.png "game 82 screenshot")

simple game with history, press S to save your position to a list of positions, and then B to go back in time

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

player = Actor("c1")
player.x = WIDTH/2
player.y = HEIGHT/2

history = []

def on_key_down(key):
    speed = 3
    
    if key == keys.UP:
        player.y -= speed
    if key == keys.DOWN:
        player.y += speed
    if key == keys.LEFT:
        player.x -= speed
    if key == keys.RIGHT:
        player.x += speed

    if key == keys.S:
        position = [player.x, player.y]
        history.append(position)

        print('append', history)

    if key == keys.B and len(history) > 0:        
        last = history.pop()
        player.x = last[0]
        player.y = last[1]

        print('pop', history)


def draw():
    screen.fill('black')
    player.draw()

pgzrun.go()
```

Two players, and more positions

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200
player1 = Actor("c1")
player2 = Actor('c2')
history = []

def on_key_down(key):
    speed = 10
    if key == keys.W:
        player1.y-= speed
    if key == keys.A:
        player1.x-=speed
    if key == keys.S:
        player1.y += speed
    if key == keys.D:
        player1.x += speed


    if key == keys.UP:
        player2.y-= speed
    if key == keys.LEFT:
        player2.x-=speed
    if key == keys.DOWN:
        player2.y += speed
    if key == keys.RIGHT:
        player2.x += speed

        
    if key == keys.F:
        positions = [player1.x,player1.y,player2.x,player2.y]
        history.append(positions)
        print('push', history)
    if key == keys.G:
        if len(history) > 0:
            positions = history.pop()
            player1.x = positions[0]
            player1.y = positions[1]
            player2.x = positions[2]
            player2.y = positions[3]
            print('pop', history)
        
def draw():
    screen.fill('black')
    player1.draw()
    player2.draw()
pgzrun.go()
```

More lists

```
a = ['h','w','e']
b = ['e','o','a']
c = ['l','r','r']
d = ['l','l','t']
e = ['o','d','h']

sum1 = ''
sum2 = ''

sum1 = a[0] + b[0] + c[0] + d[0] + e[0]
sum2 = a[1] + b[1] + c[1] + d[1] + e[1]

print(sum1)
print(sum2)

sum = []
for i in range(len(a)):
    sum.append('')
    sum[i] = a[i] + b[i] + c[i] + d[i] + e[i]


print(sum)
```

sum from the input

```
list = []
while True:
    integer = int(input('enter a number: '))
    list.append(integer)
    sum = 0
    for i in list:
        sum += i
        
    print(list, sum)
```

## [DAY-83] Lists; Functions

![game-83.png](./screenshots/game-83.png "game 83 screenshot")


```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

player = Actor("c1")
player.x = WIDTH/2
player.y = HEIGHT/2

things = []

def on_key_down(key):
    speed = 10

    if key == keys.UP:
        player.y -= speed
    if key == keys.DOWN:
        player.y += speed
    if key == keys.LEFT:
        player.x -= speed
    if key == keys.RIGHT:
        player.x += speed

    if key == keys.F:
        thing = Actor("flower")
        thing.x = player.x
        thing.y = player.y

        things.append(thing)

    if key == keys.R:
        thing = Actor("rock")
        thing.x = player.x
        thing.y = player.y

        things.append(thing)


def draw():
    screen.fill('black')
    player.draw()
    for t in things:
        t.draw()

pgzrun.go()
```

With a function, so we can add more keys faster and we dont duplicate that much code

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

player = Actor("c1")
player.x = WIDTH/2
player.y = HEIGHT/2

things = []
def place_thing(kind):
    thing = Actor(kind)
    thing.x = player.x
    thing.y = player.y

    things.append(thing)

def on_key_down(key):
    speed = 15
    
    if key == keys.UP:
        player.y -= speed
    if key == keys.DOWN:
        player.y += speed
    if key == keys.LEFT:
        player.x -= speed
    if key == keys.RIGHT:
        player.x += speed

    if key == keys.F:
        place_thing("flower")

    if key == keys.R:
        place_thing("rock")

    if key == keys.K:
        place_thing("c2")

def draw():
    screen.fill('black')
    player.draw()
    for t in things:
        t.draw()

pgzrun.go()
```

Now we can make a map, just add the kind of thing, its x and y position in a list and print it, after we are done building the map we can use it later

```
...
game_map = []
def place_thing(kind):
    thing = Actor(kind)
    thing.x = player.x
    thing.y = player.y

    things.append(thing)
    game_map.append([kind, thing.x, thing.y])
    print(game_map)
...    
```

use the map:

![game-83-a.png](./screenshots/game-83-a.png "game 83-a screenshot")

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

player = Actor("c1")
player.x = WIDTH/2
player.y = HEIGHT/2

things = []
def place_thing(kind,x,y):
    thing = Actor(kind)
    thing.x = x
    thing.y = y
    things.append(thing)

def on_key_down(key):
    speed = 15
    
    if key == keys.UP:
        player.y -= speed
    if key == keys.DOWN:
        player.y += speed
    if key == keys.LEFT:
        player.x -= speed
    if key == keys.RIGHT:
        player.x += speed
def draw():
    screen.fill('black')
    player.draw()
    for t in things:
        t.draw()

game_map = [['rock', 100.0, 55.0], ['flower', 100.0, 85.0], ['c2', 100.0, 130.0], ['c2', 70.0, 130.0], ['c2', 55.0, 130.0], ['c2', 40.0, 130.0], ['c2', 25.0, 130.0], ['c2', 25.0, 100.0], ['c2', 25.0, 85.0], ['c2', 25.0, 70.0], ['c2', 25.0, 55.0], ['c2', 25.0, 40.0], ['c2', 25.0, 25.0], ['c2', 40.0, 25.0], ['c2', 55.0, 25.0], ['c2', 70.0, 25.0], ['c2', 85.0, 25.0], ['c2', 100.0, 25.0], ['c2', 115.0, 25.0], ['c2', 130.0, 25.0], ['c2', 145.0, 25.0], ['c2', 145.0, 40.0], ['c2', 145.0, 55.0], ['c2', 145.0, 70.0], ['c2', 145.0, 85.0], ['c2', 145.0, 100.0], ['c2', 145.0, 115.0], ['c2', 145.0, 130.0], ['c2', 130.0, 130.0], ['c2', 115.0, 130.0], ['c2', 100.0, 130.0], ['c2', 85.0, 130.0], ['c2', 25.0, 115.0]]
for g in game_map:
    place_thing(g[0],g[1],g[2])

pgzrun.go()
```


![game-83-b.png](./screenshots/game-83-b.png "game 83-a screenshot")
![game-83-c.png](./screenshots/game-83-c.png "game 83-c screenshot")

Another way to do it, press S to print the list of things, and then paste it in the game[] list to use it, D deletes things where you stand, and U removes the last thing

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

player = Actor("c1")

things = []

game = []
for g in game:
    t = Actor(g[0])
    t.x = g[1]
    t.y = g[2]
    things.append(t)

def on_key_down(key):
    speed = 10

    if key == keys.UP:
        player.y -= speed
    if key == keys.DOWN:
        player.y += speed
    if key == keys.LEFT:
        player.x -= speed
    if key == keys.RIGHT:
        player.x += speed
        
    if key == keys.F:
        f = Actor("flower")
        f.x = player.x
        f.y = player.y
        things.append(f)
    if key == keys.R:
        f = Actor("rock")
        f.x = player.x
        f.y = player.y
        things.append(f)

    if key == keys.U:
         things.pop()

    if key == keys.D:
        collide = []
        for t in things:
            if player.colliderect(t):
                collide.append(t)

        for t in collide:
            things.remove(t)
    
    if key == keys.S:
        positions = []
        for t in things:
            positions.append([t.image,t.x,t.y])
        print(positions)

def draw():
    screen.fill('black')
    player.draw()
    for t in things:
        t.draw()

pgzrun.go()
```

## [DAY-84] Lists

![game-84.png](./screenshots/game-84.png "game 84 screenshot")

Lets visualize the list, try to delete from the middle, and see how the indexes change.


```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

player = Actor("c1")

things = []

def on_key_down(key):
    speed = 10

    if key == keys.UP:
        player.y -= speed
    if key == keys.DOWN:
        player.y += speed
    if key == keys.LEFT:
        player.x -= speed
    if key == keys.RIGHT:
        player.x += speed

    if key == keys.F:
        f = Actor("flower")
        f.x = player.x
        f.y = player.y
        things.append(f)
    if key == keys.R:
        f = Actor("rock")
        f.x = player.x
        f.y = player.y
        things.append(f)

    if key == keys.U:
         things.pop()

    if key == keys.D:
        collide = []
        for t in things:
            if player.colliderect(t):
                collide.append(t)

        for t in collide:
            things.remove(t)

def draw():
    screen.fill('black')
    player.draw()

    
    for i in range(len(things)):
        t = things[i]
        t.draw()
        screen.draw.text(str(i), color=(255,255,255), topleft=(t.x,t.y))
        if i > 0:
            p = things[i-1]
            screen.draw.line((p.x,p.y), (t.x,t.y), (255,255,255))
pgzrun.go()
```

spend more time thinking about connecting previous and current elements from a list, think about how to do it the other way around, from current element to next:

```
# change this to go from t to the next element of things, instead from t to previous
for i in range(len(things)):
    t = things[i]
    ...
    if i > 0:
        p = things[i-1]
        ...
```

## [DAY-85] List; Functions

This day is more about reading than writing, those are few different examples you can use

![game-85.png](./screenshots/game-85.png "game 85 screenshot")


don't let the **zombie** flowers overrun you, smash them with rocks


```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

game_over = False

elf = Actor("c1")
elf.x = WIDTH/2
elf.y = HEIGHT-20
flowers = []
rocks = []

game_area = Rect((0, 0), (WIDTH, HEIGHT-40))

def add_one_row():
    lastY = 0
    if len(flowers) > 0:
        f = flowers[len(flowers)-1]
        lastY = f.y
    
    for i in range(20, WIDTH-10, 20):
        f = Actor("flower")
        f.x = i
        f.y = lastY + 10
        flowers.append(f)

def rock_out_of_screen():
    if len(rocks) > 0:
        rocks.pop(0)

def on_key_down(key):
    speed = 10
    if key == keys.LEFT:
        elf.x -= speed
    if key == keys.RIGHT:
        elf.x += speed
        
    if key == keys.SPACE:
        rock = Actor("rock")
        rock.x = elf.x
        rock.y = elf.y - 20
        animate(rock,pos=(rock.x, -100), on_finished=rock_out_of_screen)
        rocks.append(rock)

def update():
    global game_over
    hit = []
    for b in rocks:
        for f in flowers:
            if b.colliderect(f) and random.randint(0,10) > 7:
                hit.append(f)

    for h in hit:
        flowers.remove(h)

    for f in flowers:
        if not f.colliderect(game_area):
            game_over = True


def draw():
    if game_over:
        screen.draw.text("GAME OVER", color="white", topleft=(10,10))
    else:
        screen.fill('black')
        elf.draw()
        for f in flowers:
            f.draw()
        for r in rocks:
            r.draw()

        screen.draw.rect(game_area, (200, 0, 0))

add_one_row()
clock.schedule_interval(add_one_row, 5)

pgzrun.go()
```

![game-85-a.png](./screenshots/game-85-a.png "game 85-a screenshot")

```
import turtle as t

size = 10

t.pensize(size)
t.left(45)
t.forward(90)
t.circle(45,extent=180)
t.right(90)
t.circle(45,extent=180)
t.forward(90)
t.penup()
t.goto(-35,-35)
t.pendown()
t.write('i love python')
t.penup()
```

![game-85-b.png](./screenshots/game-85-b.png "game 85-b screenshot")


```
import  turtle as t
import datetime
import time
def deg(h,m,s):
	hDeg=(h*3600+m*60+s)/(3600*12)*360
	mDeg=(m*60+s)/3600*360
	sDeg=360/60*s
	
	return (90+hDeg,90+mDeg,90+sDeg)
	
	
def show(h, size):
	(hDeg,m,s) = deg(h,0,0)
	
	t.penup()
	t.goto(0, size)
	t.pencolor('white')
	t.setheading(hDeg)
	t.forward(size)
	t.write(str(h))
	
def klok(size, h, m, s):
	t.reset()
	(hDeg,mDeg,sDeg) = deg(h,m,s)
	
	t.pendown()
	t.pensize(7)
	t.bgcolor('black')
	t.pencolor('lime')
	
	t.circle(size)
	
	t.penup()
	t.goto(0, size)
	t.setheading(hDeg)
	t.pendown()
	t.pencolor('springgreen')
	t.forward(size/3)
	
	
	t.penup()
	t.goto(0, size)
	t.setheading(mDeg)
	t.pendown()
	t.pencolor('lawngreen')
	t.forward(size/2)
	t.penup()
	t.pencolor('cyan')
	t.goto(0, size)
	t.setheading(sDeg)
	t.pendown()
	t.forward(size-25)
	t.penup()
	
size = 150
while True:
	now = datetime.datetime.now()
	klok(size,now.hour, now.minute, now.second)

	for h in range(1, 13):
		show(h,size)
	time.sleep(10)
```

![game-85-c.png](./screenshots/game-85-c.png "game 85-c screenshot")

Just one rock that hits the zombies above you

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

game_over = False

elf = Actor("c1")
elf.x = WIDTH/2
elf.y = HEIGHT-20
rock = Actor("rock")
rock.x = elf.x + 10
rock.y = elf.y - 20

flowers = []

def add_one_row():
    lastY = 0
    if len(flowers) > 0:
        f = flowers[len(flowers)-1]
        lastY = f.y
    
    for i in range(20, WIDTH-10, 20):
        f = Actor("flower")
        f.x = i
        f.y = lastY + 10
        flowers.append(f)

def on_key_down(key):
    speed = 10
    if key == keys.LEFT:
        elf.x -= speed
    if key == keys.RIGHT:
        elf.x += speed
    if key == keys.UP:
        elf.y -= speed
    if key == keys.DOWN:
        elf.y += speed
        

def update():
    global game_over
    hit = []
    for f in flowers:
        if rock.colliderect(f) and random.randint(0,10) > 7:
            hit.append(f)

    for h in hit:
        flowers.remove(h)

    rock.x -= 1
    if rock.x < elf.x - 10:
        rock.x = elf.x + 10

    rock.y = elf.y - 20


def draw():
    screen.fill('black')
    elf.draw()
    rock.draw()
    for f in flowers:
        f.draw()

add_one_row()
clock.schedule_interval(add_one_row, 5)

pgzrun.go()
```

![day-85.jpg](./reading/day-85.jpg "day 85 reading")


## [DAY-86] Lists


![game-86.png](./screenshots/game-86.png "game 86 screenshot")

SNAKE

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

snake = Actor("c1")
snake.x = WIDTH/2
snake.y = HEIGHT-20

apple = Actor("flower")
apple.x = WIDTH/2
apple.y = HEIGHT/2

snake_size = 20
snake_speed = 1
steps = []
direction = "up"
step_size = 1
game_over = False
game_area = Rect(0,0,WIDTH,HEIGHT)
def on_key_down(key):
    global direction

    if key == keys.LEFT:
        direction = "left"
    if key == keys.RIGHT:
        direction = "right"
    if key == keys.UP:
        direction = "up"
    if key == keys.DOWN:
        direction = "down"

def update():
    global snake_size, game_over, snake_speed, steps

    s = Actor("snake")
    s.x = snake.x
    s.y = snake.y
    steps.append(s)
    if len(steps) > snake_size:
        steps = steps[-snake_size:]

    if direction == "left":
        snake.x -= step_size
    if direction == "right":
        snake.x += step_size
    if direction == "up":
        snake.y -= step_size
    if direction == "down":
        snake.y += step_size
    
    if snake.colliderect(apple):
        apple.x = random.randint(0,WIDTH)
        apple.y = random.randint(0,HEIGHT)
        snake_size += step_size * 10

    if not snake.colliderect(game_area):
        game_over = True

def draw():
    screen.fill('black')

    if game_over:
        screen.draw.text("GAME OVER", color="white", topleft=(10,10))
    else:
        screen.draw.rect(game_area, (255,0,0))
        for s in steps:
            s.draw()
        snake.draw()
        apple.draw()

pgzrun.go()
```

There are few key moments to emphasize, but the most important one is `steps = steps[-snake_size:]`.

Try this in IDLE:

```
x = [1,2,3,4]
print(x[-1])
```

It will print '4', so in python you can get elements from the back of the list, just as easily as the front, try `x[-2]`, now try to get multiple elements from a list, `y = x[0:2]`, it will make new list `[1,2]`, it is a bit like this code:

```
x = [1,2,3,4]
y = []
for i in range(0,2):
    y.append(x[i])
```

Now you can also ask python to give you the first 2 elements by saying `x[0:2]` or you can ask it for the elements *after* the second one by doing `x[2:len(x)]`, you can omit 0 and `len(x)` so it is a bit shorter, `x[:2]` and `x[2:]`. Sometimes you want the last 2 elements, to do that just say `x[-2:len(x)]` or `x[-2:]` and that's how we are getting the last `snake_size` elements of the `steps` list.

Again, `x[-2:len(x)]` just means from -2 elements from the end if the list, until the end of the list. It looks scary though.

Similar to this code:

```
x = [1,2,3,4]
y = []
for i in range(len(x)-2,len(x)):
    y.append(x[i])
```

## [DAY-87] Read/Write Files

Its File time!

First lets make a new file, called day-87.txt and we will open it in "w" mode, which means "write", so once we do `f.write` it will start from the beginning of the file, we can use "a" (for append) mode as well that would continue appending to the end of the file

```
f = open("day-87.txt", "w")

while True:
    a = input("what do you want to write: ")
    if a == "quit":
        break
    f.write(a + "\n")

f.close()
```

Now you can open day-87.txt with Notepad or some other text editor and see what you wrote.

It is important to remember this pattern

1. Open
2. Read or Write
3. Read or Write
4. Read or Write
5. Read or Write
6. ...
7. Close

lets see how you read a file:

```
f = open("day-87.txt", "r")
data = f.read()
print(data)
```

Make a game that persists the player position.


```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

elf = Actor("c1")
elf.x = WIDTH/2
elf.y = HEIGHT-20

try:
    x = open("day-87-x.txt", "r")
    elf.x = float(x.read())
    x.close()
    
    y = open("day-87-y.txt", "r")
    elf.y = float(y.read())
    y.close()
except IOError:
    pass

def on_key_down(key):
    speed = 10
    if key == keys.LEFT:
        elf.x -= speed
    if key == keys.RIGHT:
        elf.x += speed
    if key == keys.UP:
        elf.y -= speed
    if key == keys.DOWN:
        elf.y += speed

    if key == keys.S:
        x = open("day-87-x.txt", "w")
        x.write(str(elf.x))
        x.close()

        y = open("day-87-y.txt", "w")
        y.write(str(elf.y))
        y.close()


def draw():
    screen.fill('black')
    elf.draw()

pgzrun.go()
```

open `day-87-x.txt` and `day-87-y.txt` to see the positions of X and Y of the elf after you press `S`.

One other patter you will see is:

```
try:
    try to do something
except some error:
    handle error
```

There are many many things that could go wrong when you write to or read a file, for example when you read the file might not be created, or you might have no access to read it, or when you write the disk might be full, and there is no more space.

In our example we don't check if our write fails, so if your disk is full the game will crash, but in the beginning we do check for IOError in case the reading fails, and it will if the files are not created yet the very first time you start the game and there is no save yet.



## [DAY-88] Flask

Reading exercise, a lot of unfamiliar code

```
from flask import Flask, redirect, request,make_response
import random
app = Flask(__name__)

tokens = {}

@app.route('/')
def index():
    token = request.cookies.get('token')
    if token in tokens:
        response = make_response("""
        welcome to the secure section of the website,
        <a href="/logout">click here to logout
        """)
        return response

    
    response = make_response("""
        <html>
        <form action="/login" method="post">
        user: <input name="user">
        pass: <input type="password" name="pass">
        <input type="submit">
        </form>
        </html>
        """)
    return response

@app.route('/logout')
def logout():
    token = request.cookies.get('token')
    try:
        del tokens[token]
    except KeyError:
        pass

    response = make_response(redirect('/'))
    response.set_cookie('token', '')
    return response

@app.route('/login', methods = ['POST'])
def login():
    user = request.form['user']
    password = request.form['pass']
    if user == "admin" and password == "123":
        token = str(random.randint(0,10000000))
        tokens[token] = "admin"

        response = make_response(redirect('/'))
        response.set_cookie('token', token)
        return response
    else:
        return "access denied"
    
if __name__ == "__main__":
    app.run(host="127.0.0.1",port=8000,debug=True)
```

start the script, see what it does, try to debug how `tokens` changes. Inspect your cookies, try to hack it, login from private mode and steal the cookie from the console.