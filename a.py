import random
import subprocess

INF = 10 ** 18
def generate_random (n, reale):
    a = []
    if reale:
        a = [random.random () * INF for _ in range (n)]
    else:
        a = [random.randint (-INF, INF) for _ in range (n)]
    return [n] + a

def generate_sorted (n, reale):
    a = []
    if reale:
        a = [random.random() * INF for _ in range(n)]
    else:
        a = [random.randint(-INF, INF) for _ in range(n)]
    a.sort ()
    return [n] + a

def generate_reversed_sorted (n, reale):
    a = []
    if reale:
        a = [random.random() * INF for _ in range(n)]
    else:
        a = [random.randint(-INF, INF) for _ in range(n)]
    a.sort ()
    a.reverse()

    return [n] + a
def generate_toate_egale (n, reale):
    a = []
    if reale:
        x = random.random () * INF
        a = [x for _ in range(n)]
    else:
        x = random.randint (-INF, INF)
        a = [x for _ in range(n)]
    return [n] + a

def generate_partial_sortat (n, reale):
    a = []
    if reale:
        a = [random.random() * INF for _ in range(n)]
    else:
        a = [random.randint(-INF, INF) for _ in range(n)]

    for _ in range (n):
        idx = random.randint (0, n - 2)
        a[idx], a[idx + 1] = a[idx + 1], a[idx]
    return [n] + a


teste = [generate_random, generate_reversed_sorted, generate_sorted, generate_partial_sortat, generate_toate_egale]
nume_test = ["test_random", "test_sortat_invers", "test_sortat", "test_partial_sortat", "test_toate_egale"]

list_n = [10000]
nume_fisiere = ["tim.cpp", "RadixSort10.cpp", "quick.cpp", "shell.cpp", "merge.cpp"]

for idx, test in enumerate(teste):
    for n in list_n:
        print (f"Rulam cu n = {n}")
        for nume in nume_fisiere:
            print (f"Testul {nume_test[idx]} a rulat in ", end = " ")
            subprocess.run (f'g++ {nume}', shell = True)
            subprocess.run ("./a.out", input = ' '.join (str(x) for x in test (n, False)), text = True)
            print (f" pe {nume}")
        print ("")