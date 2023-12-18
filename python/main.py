import sys
import time
import random

sys.setrecursionlimit(1000000)

from bubblesort import bubble_sort
from mergesort import merge_sort
from quicksort import quick_sort
from selectionsort import selection_sort

def random_tab(size):
    array = []
    for i in range(size):
        array.append(random.randint(1,100))
    return array

def benchmark(fun, tab, times = 4):
    total_time = 0
    for _ in range(times):
        tabCopy = tab.copy()
        start = time.time()
        fun(tabCopy)
        elapsed = time.time()-start

        total_time += elapsed

    return total_time / times

def testAlgorithms(functions, sizes, outputCsvFilename):
    csvFile = open(outputCsvFilename, 'w')
    csvFile.write('size| algorithm')
    for key, _ in functions.items():
        csvFile.write("," + key)
    csvFile.write("\n")

    for size in sizes:
        print("Comparaison des algorithmes avec une taille de", size)
        csvFile.write(str(size))
        tab = random_tab(size)
        for key, fun in functions.items():
            time = benchmark(fun, tab, 1)
            print(key, ": ", time, " seconds")
            csvFile.write("," + str(time))
        print("\n")
        csvFile.write("\n")
        del tab

testAlgorithms({
    # "bubbleSort": bubble_sort,
    "mergeSort": merge_sort,
    "quickSort": quick_sort,
    # "selectionSort": selection_sort,
}, [10_000, 100_000, 200_000, 300_000, 400_000, 500_000, 600_000], "outputd.csv")
