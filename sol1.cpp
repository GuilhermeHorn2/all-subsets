#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void ger_subsets(std::vector<int> &v, std::vector<int> &curr, int k, std::vector<std::vector<int>> &all);

std::vector<std::vector<int>> ger_subsets(std::vector<int> &v);

int main()
{

 std::vector<int> v = {1, 2, 2};
 ger_subsets(v);

 return 0;
}

void print_list(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i];
 }
 std::cout << '\n';
}

void ger_subsets(std::vector<int> &v, std::vector<int> &curr, int k, std::vector<std::vector<int>> &all)
{
 if (k >= v.size())
 {
  // print_list(curr);
  return;
 }

 int prev = -1;
 for (int i = k; i < v.size(); i++)
 {
  if (prev == -1 || prev != v[i])
  {
   curr.push_back(v[i]);
   ger_subsets(v, curr, i + 1, all);
   all.push_back(curr);
   curr.pop_back();
   prev = v[i];
  }
 }
}

std::vector<std::vector<int>> ger_subsets(std::vector<int> &v)
{
 sort(v.begin(), v.end());
 std::vector<std::vector<int>>
     all;
 std::vector<int> curr;
 ger_subsets(v, curr, 0, all);

 for (int i = 0; i < all.size(); i++)
 {
  print_list(all[i]);
 }

 return all;
}
