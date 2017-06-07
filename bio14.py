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
    #global poblacion_inicial
    poblacion_inicial = []
    for i in range(0,n):
        ra = random.randint(0, maximo) # Para generar RANDOM
        x=bin(ra)[2:].zfill(c) # C => cantidad de cromosomas
        print x
        poblacion_inicial.append(x)    
    return poblacion_inicial


#Evaluando los individuos:
def evaluar_individuos(lista): #lista va a contener mi polbacion INICIAL
    e_individuos = []
    for i in range(len(lista)): #range(len(lista)) => para sacar el tamano de la cadena
        #print int(lista[i],2) #int(...) => para convertir a binario
        num = int(lista[i],2)
        cadena = lista[i]
        nuca = cadena,num #'100010',30
        e_individuos.append(nuca)
    return e_individuos

#Seleccion de individuos:
def seleccion_individuos(lista):
    s_individuos = []
    suma_t = 0
    # for => para obtener el 100 porciento
    for i in range(len(lista)):
        #print lista[i][1]
        suma_t += lista[i][1]
    #print suma_t

    for i in range(len(lista)):
        por = (lista[i][1]*100.0)/suma_t #por => porcentaje
        cadena = lista[i][0]
        cadena1 = lista[i][1]
        porcad = cadena,cadena1,por
        s_individuos.append(porcad)
    return s_individuos

#Seleccion de individuos con RULETA:
def ruleta(lista):
    x = random.uniform(0, 100) #con esto genero un numero random de 0 a 100
    #print "este es el # random:   ", x
    ruleta_v = [] # almacenar todas las restas
    for i in range(len(lista)):
       z = abs(x - lista[i][1])
       #print z
       ruleta_v.append(z)

    w = min(ruleta_v) # w voy a sacar el menor que guardo en ruleta_v
    pw = [i for i, x in enumerate(ruleta_v) if x == w] # pw => sacar la posicion
    print "este es el menor:   ", w
    print pw
    #return w
    #print p_w
        
    
    
    

#crear_poblacion(4,5)
#x = ["11110","10000","10101"]
#evaluar_individuos(x)
y=[('11110', 10), ('10000', 50), ('10101', 60)]
#print seleccion_individuos(y)
ruleta(y)

    
        