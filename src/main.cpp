#include <iostream>
#include <numeric> // std::accumulate
#include "Vector.h"

int main() {
    std::cout << "=== Demonstration of Custom Vector Library ===\n\n";

    std::cout << "1. Initialization and push_back:\n";
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    std::cout << "v1: " << v1 << " (Size: " << v1.size() << ")\n\n";

    std::cout << "2. Copy Constructor:\n";
    Vector<int> v2 = v1;
    std::cout << "v2 (copied from v1): " << v2 << "\n\n";

    std::cout << "3. Copy-and-Swap Assignment Operator:\n";
    Vector<int> v3;
    v3.push_back(100);
    std::cout << "v3 before assignment: " << v3 << "\n";
    v3 = v1;
    std::cout << "v3 after assignment:  " << v3 << "\n\n";

    std::cout << "4. Linear Algebra Operations:\n";
    Vector<double> a(3);
    a[0] = 1.0; a[1] = 2.0; a[2] = 3.0;

    Vector<double> b(3);
    b[0] = 4.0; b[1] = 5.0; b[2] = 6.0;

    std::cout << "Vector a: " << a << "\n";
    std::cout << "Vector b: " << b << "\n";

    Vector<double> sum = a + b;
    std::cout << "a + b = " << sum << "\n";

    Vector<double> diff = a - b;
    std::cout << "a - b = " << diff << "\n";

    double dot_product = a * b;
    std::cout << "a * b (scalar product) = " << dot_product << "\n\n";

    std::cout << "5. Exception Handling (Dimension Mismatch):\n";
    Vector<double> c(2);
    c[0] = 1.0; c[1] = 1.0;
    try {
        std::cout << "Trying to add vector a (size 3) and vector c (size 2)...\n";
        Vector<double> invalid_sum = a + c;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected exception: " << e.what() << "\n\n";
    }

    std::cout << "6. Iterators and STL compatibility:\n";
    std::cout << "Using range-based for loop over v1: ";
    for (const auto& element : v1) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    int total_sum = std::accumulate(v1.begin(), v1.end(), 0);
    std::cout << "Sum of elements using std::accumulate: " << total_sum << "\n";

    return 0;
}