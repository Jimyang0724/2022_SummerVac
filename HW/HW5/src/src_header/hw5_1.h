#pragma once

namespace Hw5_1 {
    template<typename T>
    void swap(T& , const int , const int );

    template<typename T>
    void bubbleSort(T& );

    template<typename T>
    void insertionSort(T& );

    template<typename T>
    void sort(T& vec, void (*)(T&));

    void question1(void);
}