#include <limits>
#include <random>


void fill_random(int tab[], int size) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    std::uniform_int_distribution<> dis(0, 1000);

    for(int i=0; i<size; i++) {
        tab[i] = dis(gen);
    }
}
