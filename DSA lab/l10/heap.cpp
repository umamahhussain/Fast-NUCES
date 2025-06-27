#include<iostream>
#include<math.h>
using namespace std;

void swap(int& x, int& y) 
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap {
public:
    int* arr; 
    int capacity;
    int size; 
    
    MinHeap(int cap) 
    {
        size = 0;
        capacity = cap;
        arr = new int[cap];
    }

    int parent(int i) 
    {
        return (i - 1) / 2;
    }

    int left(int i) 
    {
        return (2 * i + 1);
    }

    int right(int i) 
    {
        return (2 * i + 2);
    }

    int getMin() {
        return arr[0];
    }

    void insertKey(int k) {
        if (size == capacity) {
            cout << "\nOverflow: Could not insert Key\n";
            return;
        }

        size++;
        int i = size - 1;
        arr[i] = k;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_val) 
    {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) 
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void linearSearch(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value NOT Found!";
    }

    // Method to remove minimum element (or root) from min heap
    int extractMin() 
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        MinHeapify(0);

        return root;
    }

    void MinHeapify(int i) 
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && arr[l] < arr[i])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            MinHeapify(smallest);
        }
    }

    void printArray() 
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int height() 
    {
        return ceil(log2(size + 1)) - 1;
    }

};

int main() {
    int s;
    cout << "Enter Size of Min Heap" << endl;
    cin >> s;
    MinHeap obj(s);
    cout << "Min Heap Created" << endl;

    int option, val;

    do {
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "INSERT Operation -" << endl;
            cout << "Enter VALUE to INSERT in HEAP: ";
            cin >> val;
            obj.insertKey(val);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH Operation -" << endl;
            cout << "Enter VALUE to SEARCH in HEAP: ";
            cin >> val;
            obj.linearSearch(val);
            break;
        case 3:
            cout << "DELETE Operation -" << endl;
            cout << "Enter INDEX of Heap Array to DELETE: ";
            cin >> val;
            obj.deleteKey(val);
            break;
        case 4:
            cout << "GET Min value : " << obj.getMin();
            cout << endl;
            break;
        case 5:
            cout << "EXTRACT Min value : " << obj.extractMin();
            cout << endl;
            break;
        case 6:
            cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
            break;

        case 7:
            cout << "PRINT Heap Array : " << endl;
            obj.printArray();

            cout << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}