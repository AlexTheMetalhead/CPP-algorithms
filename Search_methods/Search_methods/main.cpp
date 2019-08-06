#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

void breadth_first_search();
void breadth_first_recurtion(int graph[10][10], int vertex1, int vertex2, queue <int> route, bool *is_found);
void binary_search();
int binary_search_recurtion(int *arr, int first, int last, int num);

int main()
{
    int choise = 1;

    while(choise)
    {
        cout << "1 - breadth-first serach, 2 - binary search, 0 - exit: ";
        cin>> choise;

        if (choise == 1)
        {
            breadth_first_search();
        }
        else if (choise == 2)
        {
            binary_search();
        }
    }
}

void breadth_first_search()
{
    long start = clock();

    int graph[10][10] =
    {
        {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 0}
    };
    int vertex1, vertex2;

    cout << "Input start vertex: ";
    cin >> vertex1;
    cout << "Input vertex you want to find: ";
    cin >> vertex2;

    queue <int> route;
    bool is_found = false;

    route.push(vertex1);

    breadth_first_recurtion(graph, vertex1, vertex2, route, &is_found);

    long end = clock();

    cout << "Route from " << vertex1 << " to " << vertex2 << ": ";
    for (auto itr = route.front(); itr != route.back(); itr++)
    {
        cout << itr << " -> ";
    }

    cout << "Work time - " << (end - start) / CLOCKS_PER_SEC << endl;
}

void breadth_first_recurtion(int graph[10][10], int vertex1, int vertex2, queue <int> route, bool *is_found)
{
    if (vertex1 == vertex2)
    {
        route.push(vertex1);
        *is_found = true;
        return;
    }

    queue <int> neighbs;

    for(int i = 0; i < 10; i++)
    {
        if (graph[vertex1][i])
        {
            neighbs.push(i);
        }
    }

    for (auto itr = neighbs.front(); itr != neighbs.back(); itr++)
    {
        if (!(*is_found))
        {
            breadth_first_recurtion(graph, itr, vertex2, route, is_found);
        }
    }
}

void binary_search()
{
    // Use only sorted arrays
    int arr[10000], num;

    for (int i = 0; i < 10000; i++)
    {
        arr[i] = i;
    }

    cout << "Input number you want to find: ";
    cin >> num;

    long start = clock();

    cout << "Position of number you want to find is " << binary_search_recurtion(arr, 0, 9999, num) << endl;

    long end = clock();
    cout << "Work time - " << (end - start) / CLOCKS_PER_SEC << endl;
}

int binary_search_recurtion(int *arr, int first, int last, int num)
{
    int middle = (last + first) / 2;

    if (arr[middle] == num)
    {
        return middle;
    }
    else if (arr[middle] > num)
    {
        // Interval depends on sort direction
        binary_search_recurtion(arr, first, --middle, num);
    }
    else if (arr[middle] < num)
    {
        binary_search_recurtion(arr, ++middle, last, num);
    }
}
