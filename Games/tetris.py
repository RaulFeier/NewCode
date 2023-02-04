import pygame
import random

colors = [
    (25, 25, 25),
    (240, 230, 80),
    (120, 190, 150),
    (230, 60, 60),
    (75, 150, 240),
    (250, 190, 70),
    (230, 100, 100),
    (120, 120, 180),
]

pieces = [
    [
        [
            [0, 0, 0, 0],
            [0, 1, 1, 0],
            [0, 1, 1, 0],
            [0, 0, 0, 0],
        ],
    ],
    [
        [
            [0, 0, 0, 0],
            [2, 2, 2, 2],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 2, 0, 0],
            [0, 2, 0, 0],
            [0, 2, 0, 0],
            [0, 2, 0, 0],
        ],
    ],
    [
        [
            [0, 0, 0, 0],
            [0, 3, 3, 0],
            [3, 3, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [3, 0, 0, 0],
            [3, 3, 0, 0],
            [0, 3, 0, 0],
            [0, 0, 0, 0],
        ],
    ],
    [
        [
            [0, 0, 0, 0],
            [4, 4, 0, 0],
            [0, 4, 4, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 4, 0, 0],
            [4, 4, 0, 0],
            [4, 0, 0, 0],
            [0, 0, 0, 0],
        ],
    ],
    [
        [
            [0, 0, 0, 0],
            [5, 5, 5, 0],
            [5, 0, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 5, 0, 0],
            [0, 5, 0, 0],
            [0, 5, 5, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 0, 5, 0],
            [5, 5, 5, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [5, 5, 0, 0],
            [0, 5, 0, 0],
            [0, 5, 0, 0],
            [0, 0, 0, 0],
        ],
    ],
    [
        [
            [0, 0, 0, 0],
            [6, 6, 6, 0],
            [0, 0, 6, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 6, 0, 0],
            [0, 6, 0, 0],
            [6, 6, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [6, 0, 0, 0],
            [6, 6, 6, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 6, 6, 0],
            [0, 6, 0, 0],
            [0, 6, 0, 0],
            [0, 0, 0, 0],
        ],
    ],
    [
        [
            [0, 0, 0, 0],
            [7, 7, 7, 0],
            [0, 7, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 7, 0, 0],
            [0, 7, 7, 0],
            [0, 7, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 7, 0, 0],
            [7, 7, 7, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
        ],
        [
            [0, 7, 0, 0],
            [7, 7, 0, 0],
            [0, 7, 0, 0],
            [0, 0, 0, 0],
        ],
    ],
]


def initialize():
    global width, height, screen, inert, piece, rotation
    global rspiece, x, y, lsttime, pieceq, moved, score, piecehold

    pygame.init()
    width = 25 * 15
    height = 25 * 20
    screen = pygame.display.set_mode((width, height))
    pygame.display.set_caption("Coclender")
    inert = []
    for i in range(10):
        inert.append([])
        for _ in range(20):
            inert[i].append(0)
    piece = 1
    rotation = 0
    lsttime = pygame.time.get_ticks()
    x = 0
    y = 0
    pieceq = []
    for i in range(4):
        pieceq.append(random.randint(0, len(pieces) - 1))
    moved = False
    rspiece = 0
    score = 0
    piecehold = -1

    draw()


def checktime():
    global lsttime, y, moved, rspiece
    dt = pygame.time.get_ticks() - lsttime
    if dt > 1000:
        lsttime = pygame.time.get_ticks()
        if canmove(x, y + 1, rotation):
            y += 1
            moved = True
        else:
            rspiece += 1

    if rspiece > 1:
        rspiece = 0
        nextpiece()

    draw()


def canmove(testx, testy, testrot):
    global piece

    for i in range(4):
        for j in range(4):
            if pieces[piece][testrot][i][j] != 0:
                if testx + i < 0 or testx + i >= 10 or testy + j >= 20:
                    return False
                if inert[testx + i][testy + j] != 0:
                    return False
    return True


def drop():
    global y, moved
    while canmove(x, y + 1, rotation):
        y += 1
        moved = True
    draw()


def checkbotlinecuzfthis():
    for j in range(16, 19):
        empty = True
        for i in range(10):
            if inert[i][j] == 0:
                empty = False

        if empty:
            return j

    return -1


def checkline():
    global score

    for i in range(19, 0, -1):
        goodline = True
        for j in range(10):
            if inert[j][i] == 0:
                goodline = False
        if goodline:
            for j in range(10):
                inert[j][i] = 0
            for j in range(i, 0, -1):
                for k in range(10):
                    inert[k][j] = inert[k][j - 1]
            score += 1
            return True


def draw():
    global piece, rotation, x, y, piecehold

    checkline()
    screen.fill((0, 0, 0))
    for i in range(10):
        for j in range(20):
            color = colors[inert[i][j]]
            pygame.draw.rect(screen, color, (i * 25, j * 25, 24, 24))

    for i in range(4):
        for j in range(4):
            if pieces[piece][rotation][i][j] != 0:
                color = colors[pieces[piece][rotation][i][j]]
                pygame.draw.rect(screen, color, ((x + i) * 25, (y + j) * 25, 24, 24))

    idk1 = 11
    idk2 = -4
    for k in range(3):
        idk2 += 5
        temppiece = pieceq[k]
        for i in range(idk1, idk1 + 4):
            for j in range(idk2, idk2 + 4):
                color = colors[pieces[temppiece][0][i - idk1][j - idk2]]
                if color != ((25, 25, 25)):
                    pygame.draw.rect(screen, color, (i * 25, j * 25, 24, 24))

    if piecehold != -1:
        idk2 += 5
        for i in range(idk1, idk1 + 4):
            for j in range(idk2, idk2 + 4):
                color = colors[pieces[piecehold][0][i - idk1][j - idk2]]
                if color != ((25, 25, 25)):
                    pygame.draw.rect(screen, color, (i * 25, j * 25, 24, 24))

    pygame.display.flip()


def nextpiece():
    global piece, rotation, x, y, pieceq, moved, running

    for i in range(4):
        for j in range(4):
            if pieces[piece][rotation][i][j] != 0:
                inert[x + i][y + j] = pieces[piece][rotation][i][j]

    piece = pieceq[0]
    if not canmove(0, 0, 0):
        running = False
        return

    rotation = 0
    x = 0
    y = 0
    pieceq.pop(0)
    pieceq.append(random.randint(0, len(pieces) - 1))
    moved = False

    checkline()


def hold():
    global piecehold, piece, rotation, x, y, pieceq
    if piecehold == -1:
        piecehold = piece
        piece = pieceq[0]
        if not canmove(x, y, 0):
            piece = piecehold
            piecehold = -1
            return
        pieceq.pop(0)
        rotation = 0
        pieceq.append(random.randint(0, len(pieces) - 1))

    else:
        piecehold, piece = piece, piecehold
        if not canmove(x, y, 0):
            piece = piecehold
            piecehold = -1
            return
        rotation = 0


initialize()
global running
running = True
while running:
    checktime()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        global rotation

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_x:
                testrot = ((rotation + 1) + len(pieces[piece])) % len(pieces[piece])
                if canmove(x, y, testrot):
                    rotation = testrot

            elif event.key == pygame.K_z:
                testrot = ((rotation - 1) + len(pieces[piece])) % len(pieces[piece])
                if canmove(x, y, testrot):
                    rotation = testrot

            elif event.key == pygame.K_LEFT:
                if canmove(x - 1, y, rotation):
                    x -= 1

            elif event.key == pygame.K_RIGHT:
                if canmove(x + 1, y, rotation):
                    x += 1

            elif event.key == pygame.K_DOWN:
                if canmove(x, y + 1, rotation):
                    y += 1

            elif event.key == pygame.K_SPACE:
                drop()

            elif event.key == pygame.K_a:
                hold()

            elif event.key == pygame.K_ESCAPE:
                running = False

        checktime()
        draw()