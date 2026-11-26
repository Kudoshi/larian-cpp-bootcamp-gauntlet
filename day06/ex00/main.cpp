#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// requires v sorted ascending; returns the index of target, or -1
int binarySearch(const std::vector<int>& v, int target)
{
    int lo = 0, hi = static_cast<int>(v.size());

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int valueMid = v[mid];

        if (valueMid == target) return mid;

        if (valueMid > target)
        {
            hi = mid;

        }
        else{
            lo = mid + 1;        
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    if (argc < 1) return 0;

    int target = std::stoi(argv[1]);
    std::vector<int> items;

    for (int i = 2; i < argc; i++)
    {
        items.push_back(std::stoi(argv[i]));
    }

    std::sort(items.begin(), items.end());

    // Printing ascending

    std::cout << "sorted asc: ";

    for (const auto& item : items)
    {
        std::cout << item << " ";
    }

    int searchResult = binarySearch(items, target);

    std::sort(items.begin(), items.end(), std::greater<int>());

    

    // Printing descending

    std::cout << "\nsorted desc: ";

    for (const auto& item : items)
    {
        std::cout << item << " ";
    }

    // Print finding

    std::cout << "\nfind " << target << " -> ";

    if (searchResult == -1)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << "index " << searchResult;
    }

    std::cout << "\n";
    return 0;
};

/**
Output Example:

$ ./search 7 5 3 9 1 7
sorted asc:  1 3 5 7 9
sorted desc: 9 7 5 3 1
find 7 -> index 3
$ ./search 4 5 3 9 1 7
sorted asc:  1 3 5 7 9
sorted desc: 9 7 5 3 1
find 4 -> -1
$ ./search 42
sorted asc:
sorted desc:
find 42 -> -1
 * 
 */