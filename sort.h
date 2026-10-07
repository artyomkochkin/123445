#pragma once

#include "Marsh.h"
#include <algorithm>

template <class T>
void bubbleSort(
    T arr[],
    int n,
    bool (*comp)(const T&, const T&)
)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (comp(arr[j + 1], arr[j]))
            {
                std::swap(
                    arr[j],
                    arr[j + 1]
                );
            }
        }
    }
}


template <class T>
void selectionSort(
    T arr[],
    int n,
    bool (*comp)(const T&, const T&)
)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (comp(arr[j], arr[minIdx]))
            {
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            std::swap(
                arr[i],
                arr[minIdx]
            );
        }
    }
}


template <class T>
void insertionSort(
    T arr[],
    int n,
    bool (*comp)(const T&, const T&)
)
{
    for (int i = 1; i < n; i++)
    {
        T key = arr[i];

        int j = i - 1;

        while (
            j >= 0 &&
            comp(key, arr[j])
        )
        {
            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = key;
    }
}


template <class T>
void shellSort(
    T arr[],
    int n,
    bool (*comp)(const T&, const T&)
)
{
    for (
        int gap = n / 2;
        gap > 0;
        gap /= 2
    )
    {
        for (int i = gap; i < n; i++)
        {
            T temp = arr[i];

            int j;

            for (
                j = i;
                j >= gap &&
                comp(temp, arr[j - gap]);
                j -= gap
            )
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}


template <class T>
void combSort(
    T arr[],
    int n,
    bool (*comp)(const T&, const T&)
)
{
    int gap = n;

    bool swapped = true;

    const double shrink = 1.3;

    while (gap > 1 || swapped)
    {
        gap = static_cast<int>(
            gap / shrink
        );

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        for (
            int i = 0;
            i < n - gap;
            i++
        )
        {
            if (
                comp(
                    arr[i + gap],
                    arr[i]
                )
            )
            {
                std::swap(
                    arr[i],
                    arr[i + gap]
                );

                swapped = true;
            }
        }
    }
}
