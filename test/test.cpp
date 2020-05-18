#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
#include <math.h>
#include <set>

int thirdBiggest(std::vector<int> arr)
{
    set<int> temp;
    temp.insert(arr.begin(), arr.end());
    arr.clear();
    arr.insert(arr.begin(), temp.begin(), temp.end());
    return arr.at(2);
}

int main()
{
    return 0;
}