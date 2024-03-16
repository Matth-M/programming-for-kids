## [DAY-75] Functions; Callbacks; Lists; Encoding

![game-75.png](./screenshots/game-75.png "game 75 screenshot")


Enemies come to get you, and you shoot half moons at them. pretty cool.

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

score = 0
speed = 1
elf = Actor("c1")

beep = tone.create('A3', 0.5)
elf.x = 10
elf.y = HEIGHT/2

game_over = False

bullets = []
enemies = []

def make_enemies():
    level = int(score / 5) + 1

    duration = (5 - level)
    if duration < 1:
        duration = 1

    for i in range(level):
        snake = Actor("snake")    
        snake.x = WIDTH-20
        snake.y = random.randint(10,HEIGHT-10)
        animate(snake, pos=(-100, snake.y), tween='accelerate', duration=duration)
        enemies.append(snake)

def bullet_out_of_screen():
    bullets.pop(0)

def on_key_down(key):
    if key == keys.SPACE:
        b = Actor("bullet2")
        b.x = elf.x + 5
        b.y = elf.y
        animate(b, pos=(WIDTH + 100, elf.y), tween='accelerate', on_finished=bullet_out_of_screen)
        bullets.append(b)

def update():
    global game_over, speed, score, bullets, enemies
    if keyboard.left:
        elf.x = elf.x-speed
    if keyboard.right:
        elf.x = elf.x+speed
    if keyboard.up:
        elf.y = elf.y-speed
    if keyboard.down:
        elf.y= elf.y+speed
    if keyboard.R:
        speed = 1
        score = 0
        bullets = []
        enemies = []
        game_over = False

    hit = []
    for b in bullets:
        for e in enemies:
            if b.colliderect(e):
                hit.append(e)

    if len(hit) > 0:
        score += len(hit)
        if speed < 4:
            speed += 1
        beep.play()
        for e in hit:
            enemies.remove(e)

    for e in enemies:
        if e.colliderect(elf):
            game_over = True

def draw():
    if game_over:
        screen.fill('black')
        screen.draw.text("GAME OVER", color="white", topleft=(10,10))
    else:
        screen.fill('black')
        elf.draw()

        for b in bullets:
            b.draw()

        for e in enemies:
            e.draw()

        screen.draw.text("Score: "+ str(score), color="white", topleft=(10,10))


make_enemies()
clock.schedule_interval(make_enemies, 2)

pgzrun.go()
```
![day-75-1.jpg](./reading/day-75-1.jpg "day 75 example 1")



tic tac toe but with one character variable names

```
x = [
        #  0    1    2     3
        ['〰️','🅰️','🅱️','🅾️'], # 0 
        ['🥇','〰️','〰️','〰️'], # 1
        ['🥈','〰️','〰️','〰️'], # 2
        ['🥉','〰️','〰️','〰️'], # 3
        
    ]

k = '🛹'

while True:
    for i in x:
        for s in i:
            print(s,end=' ')
        print('')


    l = input(k + ": ")

    if l == 'a1':
        x[1][1]=k
    elif l == 'a2':
        x[2][1]=k
    elif l == 'a3':
        x[3][1]=k

    elif l == 'b1':
        x[1][2]=k
    elif l == 'b2':
        x[2][2]=k
    elif l == 'b3':
        x[3][2]=k

    elif l == 'o1':
        x[1][3]=k
    elif l == 'o2':
        x[2][3]=k
    elif l == 'o3':
        x[3][3]=k
    else:
        continue
    
    if k == '🛹':
        k = '⚽'
    else:
        k = '🛹'

```

30 and back

```
for i in range(1,31):
    print(i)
for i in range(1,31):
    print(30 - i)
```

football mania

```
d = 30
while True:
    for i in range(1,d):
        print('⚽' * i)
    for i in range(1,d):
        h = (d - i)
        print('⚽' * h)
```

## [DAY-76] Functions; Callbacks; Lists


![game-76.png](./screenshots/game-76.png "game 76 screenshot")

A game of tag! The elf is robin hood, running away from the king. The elf plays with WASD and the king plays with up/down/left/right.

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

speedA = 3
speedB = 3

playerA = Actor("c1")
playerB = Actor("c2")

playerA.x = 10
playerA.y = HEIGHT - 40

playerB.x = 10
playerB.y = 40

game_over = False

def random_speed():
    global speedA, speedB
    speedA = random.randint(1,5)
    speedB = random.randint(1,5)

def on_key_down(key):
    global game_over

    # player A
    if key == keys.A:
        playerA.x -= speedA
    if key == keys.D:
        playerA.x += speedA
    if key == keys.W:
        playerA.y -= speedA
    if key == keys.S:
        playerA.y += speedA

    # player B
    if key == keys.LEFT:
        playerB.x -= speedB
    if key == keys.RIGHT:
        playerB.x += speedB
    if key == keys.UP:
        playerB.y -= speedB
    if key == keys.DOWN:
        playerB.y += speedB

def update():
    global game_over
    if playerA.colliderect(playerB):
        game_over = True
    
def draw():
    if game_over:
        screen.fill('black')
        screen.draw.text("GAME OVER", color="white", topleft=(10,10))
    else:
        screen.fill('black')
        screen.draw.text("RUN! elf: " + str(speedA) + " king: " + str(speedB) , color="white", topleft=(10,10))
        playerA.draw()
        playerB.draw()

clock.schedule_interval(random_speed, 2)

pgzrun.go()
```


