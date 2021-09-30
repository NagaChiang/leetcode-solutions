class Solution {
public:
  int maxTurbulenceSize(vector<int>& arr) {
    int maxSize = 1;
    int start = 0;
    bool shouldLarger = false;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i - 1] == arr[i]) {
        start = i;
      } else if ((shouldLarger && arr[i - 1] >= arr[i])
        || (!shouldLarger && arr[i - 1] <= arr[i])) {
        start = i - 1;
        shouldLarger = arr[i - 1] < arr[i];
      }
      
      shouldLarger = !shouldLarger;
      maxSize = max(maxSize, i - start + 1);
    }

    return maxSize;
  }
};