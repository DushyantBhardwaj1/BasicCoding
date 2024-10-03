#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<vector<int>> &answer, int index)
{
    if (index >= nums.size())
    {
        answer.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, answer, index + 1);
        swap(nums[index], nums[j]);
    }
}
int main()
{
    int n;
    cout << "Enter Size of Array";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int index = 0;
    vector<vector<int>> answer;
    solve(arr, answer, index);
    cout << "[";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
            if (j != answer[i].size() - 1)
                cout << ",";
        }
        cout << "}";
        if (i != answer.size() - 1)
            cout << ",";
    }
    cout<<"]";
}