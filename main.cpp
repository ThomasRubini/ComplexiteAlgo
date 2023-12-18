#include<fstream>
#include<functional>
#include<chrono>
#include<vector>
#include<map>

#include<bubble.hpp>
#include<selection.hpp>
#include<merge.hpp>
#include<quicksort.hpp>
#include<random.hpp>

double benchmark(std::function<void(int[], int)> fun, int tab[], int size, int times = 4) {

    double totalTime = 0;
    for(int i=0; i<times; i++) {
        // copy tab
        int *tabCopy = new int[size];
        for(int j=0; j<size; j++) tabCopy[i] = tab[i];

        // execute function
        auto start = std::chrono::steady_clock::now();
        fun(tabCopy, size);
        auto end = std::chrono::steady_clock::now();

        // get results
        std::chrono::duration<double> elapsed_seconds = end-start;
        totalTime += elapsed_seconds.count();

        delete tabCopy;
    }

    return totalTime / times;   
}

void testAlgorithms(std::map<std::string, std::function<void(int[], int)>> functions, std::vector<int> sizes, std::string outputCsvFilename) {
    std::ofstream csvFile(outputCsvFilename);

    csvFile << "size| algorithm";
    for(auto [key, _] : functions) csvFile << "," << key;
    csvFile << std::endl;

    for(auto size : sizes) {
        std::cout << "Comparaison des algorithmes avec une taille de " << size << std::endl;
        csvFile << size;
        
        int *tab = new int[size];
        fill_random(tab, size);

        for(auto &[key, fun] : functions) {
            double time = benchmark(fun, tab, size);
            std::cout << key << ": " << time << " seconds" << std::endl;
            csvFile << "," << time;
        }

        std::cout << std::endl;
        csvFile << std::endl;

        delete tab;
    }
}

int main() 
{ 
    testAlgorithms({
        {"bubbleSort", bubbleSort},
        {"mergeSort", mergeSort},
        {"quickSort", quickSort},
        {"selectionSort", selectionSort},
    }, {20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000}, "output.csv");

    return 0; 
}
