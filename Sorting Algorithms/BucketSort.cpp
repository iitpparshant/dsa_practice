#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bucketSort(float arr[], int n)
{
  vector<vector<float>> bucket(n, vector<float>());
  float mx = arr[0];
  float mn = arr[0];
  for (int i = 1; i < n; i++)
  {
    mx = max(mx, arr[i]);
    mn = min(mn, arr[i]);
  }

  float range = (mx - mn) / n;

  for (int i = 0; i < n; i++)
  {
    int idx = (arr[i] - mn) / range;
    float diff = (arr[i] - mn) / range - idx;
    if (diff == 0 && arr[i] != mn)
    {
      bucket[idx - 1].push_back(arr[i]);
    }
    else
    {
      bucket[idx].push_back(arr[i]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (!bucket[i].empty())
    {
      sort(bucket[i].begin(), bucket[i].end());
    }
  }
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < bucket[i].size(); j++)
    {
      arr[k++] = bucket[i][j];
    }
  }
}

int main()
{
  float arr[] = {0.13, 0.45, 4.12, 0.23, 5.34, 0.25, 0.82, 0.42, 0.94, 0.17};
  int size = sizeof(arr) / sizeof(arr[0]);
  bucketSort(arr, size);
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}