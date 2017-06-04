from array import array
import math
import random

#poblacion_inicial = [] # mi vector para almacenar la poblacion

def maximo_limit(n):
    max = pow(2,n)
    return max

# Funcion para crear mi POBLACION INICIAL
# donde n es el tamano de la poblacion
# donde c es la cantidad de cromosomas
# ra => tamano de cromosomas
def crear_poblacion(n,c):
    maximo = maximo_limit(c)
    #print maximo   #Imprime el Maximo
    global poblacion_inicial
    poblacion_inicial = []
    for i in range(0,n):
        ra = random.randint(0, maximo) # Para generar RANDOM
        x=bin(ra)[2:].zfill(c) # C => cantidad de cromosomas
        print x
        poblacion_inicial.append(x)    
    return poblacion_inicial


#Evaluando los individuos:
def evaluar_individuos():
    
    

crear_poblacion(8,5)
#evaluar_individuos()
    
        