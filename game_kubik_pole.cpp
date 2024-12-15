#!/usr/bin/env python3
# <------------------------------------- TASK:
# Задача: поставить кубик ниже и правее
# Награда: 30 Киберонов
# Условие: можно пользоваться любыми сервисами или ресурсами
# <------------------------------------- END TASK.

import pygame
import sys
pygame.init()

class Game:
	def __init__(self):
		self.screen = pygame.display.set_mode((800,600))
	
	def draw_world(self):
		pygame.draw.polygon(self.screen, (77, 53, 18),
			[[105, 120], [105, 420], [230, 620], [230, 250]]) # Левая сторона
		pygame.draw.polygon(self.screen, (105, 72, 24),[[230,250], [595,250], [595,620], [230,620]]) # Передняя сторона
		pygame.draw.polygon(self.screen, (0, 255, 0),
			[[100,120], [430, 120], [600,250], [230,250]]) # Верхняя сторона

	def render(self):
		self.screen.fill((0,0,0))
		self.draw_world()
		pygame.display.flip()
		
	def run(self):
		while True:
			for event in pygame.event.get():
				if event.type == pygame.QUIT:
					sys.exit()
					
			self.render()
Game().run()
	
