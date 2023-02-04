import pygame, random

global mp, screen
pygame.init()
screen = pygame.display.set_mode((400, 400))


def move(turn):
    global mp

    if turn == 0:
        for i in range(4):
            for e in range(4):
                x = i
                while x > 0:
                    if mp[e][x - 1][0] == 0:
                        mp[e][x - 1][0] = mp[e][x][0]
                        mp[e][x][0] = 0
                        x -= 1
                    elif (
                        mp[e][x - 1][0] == mp[e][x][0]
                        and mp[e][x - 1][1] == False
                        and mp[e][x][1] == False
                    ):
                        mp[e][x - 1][0] *= 2
                        mp[e][x - 1][1] += True
                        mp[e][x][0] = 0
                        x -= 1
                    else:
                        break

    elif turn == 1:
        for i in range(4):
            for e in range(4):
                x = i
                while x > 0:
                    if mp[x - 1][e][0] == 0:
                        mp[x - 1][e][0] = mp[x][e][0]
                        mp[x][e][0] = 0
                        x -= 1
                    elif (
                        mp[x - 1][e][0] == mp[x][e][0]
                        and mp[x - 1][e][1] == False
                        and mp[x][e][1] == False
                    ):
                        mp[x - 1][e][0] *= 2
                        mp[x - 1][e][1] += True
                        mp[x][e][0] = 0
                        x -= 1
                    else:
                        break

    elif turn == 2:
        for i in range(3, -1, -1):
            for e in range(4):
                x = i
                while x < 3:
                    if mp[e][x + 1][0] == 0:
                        mp[e][x + 1][0] = mp[e][x][0]
                        mp[e][x][0] = 0
                        x += 1
                    elif (
                        mp[e][x + 1][0] == mp[e][x][0]
                        and mp[e][x + 1][1] == False
                        and mp[e][x][1] == False
                    ):
                        mp[e][x + 1][0] *= 2
                        mp[e][x + 1][1] += True
                        mp[e][x][0] = 0
                        x += 1
                    else:
                        break

    elif turn == 3:
        for i in range(3, -1, -1):
            for e in range(4):
                x = i
                while x < 3:
                    if mp[x + 1][e][0] == 0:
                        mp[x + 1][e][0] = mp[x][e][0]
                        mp[x][e][0] = 0
                        x += 1
                    elif (
                        mp[x + 1][e][0] == mp[x][e][0]
                        and mp[x + 1][e][1] == False
                        and mp[x][e][1] == False
                    ):
                        mp[x + 1][e][0] *= 2
                        mp[x + 1][e][1] += True
                        mp[x][e][0] = 0
                        x += 1
                    else:
                        break

    for i in range(4):
        for j in range(4):
            if mp[i][j][1] == True:
                mp[i][j][1] = False

    addpieces()
    draw()


def draw():
    global mp, screen

    for i in range(4):
        for j in range(4):
            if mp[i][j][0] == 0:
                pygame.draw.rect(screen, (100, 100, 100), (i * 100, j * 100, 100, 100))
            else:
                pygame.draw.rect(screen, (0, 0, 0), (i * 100, j * 100, 100, 100))
                font = pygame.font.SysFont("comicsansms", 100)
                text = font.render(str(mp[i][j][0]), True, (255, 255, 255))
                screen.blit(text, (i * 100 + 20, j * 100 + 20))
    pygame.display.flip()


def initialize():
    global mp, screen
    mp = [
        [[0, False], [0, False], [0, False], [0, False]],
        [[0, False], [0, False], [0, False], [0, False]],
        [[0, False], [0, False], [0, False], [0, False]],
        [[0, False], [0, False], [0, False], [0, False]],
    ]
    addpieces()
    pygame.display.set_caption("2048")


def addpieces():
    global mp, running

    for i in range(3):
        x = random.randint(0, 3)
        y = random.randint(0, 3)
        if mp[x][y][0] == 0 and i in range(2):
            mp[x][y][0] = 2
        else:
            rnd = random.randint(0, 1)
            if rnd == 0 and mp[x][y][0] == 0:
                mp[x][y][0] = 4

    found = False
    for i in range(4):
        for j in range(4):
            if mp[i][j][0] == 0:
                found = True
                break

    if not found:
        running = False


initialize()
draw()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                running = False
            elif event.key == pygame.K_LEFT:
                move(1)
            elif event.key == pygame.K_UP:
                move(0)
            elif event.key == pygame.K_RIGHT:
                move(3)
            elif event.key == pygame.K_DOWN:
                move(2)