import pygame, math

pygame.init()

screen = pygame.display.set_mode((800, 600))


# def update():
#     pass

screen.fill((0, 0, 0))
pygame.display.flip()
# def draw():


# draw()
def draw_eye(eye_x, eye_y):
    mouse_x, mouse_y = pygame.mouse.get_pos()

    distance_x = mouse_x - eye_x
    distance_y = mouse_y - eye_y

    distance = min(math.sqrt(distance_x**2 + distance_y**2), 30)
    angle = math.atan2(distance_y, distance_x)
    pupil_x = eye_x + (math.cos(angle) * distance)
    pupil_y = eye_y + (math.sin(angle) * distance)

    print(mouse_x, end=" ")
    print(mouse_y)

    pygame.draw.circle(screen, (255, 255, 255), (eye_x, eye_y), 50)
    pygame.draw.circle(screen, (0, 0, 100), (pupil_x, pupil_y), 15)
    pygame.display.flip()


running = True
while running:
    draw_eye(200, 200)
    draw_eye(330, 200)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False