#include <iostream>
#include <vector>

int knapsack(std::vector<int> values, std::vector<int> weights, int knapsack)
{
    // Create a table for memorize intermediate results
    std::vector<std::vector<int>> K(knapsack+1, std::vector<int>(values.size()+1) );

    for (int i=0; i<= knapsack; ++i)
    {
        for (int j=0; j<= values.size(); ++j)
        {
            // Start value of empty knapsack with no items
            if (i==0 || j==0) K[i][j] = 0;
            else if (weights[j-1] <= i)
            {
                // If sum of items in the knapsack includes current item is higher 
                // than with previous tried item, then use the current one
                K[i][j] = std::max(values[j-1] + K[i - weights[j-1]][j-1], K[i][j-1]);
            }
            else K[i][j] = K[i][j-1];
        }
    }

    /* Educational debug output 
    for (int i=0;i<=knapsack;++i)
    {
        std::cout << "\n";
        for (int j=0;j<=values.size();++j)
            std::cout << K[i][j] << " ";
    }*/    
    return K[knapsack][values.size()];
}

int main() {
    // Vector of items values
    std::vector<int> v = {3, 5, 3, 3, 5};
    // Vector of items weights
    std::vector<int> w = {3, 5, 3, 3, 5};

    // Our task is to get items with maximum sum of values
    // if we are restricted by knapsack maximum summary weight (10 i.e)
    auto r = knapsack(v, w, 10);
    std::cout << "\n Total sum of values in the knapsack = " << r;
}