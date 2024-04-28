#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std::chrono;
using namespace SortLibrary;


template<typename T>
double getBubbleSortDuration(vector<T>& v){

    // Starto il tempo
    steady_clock::time_point start = steady_clock::now();

    BubbleSort(v);

    // Fermo il tempo
    steady_clock::time_point end = steady_clock::now();

    double duration = duration_cast<nanoseconds>(end-start).count();
    return duration;
}



template<typename T>
double getMergeSortDuration(vector<T>& v){

    // Starto il tempo
    steady_clock::time_point start = steady_clock::now();

    MergeSort(v);

    // Fermo il tempo
    steady_clock::time_point end = steady_clock::now();

    double duration = duration_cast<nanoseconds>(end-start).count();
    return duration;
}

int main(int argc, char **argv) {

    unsigned int nTest = 30;
    unsigned int dim = stoi(argv[1]);

    // -------------------------------------------------
    cout << "Vettore già ordinato (decrescente):" << endl;
    double sumBubble = 0;
    double sumMerge = 0;

    double n = dim;
    vector<int> v1(dim);
    vector<int> v2(dim);
    for(unsigned int i=0; i<nTest;i++){
        // lo riscrivo per avere lo stato iniziale
        n = dim;
        generate(v1.begin(), v1.end(), [&n] () {return n--;});
        v2 = v1;

        sumBubble += getBubbleSortDuration(v1);
        sumMerge += getMergeSortDuration(v2);
    }
    double meanB = sumBubble/nTest;
    double meanM = sumMerge/nTest;
    cout << "Bubble sort average time: " << meanB << endl;
    cout << "Merge sort average time: " << meanM << endl << endl;


    // -------------------------------------------------
    cout << "Vettore già ordinato (crescente):" << endl;
    sumBubble = 0;
    sumMerge = 0;

    for(unsigned int i=0; i<nTest;i++){
        // lo riscri per avere lo stato iniziale
        n = 0;
        generate(v1.begin(), v1.end(), [&n] () {return n++;});
        v2 = v1;

        sumBubble += getBubbleSortDuration(v1);
        sumMerge += getMergeSortDuration(v2);
    }
    meanB = sumBubble/nTest;
    meanM = sumMerge/nTest;
    cout << "Bubble sort average time: " << meanB << endl;
    cout << "Merge sort average time: " << meanM << endl << endl;

    // -------------------------------------------------
    cout << "Vettore con prima metà ordinata:" << endl;
    sumBubble = 0;
    sumMerge = 0;

    for(unsigned int i=0; i<nTest;i++){
        n=1;
        generate(v1.begin(), v1.end(), [&n] () {return n++;});

        for(unsigned int j=dim-1; j>dim/2; j--){
            v1[j]=rand();
        }
        v2 = v1;

        sumBubble += getBubbleSortDuration(v1);
        sumMerge += getMergeSortDuration(v2);
    }
    meanB = sumBubble/nTest;
    meanM = sumMerge/nTest;
    cout << "Bubble sort average time: " << meanB << endl;
    cout << "Merge sort average time: " << meanM << endl << endl;

    // -------------------------------------------------
    cout << "Vettore con seconda metà ordinata:" << endl;
    sumBubble = 0;
    sumMerge = 0;

    for(unsigned int i=0; i<nTest;i++){
        n=1;
        generate(v1.begin(), v1.end(), [&n] () {return n++;});

        for(unsigned int j=1; j<=dim/2; j++){
            v1[j]=rand();
        }
        v2 = v1;

        sumBubble += getBubbleSortDuration(v1);
        sumMerge += getMergeSortDuration(v2);
    }
    meanB = sumBubble/nTest;
    meanM = sumMerge/nTest;
    cout << "Bubble sort average time: " << meanB << endl;
    cout << "Merge sort average time: " << meanM << endl << endl;


    // -------------------------------------------------
    cout << "Vettore randomico:" << endl;
    sumBubble = 0;
    sumMerge = 0;

    for(unsigned int i=0; i<nTest;i++){
        n=1;
        generate(v1.begin(), v1.end(), [] () {return rand();});
        v2 = v1;

        sumBubble += getBubbleSortDuration(v1);
        sumMerge += getMergeSortDuration(v2);
    }
    meanB = sumBubble/nTest;
    meanM = sumMerge/nTest;
    cout << "Bubble sort average time: " << meanB << endl;
    cout << "Merge sort average time: " << meanM << endl << endl;


}



