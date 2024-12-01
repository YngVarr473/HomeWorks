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
    # задаёт позиции центра, а дальше я не понял
    
    def __draw_axis(self, screen):
        end_x = self.center[0] + 100 * math.cos(math.radians(self.angle))
        end_y = self.center[1] + 100 * math.sin(math.radians(self.angle))
        pygame.draw.line(screen, (255,0,0), self.center, (end_x, end_y), 2)

        end_x = self.center[0] - 100 * math.cos(math.radians(self.angle + 90))
        end_y = self.center[1] - 100 * math.sin(math.radians(self.angle + 90))
        pygame.draw.line(screen, (0,0,255), self.center, (end_x, end_y), 2)
# Отрисовывает линии, как в координатной прямой, перпендикулярные друг другу. Я не знаю, зачем они нужны?
# Здесь задействованы разные математические функции из библиотеки math: cos, sin for example

    def draw(self, screen):
        pygame.draw.circle(screen, (0,0,0), self.center, 50, 2)
        pygame.draw.circle(screen, (0,0,0), self.center, 5, 0)
# Создаёт форму нода (круг с точкой в центре)

        self.__draw_axis(screen)

        if self.next_node:
            self.next_node.draw(screen)
            pygame.draw.line(screen, (0,0,0), self.center, self.next_node.center, 2)
# Если появляется следущий Node, создаётся линия между ними (кость)

    def add_node(self, pos):
        if self.next_node == None:
            self.next_node = Node(pos, self.index + 1)  
        else:
            self.next_node.add_node(pos)
# Не понял

class Window:   #Создание игрового окна
    def __init__(self):
        self.height = 800   #Задали размеры окна, в пикселях
        self.width = 600
        self.screen = pygame.display.set_mode((self.height, self.width))    #одна из функций библиотеки - pygame, создаёт окно и задаёт размер с помощью (self.height, self.width), тоесть принимаёт за высоту и длину их значения     
        self.root_node = Node((500,200))
        self.root_node.add_node((300,300))      # Создание корневого Node и доблавение ещё 2-ух, в скобках их размеры 
        self.root_node.add_node((200,400))
        
    def run(self):
        while True:
            for event in pygame.event.get():    #обработка нажатия клавиш, мыши (нажатия клавиш и деёствия для них берутся из main.py)
                keys = pygame.key.get_pressed() #с помощью этого как раз определеяется какая клавиша нажата, идёт обращение к коду из main.py
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
            self.screen.fill((47,64,64))     # закрашивает игровое поле белым цветом и выполняется всегда, т.к. относится к циклу while 
            self.root_node.draw(self.screen)     # обращение к методу draw, тоесть сначала идёт очистка всей карты  
                                                    # с помощью предыдущей строки, а затем заново рисует Node  
            pygame.display.flip()   # в конце после всего завершения всех изменений цикла экран смняется на новый (обновляется кадр) 

window = Window()   # вызывает класс Window, тоесть создаётся игровое окно
window.run()    #вызывает класс run, отображает все действия  
