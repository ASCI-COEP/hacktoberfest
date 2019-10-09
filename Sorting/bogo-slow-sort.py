from random import shuffle
from random import randint

def bogosort(l):
    while not ordenado(l):
        shuffle(l)
        print(l)
    return l
 
def ordenado(l):
    if not l:
        return True
    last = l[0]
    for x in l[1:]:
        if x < last:
            return False
        last = x
    return True

def randomArray(largo):
    lista = []
    for numero in range(0,largo):
        numero = randint(0,1000)
        lista.append(numero)
    return lista

lista = randomArray(10)

bogosort(lista)