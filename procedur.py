import sys, pygame
import time
from pygame.math import Vector2
pygame.init()

size = width, height = 640, 480
screen = pygame.display.set_mode(size)

HEAD = pygame.image.load("./sprite-0001.png")
BODY = pygame.image.load("./sprite-0002.png")
TAIL = pygame.image.load("./sprute.png")

BODY_RECT = BODY.get_rect()
TAIL_RECT = TAIL.get_rect()
HEAD_RECT = HEAD.get_rect()

points = list(map(Vector2, [(i*50, 100) for i in range(7)]))
target = Vector2(450, 300)

rel_points = []
angles = []

max_angle = 360 # Adjust for limited angles
target_speed = Vector2(1, 1)
lerp_factor = 0.1  # Adjust this value to control the smoothness of the movement
for i in range(1, len(points)):
    rel_points.append(points[i] - points[i-1])
    angles.append(0)

def solve_ik(i, endpoint, target):
    if i < len(points) - 2:
        endpoint = solve_ik(i+1, endpoint, target)
    current_point = points[i]

    angle = (endpoint-current_point).angle_to(target-current_point)
    angles[i] += min(max(-3, angle), 3)
    angles[i] = min(max(180-max_angle, (angles[i]+180)%360), 180+max_angle)-180

    return current_point + (endpoint-current_point).rotate(angle)

def render():
    black = 0, 0, 0
    white = 255, 255, 255

    screen.fill(white)
    for i in range(1, len(points)):
        prev = points[i-1]
        cur = points[i]
        pygame.draw.aaline(screen, black, prev, cur)
    for point in points:
        if point == points[0]:
            pass
        elif point == points[-1]:
            screen.blit(TAIL, (int(point[0] -64 // 2), int(point[1]) -64 // 2))
        else:
            screen.blit(BODY, (int(point[0] -64 // 2), int(point[1]) -64 // 2))
        
        pygame.draw.circle(screen, black, (int(point[0]), int(point[1])), 5)

    screen.blit(HEAD, (points[0][0] -64 // 2, points[0][1] -64 // 2))
    pygame.display.flip()

while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()

    # Move the target
    target = Vector2(pygame.mouse.get_pos())

    # Update the positions of the points to follow the target with a fixed distance
    for i in range(len(points) - 1, 0, -1):
        direction = (points[i-1] - points[i]).normalize()
        points[i] = points[i-1] - direction * 50

    # Use lerp to move the main node towards the target
    points[0] = points[0].lerp(target, lerp_factor)

    # Update the target position based on speed
    target += target_speed
    if target.x <= 0 or target.x >= width:
        target_speed.x = -target_speed.x
    if target.y <= 0 or target.y >= height:
        target_speed.y = -target_speed.y

    render()

    pygame.time.wait(int(1000/60))
