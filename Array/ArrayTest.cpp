#include "Array.hpp"    // For Array<T>
#include <cassert>      // For assert
#include <iostream>     // For console output

using std::cout;

void TestDefaultCtor() {
  cout << "\n\n*** Testing Default Constructor \n";

  Array<int> a{};
  assert(a.IsEmpty());
  assert(a.Size() == 0);

  Array<double> x{};
  assert(x.IsEmpty());
  assert(x.Size() == 0);

  cout << " Array objects correctly default-constructed.\n";
}

void TestCopyCtor() {
  cout << "\n\n*** Testing Copy Constructor \n";

  Array<int> a{3};
  assert(! a.IsEmpty());
  assert(a.Size() == 3);
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  Array<int> b = a;
  assert(! b.IsEmpty());
  assert(b.Size() == a.Size());
      
  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';

  b[1] = 100;
  cout << "\n b[1] = 100; \n\n";

  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';
}

void TestSwap() {
  cout << "\n\n*** Testing Swap \n";

  Array<int> a{3};
  assert(! a.IsEmpty());
  assert(a.Size() == 3);
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  Array<int> b{2};
  assert(! b.IsEmpty());
  assert(b.Size() == 2);
  b[0] = 100;
  b[1] = 200;

  cout << " --- Before swap:\n";
  cout << "  a = " << a << '\n';
  cout << "  b = " << b << '\n';

  swap(a, b);
  
  cout << "\n --- After swap:\n";
  cout << "  a = " << a << '\n';
  cout << "  b = " << b << '\n';
}

void TestAssignmentOperator() {
  cout << "\n\n*** Testing Assignment Operator \n";

  Array<int> a{3};
  assert(!a.IsEmpty());
  assert(a.Size() == 3);
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  cout << " a = " << a << '\n';

  Array<int> b{};
  b = a;
  assert(!b.IsEmpty());
  assert(b.Size() == a.Size());

  cout << "\n b = a; \n\n";

  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';
}

void TestBoundsChecking() {
  cout << "\n\n*** Testing Bounds Checking \n";

  Array<int> a{3};
  assert(! a.IsEmpty());
  assert(a.Size() == 3);
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;
  
  try {
    // Attempt writing outside array boundaries on purpose
    cout << " Trying to access memory outside array boundaries... \n";
    a[100] = 64;

    // Catch the expected exception
  } catch (const IndexOutOfBoundsException& e) {
    cout << " IndexOutOfBoundsException correctly caught!\n";
  }
}

void TestLinearSearch() {
  cout << "\n\n*** Testing Linear Search \n";

  Array<int> a{5};
  a[0] = 5;
  a[1] = 2;
  a[2] = 3;
  a[3] = 1;
  a[4] = 4;

  cout << " a = " << a << '\n';

  int index = a.LinearSearch(a, 0, a.Size(), 14);
  assert(index == -1);

  index = a.LinearSearch(a, 0, a.Size(), -14);
  assert(index == -1);

  index = a.LinearSearch(a, 0, a.Size(), 3);
  assert(index == 2);

  index = a.LinearSearch(a, 2, a.Size() -1, 2);
  assert(index == -1);

  index = a.LinearSearch(a, 2, a.Size(), 4);
  assert(index == 4);  

  try {
    int index = a.LinearSearch(a, -1, a.Size(), 4);
  }
  catch (const IndexOutOfBoundsException& e) {
        cout << " IndexOutOfBoundsException correctly caught!\n";
  }

  try {
    int index = a.LinearSearch(a, 0, 400, 4);
  }
  catch (const IndexOutOfBoundsException& e) {
        cout << " IndexOutOfBoundsException correctly caught!\n";
  }

  try {
    int index = a.LinearSearch(a, 400, a.Size(), 4);
  }
  catch (const IndexOutOfBoundsException& e) {
        cout << " IndexOutOfBoundsException correctly caught!\n";
  }

  try {
    int index = a.LinearSearch(a, 0, -1, 4);
  }
  catch (const IndexOutOfBoundsException& e) {
        cout << " IndexOutOfBoundsException correctly caught!\n";
  }

}

void TestBinarySearch() {
  cout << "\n\n*** Testing Binary Search \n";
  Array<int> a{5};
  a[0] = 5;
  a[1] = 2;
  a[2] = 3;
  a[3] = 1;
  a[4] = 4;

  cout << " a = " << a << '\n';

  int index = a.BinarySearch(a, 14);
  assert(index == -1);

  index = a.BinarySearch(a, -14);
  assert(index == -1);

  index = a.BinarySearch(a, 3);
  assert(index == 2);

  index = a.BinarySearch(a, 2);
  assert(index == 1);

  index = a.BinarySearch(a, 4);
  assert(index == 3);  
}

void TestBubbleSort() {
  cout << "\n\n*** Testing Bubble Sort \n";

  Array<int> a{5};
  a[0] = 5;
  a[1] = 2;
  a[2] = 3;
  a[3] = 1;
  a[4] = 4;

    cout << "\n\n*** Before Bubble Sorting \n";
  cout << " a = " << a << '\n';

  Array b = a.BubbleSort(a);

  cout << "\n\n*** After Bubble Sorting \n";
  cout << " b = " << b << '\n';

  assert(b[0] == 1);
  assert(b[1] == 2);
  assert(b[2] == 3);
  assert(b[3] == 4);
  assert(b[4] == 5);
}

int main() {
  cout << '\n';
  cout << "=========================================== \n";
  cout << "*** Testing the Array<T> Class Template *** \n";
  cout << "=========================================== \n\n";

  TestDefaultCtor();
  TestCopyCtor();
  TestSwap();
  TestAssignmentOperator();
  TestBoundsChecking();
  TestLinearSearch();
  TestBubbleSort();
  TestBinarySearch();
};