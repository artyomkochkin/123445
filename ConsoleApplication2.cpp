#define _CRT_SECURE_NO_WARNINGS

#include "Marsh.h"
#include "sort.h"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>
#include <windows.h>
#include <fstream>
#include <cstdlib>

void fixConsoleEncoding()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");
}

void readFromTextFile(
    const char* filename,
    Marsh arr[],
    int size
)
{
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Ошибка открытия файла "
                  << filename << std::endl;

        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        if (!(file >> arr[i]))
        {
            std::cerr << "Ошибка чтения данных из файла!"
                      << std::endl;

            file.close();
            exit(1);
        }
    }

    file.close();
}

void writeToBinaryFile(
    const char* filename,
    Marsh arr[],
    int size
)
{
    FILE* file = fopen(filename, "wb");

    if (!file)
    {
        std::cerr << "Ошибка открытия бинарного файла!"
                  << std::endl;

        exit(1);
    }

    fwrite(
        arr,
        sizeof(Marsh),
        size,
        file
    );

    fclose(file);
}

void readFromBinaryFile(
    const char* filename,
    Marsh arr[],
    int size
)
{
    FILE* file = fopen(filename, "rb");

    if (!file)
    {
        std::cerr << "Ошибка открытия бинарного файла!"
                  << std::endl;

        exit(1);
    }

    size_t readCount = fread(
        arr,
        sizeof(Marsh),
        size,
        file
    );

    if (readCount != static_cast<size_t>(size))
    {
        std::cerr << "Прочитано "
                  << readCount
                  << " элементов вместо "
                  << size
                  << std::endl;
    }

    fclose(file);
}

void printByDestination(
    Marsh arr[],
    int size,
    const char* dest
)
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (std::strcmp(arr[i].name2, dest) == 0)
        {
            std::cout << arr[i] << std::endl;

            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Нет маршрутов, следующих в пункт "
                   << dest
                   << std::endl;
    }
}

int main()
{
    fixConsoleEncoding();

    const int SIZE = 8;

    Marsh marshes[SIZE];

    readFromTextFile(
        "text.txt",
        marshes,
        SIZE
    );

    std::cout << "Исходные данные:"
              << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << marshes[i]
                  << std::endl;
    }

    insertionSort(
        marshes,
        SIZE,
        Marsh::compareNumber
    );

    // Другие варианты сортировки:

    // bubbleSort(
    //     marshes,
    //     SIZE,
    //     Marsh::compareNumber
    // );

    // selectionSort(
    //     marshes,
    //     SIZE,
    //     Marsh::compareNumber
    // );

    // shellSort(
    //     marshes,
    //     SIZE,
    //     Marsh::compareNumber
    // );

    // combSort(
    //     marshes,
    //     SIZE,
    //     Marsh::compareNumber
    // );

    std::cout << "\nПосле сортировки:"
              << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << marshes[i]
                  << std::endl;
    }

    writeToBinaryFile(
        "marsh.bin",
        marshes,
        SIZE
    );

    std::cout << "\nМассив записан в marsh.bin"
              << std::endl;

    Marsh marshesFromBin[SIZE];

    readFromBinaryFile(
        "marsh.bin",
        marshesFromBin,
        SIZE
    );

    std::cout << "\nДанные из бинарного файла:"
              << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << marshesFromBin[i]
                  << std::endl;
    }

    char dest[20];

    std::cout << "\nВведите пункт назначения: ";

    std::cin >> dest;

    std::cout << "Маршруты, следующие в "
              << dest
              << ":"
              << std::endl;

    printByDestination(
        marshesFromBin,
        SIZE,
        dest
    );

    return 0;
}
