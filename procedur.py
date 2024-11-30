import pygame
import sys
import math

pygame.init()

class Node:
    def __init__(self, center_pos, index = 1):
        self.center = center_pos
        self.index = index
        self.next_node = None
        self.angle = 0
    
    def __draw_axis(self, screen):
        end_x = self.center[0] + 100 * math.cos(math.radians(self.angle))
        end_y = self.center[1] + 100 * math.sin(math.radians(self.angle))
        pygame.draw.line(screen, (255,0,0), self.center, (end_x, end_y), 2)

        end_x = self.center[0] - 100 * math.cos(math.radians(self.angle + 90))
        end_y = self.center[1] - 100 * math.sin(math.radians(self.angle + 90))
        pygame.draw.line(screen, (0,0,255), self.center, (end_x, end_y), 2)



    def draw(self, screen):
        pygame.draw.circle(screen, (0,0,0), self.center, 50, 2)
        pygame.draw.circle(screen, (0,0,0), self.center, 5, 0)

        #self.__draw_axis(screen)

        if self.next_node:
            self.next_node.draw(screen)
            pygame.draw.line(screen, (0,0,0), self.center, self.next_node.center, 2)

    def add_node(self, pos):
        if self.next_node == None:
            self.next_node = Node(pos, self.index + 1)
        else:
            self.next_node.add_node(pos)

class Window:
    def __init__(self):
        self.height = 800
        self.width = 600
        self.screen = pygame.display.set_mode((self.height, self.width))
        self.root_node = Node((500,200))
        self.root_node.add_node((300,300))
        self.root_node.add_node((200,400))
        
    def run(self):
        while True:
            for event in pygame.event.get():
                keys = pygame.key.get_pressed()
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
            self.screen.fill((255,255,255))
            self.root_node.draw(self.screen)

            pygame.display.flip()

window = Window()
window.run()
