class BinaryHeap{
public:
    BinaryHeap(int size);
    void insert(int data);
    int getMax();
    int extractMax();
    void printHeap();
private:
    int capacity;
    int length;
    int* arr;
    int parent(int index);
    int lchild(int index);
    int rchild(int index);
    void swap(int* num1,int* num2);
    void heapify(int index);
};