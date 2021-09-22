// Quickselect, O(n)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    srand(time(0));

    int kth = INT_MIN;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int pivot = partition(nums, low, high);
      if (pivot == k - 1) {
        kth = nums[pivot];
        break;
      }

      if (pivot > k - 1) {
        high = pivot - 1;
      } else {
        low = pivot + 1;
      }
    }

    return kth;
  }

  int partition(vector<int>& nums, int low, int high) {
    int pivot = low + (rand() % (high - low + 1));
    swap(nums[pivot], nums[high]);

    int i = low;
    for (int j = low; j < high; j++) {
      if (nums[j] >= nums[high]) {
        swap(nums[i], nums[j]);
        i++;
      }
    }

    swap(nums[i], nums[high]);

    return i;
  }
};

// Heapsort, O(nlogn)
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