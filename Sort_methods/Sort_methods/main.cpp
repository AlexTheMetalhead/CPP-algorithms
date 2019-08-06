#include <iostream>
#include <ctime>

using namespace std;

double bubble_sort(int *arr, int arr_size);
double shell_sort(int *arr, int arr_size);
double choose_sort(int *arr, int arr_size);
double insertion_sort(int *arr, int arr_size);
double quick_sort_wrapp(int *arr, int arr_size);
void quick_sort_recurtion(int *arr, int left, int right);

int main()
{
    srand(time(0));

    int menu = 1,
        arr[10000];

    while (menu)
    {
        cout << "1 - bubble sort, 2 - choose sort, 3 - Shell sort, 4 - insertion sort, 5 - quick sort, 0 - exit: ";
        cin >> menu;

        for (int i = 0; i < 10000; i++)
        {
            arr[i] = -100000 + rand() % 200000;
        }

        if (menu == 1)
        {
            cout << "Sort finished in: " << bubble_sort(arr, 10000) << "s" << endl;
        }
        else if (menu == 2)
        {
            cout << "Sort finished in: " << choose_sort(arr, 10000) << "s" << endl;
        }
        else if (menu == 3)
        {
            cout << "Sort finished in: " << shell_sort(arr, 10000) << "s" << endl;
        }
        else if (menu == 4)
        {
            cout << "Sort finished in: " << insertion_sort(arr, 10000) << "s" << endl;
        }
        else if (menu == 5)
        {
            cout << "Sort finished in: " << quick_sort_wrapp(arr, 10000) << "s" << endl;
        }

    }
}

double bubble_sort(int *arr, int arr_size)
{
    long start = clock();
    int bubble_check = 0;

    for (int i = 0; i < arr_size; i++)
    {
        for (int k = 0; k < arr_size; k++)
        {
            if (arr[k] < arr[k + 1])
            {
                swap(arr[k], arr[k + 1]);
                bubble_check++;
            }
        }

        if (!bubble_check)
        {
            break;
        }
        bubble_check = 0;
    }

    long end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;

    return time;
}

double choose_sort(int *arr, int arr_size)
{
    long start = clock();

    for (int i = 0; i < arr_size; i++)
    {
        int max = i;

        for (int k = i; k < arr_size; k++)
        {
            if (arr[max] < arr[k])
            {
                max = k;
            }
        }

        swap(arr[i], arr[max]);
    }

    long end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;

    return time;
}

double shell_sort(int *arr, int arr_size)
{
    long start = clock();
    int step = arr_size / 2;

    while (step != 0)
    {
        for (int i = step; i < arr_size; i++)
        {
            int j = i;

            while (j >= step && arr[j - step] < arr[j])
            {
                swap(arr[j - step], arr[j]);
                j -= step;
            }
        }
        step /= 2;
    }

    long end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;

    return time;
}

double insertion_sort(int *arr, int arr_size)
{
    long start = clock();

    for (int i = 1; i < arr_size; i++)
    {
        int sorted_size = i;

        for (int k = 0; k < sorted_size; k++)
        {
            if (arr[i] > arr[k])
            {
                swap(arr[i], arr[k]);
            }
        }
    }

    long end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;

    return time;
}

double quick_sort_wrapp(int *arr, int arr_size)
{
    long start = clock();

    int left = 0,
        right = arr_size - 1;

    quick_sort_recurtion(arr, left, right);

    long end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;

    return time;
}

void quick_sort_recurtion(int *arr, int left, int right)
{
    // if received only 1 element
    if (right - left < 1)
    {
        return;
    }

    int pivot = (right + left) / 2,
        i = left,
        k = right;

    while (i < k)
    {
        // seatrching in left part
        while (i <= pivot)
        {
            if (arr[i] <= arr[pivot])
            {
                break;
            }
            i++;
        }
        // seatrching in right part
        while (k >= pivot)
        {
            if (arr[k] >= arr[pivot])
            {
                break;
            }
            k--;
        }

        if (i == pivot && k == pivot)
        {
            break;
        }
        else if (i == pivot)
        {
            pivot = k;
            swap(arr[i], arr[k]);
            i++;
        }
        else if (k == pivot)
        {
            pivot = i;
            swap(arr[i], arr[k]);
            k--;
        }
        else {
            swap(arr[i], arr[k]);
            i++;
            k--;
        }
    }

    // pivot is not included
    quick_sort_recurtion(arr, left, --i);
    quick_sort_recurtion(arr, ++k, right);
}