Basic math quiz

```
import random
while True:
    k = random.randint(1,13)
    s = random.randint(1,13)
    r = k * s
    g = int(input('How much is '+str(k) +'*' +str(s) + ': '))
    if g == r:
        print('Wow nice job its CORRECT')
    else:
        print('wrong the answer was: ' + str(r))
```

7 days average

```
x = [1231,5123,6737,6725,6261,2664,62561]
n = len(x)

print(x)
print(n)

sum = 0
for i in x:
    sum += i

print('sum: ' + str(sum))
print('average: ' + str(sum/n))
```

## [DAY-77] Lists; Encode/Decode

morse code translator

```
alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','.',',']
morse = ['.-','-...','-.-.','-..','.','..-.','--.','....','..','.---','-.-','.-..','--','-.','---','.--.','--.-','.-.','...','-','..-','...-','.--','-..-','-.--','--..','/','.-.-.-','--..--']

print(len(morse))
print(len(alphabet))

for i in range(len(alphabet)):
    print(alphabet[i] + " -> " + morse[i])

text = '.... . .-.. .-.. --- / .-- --- .-. .-.. -.. .-.-.- / - .... .. ... / .. ... / -- --- .-. ... . / -.-. --- -.. . .-.-.- / - .... . .-. . / .- .-. . / -- .- -. -.-- / -.-. --- -.. . ... --..-- / -... ..- - / - .... .. ... / --- -. . / .. ... / .--. .-. . - - -.-- / -.-. --- --- .-.. --..-- / --. --- --- -.. / .--- --- -... / - .-. .- -. ... .-.. .- - .. -. --. / .. - .-.-.-'.split(' ')
for word in text:
    found = False
    for i in range(len(morse)):
        x = morse[i]
        if x == word:
            print(alphabet[i], end = '')
            found = True
    if not found:
        print(word , end='')
```

## [DAY-78] Coordinates; Functions; Callbacks

![game-78.png](./screenshots/game-78.png "game 78 screenshot")

Small modifications to the previous game, gold in the middle moves the king away, randomize the elf position every 2 seconds

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

speedE = 3
speedK = 3

elf = Actor("c1")
king = Actor("c2")
gold = Actor("c3")

gold.x = WIDTH/2
gold.y = HEIGHT/2
elf.x = 10
elf.y = HEIGHT - 40
king.x = 10
king.y = 40

game_over = False

def random_speed():
    global speedE, speedK
    speedE = random.randint(3,5)
    speedK = random.randint(2,5)

def random_place():
    elf.x = random.randint(0,WIDTH)
    elf.y = random.randint(0,HEIGHT)

def update():
    global game_over

    # elf
    if keyboard.A:
        elf.x -= speedE
    if keyboard.D:
        elf.x += speedE
    if keyboard.W:
        elf.y -= speedE
    if keyboard.S:
        elf.y += speedE

    # king
    if keyboard.left:
        king.x -= speedK
    if keyboard.right:
        king.x += speedK
    if keyboard.up:
        king.y -= speedK
    if keyboard.down:
        king.y += speedK

    if keyboard.SPACE:
        elf.image = 'snake'
        random_speed()

    if keyboard.R:
         game_over = 1==2
         elf.x = 10
         elf.y = HEIGHT - 40
         king.x = 10
         king.y = 40
         
    if elf.x < 0:
        elf.x = 0
    if elf.x > WIDTH:
        elf.x = WIDTH
    if elf.y < 0:
        elf.y = 0
    if elf.y > HEIGHT:
        elf.y = HEIGHT


    if king.x < 0: 
        king.x = 0
    if king.x > WIDTH:
        king.x = WIDTH
    if king.y < 0:
        king.y = 0
    if king.y > HEIGHT:
        king.y = HEIGHT

    if elf.colliderect(gold):
        king.x = WIDTH
        king.y = HEIGHT

    if king.colliderect(gold):
        game_over = True

    if elf.colliderect(king):
        game_over = True
    
def draw():
    if game_over:
        screen.fill('black')
        screen.draw.text("GAME OVER", color="white", topleft=(10,10))
    else:
        screen.fill('black')
        screen.draw.text("RUN! elf: " + str(speedE) + " king: " + str(speedK) , color="white", topleft=(10,10))
        elf.draw()
        king.draw()
        gold.draw()

clock.schedule_interval(random_speed, 2)
clock.schedule_interval(random_place, 5)

