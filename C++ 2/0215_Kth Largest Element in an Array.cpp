class Heap {
private:
  vector<int> array;

public:
  int top() {
    if (array.size() == 0) {
      return -1;
    }

    return array[0];
  }

  void pop() {
    array[0] = array.back();
    array.pop_back();
    heapify(0);
  }

  void push(int num) {
    array.push_back(num);
    int index = array.size() - 1;
    while (index > 0 && array[parent(index)] < array[index]) {
      swap(array[parent(index)], array[index]),
      index = parent(index);
    }
  }

private:
  static int parent(int i) {
    return (i - 1) / 2;
  }

  static int left(int i) {
    return (i * 2) + 1;
  }

  static int right(int i) {
    return (i * 2) + 2;
  }

  void heapify(int index) {
    int maxIndex = index;
    int leftIndex = left(index);
    int rightIndex = right(index);
    if (leftIndex < array.size() && array[leftIndex] > array[maxIndex]) {
      maxIndex = leftIndex;
    }

    if (rightIndex < array.size() && array[rightIndex] > array[maxIndex]) {
      maxIndex = rightIndex;
    }

    if (maxIndex != index) {
      swap(array[index], array[maxIndex]);
      heapify(maxIndex);
    }
  }
};

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    Heap heap = Heap();
    for (int n : nums) {
      heap.push(n);
    }

    int kth = 0;
    for (int i = 0; i < k; i++) {
      kth = heap.top();
      heap.pop();
    }

    return kth;
  }
};