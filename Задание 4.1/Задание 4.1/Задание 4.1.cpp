#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;


/* \brief Функция создания массива
* \param row количество строк
* \param col количество стобцов
* \return пустой массив
*/
int** initializeArray(const size_t row, const size_t col);

/* \brief Функция замены элементов массива на 0
* \param row количество строк
* \param col количество стобцов
* \return преобразованный массив массив
*/
int** swapToZero(int** array, size_t row, size_t col);

/* \brief Функция заполнения массива рандомными числами
* \param row количество строк
* \param col количество стобцов
* \return Заполненный массив
*/
void randomizeArray(int** matrix, const size_t row, const size_t col, const int min, const int max);

/* \brief Функция заполнения массива мануальными числами
* \param row количество строк
* \param col количество стобцов
* \return Заполненный массив
*/
void manualInput(int** matrix, const size_t row, const size_t col);

/* \brief Функция преобразования массива в строчку
* \param row количество строк
* \param col количество стобцов
* \return Заполненный массив
*/
string arrayToString(int** matrix, const size_t row, const size_t col, const int width, const string& message = "");

/* \brief Функция проверки деления элементов массива на 3
* \param num элемент массива
* \return делится ли этот элемент на 3
*/
bool divisible(const int num);

/* \brief Функция получения нового количества столбцов
* \param row количество строк
* \param col количество стобцов
* \return новое количество столбцов
*/
size_t getNewRowSize(int** array, const size_t row, const size_t col);

/* \brief Функция создания нового массива
* \param row количество строк
* \param старый массив
* \param col количество стобцов
* \return новый массив массив
*/
int** insertRow(int** array, const size_t row, const size_t col, const size_t newCol);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    const int MIN = -99, MAX = 99, WIDTH = 3;
    size_t row, col;

    cout << "Please input matrix dimensons\nrow x col:\n ";
    cin >> row >> col;

    int** array = initializeArray(row, col);
    unsigned int mode;
    cout << "if 1 then random, if 2 then manual\t";
    cin >> mode;

    if (mode == 1)
    {
        randomizeArray(array, row, col, MIN, MAX);
    }
    else if (mode == 2)
    {
        manualInput(array, row, col);
    }
    else {
        cout << "Try again ...";
    }

    cout << arrayToString(array, row, col, WIDTH) << "\n\n";

    size_t row2 = getNewRowSize(array, row, col);

    int** array2 = insertRow(array, row, col, row2);

    swapToZero(array, row, col);

    cout << arrayToString(array, row, col, WIDTH) << "\n\n";

    cout << arrayToString(array2, row2, col, WIDTH) << "\n\n";
    return 0;
}

int** initializeArray(const size_t row, const size_t col)
{
    int** matrix = new int* [row];

    for (size_t i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    return matrix;
}

int** swapToZero(int** array, size_t row, size_t col) {

    for (size_t i = 0; i < row; i++)
    {
        int maxJ = array[0][0];
        for (size_t j = 0; j < col; j++)
        {

            if (maxJ < array[i][j]) {
                maxJ = array[i][j];

            }
        }
        for (size_t j = 0; j < col; j++)
        {

            if (maxJ == array[i][j]) {
                array[i][j] = 0;

            }
        }
    }
    return array;
}

void randomizeArray(int** matrix, const size_t row, const size_t col, const int min, const int max)
{
    srand(time(0));
    for (size_t i = 0; i < row; ++i)
        for (size_t j = 0; j < col; ++j)
            matrix[i][j] = rand() % 10;

}

void manualInput(int** matrix, const size_t row, const size_t col)
{
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
        {
            cout << "array[" << i << ", " << j << "] = ";
            cin >> matrix[i][j];
        }
}


string arrayToString(int** matrix, const size_t row, const size_t col, const int width, const string& message) //https://ravesli.com/urok-80-ukazateli-vvedenie/#toc-0
{
    std::stringstream buffer;

    buffer << message;

    for (size_t i = 0; i < row; ++i)
    {
        if (i != row && i != 0)
            buffer << "\n";

        buffer << "{";

        for (size_t j = 0; j < col; ++j)
        {
            buffer << setw(width) << matrix[i][j];
            if (j != col - 1)
                buffer << ", ";
        }

        buffer << "}";
    }

    return buffer.str();
}

bool divisible(const int num)
{
    return num % 3 == 0;
}

size_t getNewRowSize(int** array, const size_t row, const size_t col)
{
    size_t newRow = row;

    for (size_t i = 0; i < row; i++)
        if (divisible(array[i][0]))
            newRow++;

    return newRow;
}

int** insertRow(int** array, const size_t row, const size_t col, const size_t newRow)
{
    int** newArray = initializeArray(newRow, col);
    size_t rowOffset = 0;

    for (size_t i = 0; i < row; i++)
        if (divisible(array[i][0]))
        {
            for (size_t j = 0; j < col; j++)
                newArray[i + rowOffset][j] = 0;

            rowOffset++;

            for (size_t j = 0; j < row; j++)
                newArray[i + rowOffset][j] = array[i][j];
        }
        else
            for (size_t j = 0; j < row; j++)
                newArray[i + rowOffset][j] = array[i][j];

    return newArray;
}