pgzrun.go()
```

Explanation about setting x and y to be random:

![day-78-explain.png](./reading/day-78-explain.png "day 78 explain coordinates")

Write a program to compute the average of a list of numbers:

![day-78-a.jpg](./reading/day-78-a.jpg "day 78 average of list of numbers")

Decode morse code:

![day-78-c.jpg](./reading/day-78-c.jpg "day 78 decode morse code")



## [DAY-79] Lists; Encoding

morse code agian

```
alphabet = ['a','b','c','d','e']
morse = ['.-','-...','-.-.','...','.']


for i in range(len(alphabet)):
    print(alphabet[i])
    print(morse[i])

text = ['.-..','.','.-..','.-']

for word in text:
    for c in range(len(morse)):
        if word == morse[c]:
            print(alphabet[c])
```

## [DAY-80] Lists; Functions

![game-80.png](./screenshots/game-80.png "game 80 screenshot")


PONG (almost)

```
import pgzrun
import random

HEIGHT = 200
WIDTH = 200

left = Actor("c1")
left.x = 10
left.y = HEIGHT/2

right = Actor("c2")
right.x = WIDTH - 10
right.y = HEIGHT/2

ball = Actor("bullet")
ball.x = WIDTH/2
ball.y = HEIGHT/2

game_area = Rect((0, 0), (WIDTH, HEIGHT))

game_over = False

def send_ball_to(direction):
    duration = 3
    if direction == 'left':
        animate(ball, pos=(-100, random.randint(0,HEIGHT)), tween='linear', duration=duration)
    else:
        animate(ball, pos=(WIDTH + 100, random.randint(0,HEIGHT)), tween='linear', duration=duration)

def update():
    global game_over
    speed = 3

    if keyboard.R:
        ball.x = WIDTH/2
        ball.y = HEIGHT/2
        send_ball_to('left')
        game_over = False

    if keyboard.W:
        left.y -= speed
    if keyboard.S:
        left.y += speed

    if keyboard.up:
        right.y -= speed
    if keyboard.down:
        right.y += speed

    if left.colliderect(ball):
        send_ball_to('right')

    if right.colliderect(ball):
        send_ball_to('left')

    if not ball.colliderect(game_area):
        game_over = True

def draw():
    if game_over:
        screen.fill('black')
        screen.draw.text("GAME OVER", color="white", topleft=(10,10))
    else:
        screen.fill('black')
        left.draw()
        right.draw()
        ball.draw()
        screen.draw.rect(game_area, (200, 0, 0))

send_ball_to('left')

pgzrun.go()
```


![day-80-a.jpg](./reading/day-80-a.jpg "day 80 reading pong")

average of two lists

![day-80-b.jpg](./reading/day-80-b.jpg "day 80 reading average of two lists")


## [DAY-81] Lists; Encoding

First image

```
+-----+
| * * |
|  *  |
| * * |
+-----+
```


list of lists with pixels

```
image = [
    [1,3,3,3,3,3,1],
    [2,4,5,4,5,4,2],
    [2,4,4,5,4,4,2],
    [2,4,5,4,5,4,2],
    [1,3,3,3,3,3,1],
]

for row in image:
    for pixel in row:
        if pixel == 1:
            print('+', end='')
        elif pixel == 2:
            print('|', end='')
        elif pixel == 3:
            print('-', end='')
        elif pixel == 4:
            print(' ', end='')
        elif pixel == 5:
            print('*', end='')
        else:
            print("dont know what to do with: " + str(pixel))
    print('')
```

just a list of pixels

```
image = [
    1,3,3,3,3,3,1,
    2,4,5,4,5,4,2,
    2,4,4,5,4,4,2,
    2,4,5,4,5,4,2,
    1,3,3,3,3,3,1,
]

width = 7

for (index, pixel) in enumerate(image):
    if index > 0 and index % width == 0:
        print('')

    if pixel == 1:
        print('+', end='')
    elif pixel == 2:
        print('|', end='')
    elif pixel == 3:
        print('-', end='')
    elif pixel == 4:
        print(' ', end='')
    elif pixel == 5:
        print('*', end='')
    else:
        print("dont know what to do with: " + str(pixel))
```

some fun with lists
```
x = ['a','b','c','d']
m = ['w','x','y','z']
d = ['g','h','j','k']

# a -> 0
# b -> 1
# c -> 2

for i in range(len(x)):
    print(i,end=' ')
    print(x[i],end=' ')
    print(m[i],end=' ')
    print(d[i])
```

how similar are lists and strings

```
x = 'hello'

for i in range(len(x)):
    print(i,end=' ')
    print(x[i])
```

similar, but not quite, you cant change the inside of a string, but you can change the inside of a list.

```
x = ['h','e','l','l','o']
y = 'hello'

x[2] = 'm'
y = 'hemlo'

for i in range(len(x)):
    print(i,end=' ')
    print(x[i], end=' ')
    print(y[i])
```

sum many lists
```
a = [6,3,2]
b = [78,21,1]
c = [123,5,1]

sum = 0
for i in range(len(a)):
    sum += a[i] + b[i] + c[i]

print(sum)
```

another way to sum

```
a = [6,3,2]
b = [78,21,1]
c = [123,5,1]

sum = 0

for x in a:
    sum += x

for x in b:
    sum += x

for x in c:
    sum += x

print(sum)
```
