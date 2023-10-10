# C++ methods cheating sheet

* 树节点定义

  ```c++
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  ```

```c++
		auto t1 = new TreeNode(1);
    auto t2 = new TreeNode(2);
    auto t3 = new TreeNode(3);
    auto t4 = new TreeNode(4);
    auto t5 = new TreeNode(5);
    auto t6 = new TreeNode(6);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;

```

- Designed and implemented a robust and scalable backend using Spring Boot, leveraging Spring MVC for RESTful API development.
- Utilized Spring Security to enhance project functionality.
- Integrated REST API to extend project capabilities and improve user experience.
- Implemented database models and queries using MySQL to efficiently store and retrieve data.
- Employed  Hibernate for the frontend to create a responsive and interactive user interface.



* **vector 求和**

  ```c++
  #include <numeric>
  vector<int> dp(total+1, 1);
  accumulate(dp.begin(), dp.end(), 0);
  ```

  

* **vector根据某种条件排序**

```c++
vector<int> ans;
    sort(alphabet.begin(), alphabet.end(), [&](const struct character& a, const struct character& b)->bool{
        return a.start<b.start;
    });
```



* **reinterpret_cast**

```c++
#include <iostream>
#include<string>
using namespace std;

int main() {
    int n = 10000;
    int* pi = &n;
    char* pc = reinterpret_cast<char *> (pi);
    string s(pc);
    int* p2 = reinterpret_cast<int *>(pc);
    cout << s<< endl;
    cout << *p2;
    return 0;
}

```

**out put:**

```c++
'
10000
```



* **vector求和、找最大最小值**

```c++

#include <algorithm>

vector<int> assignments(M);
        for(int j=0; j<M; ++j){
            cin >> assignments[j];
        }

accumulate(assignments.begin(), assignments.end(), 0) 
  *min_element(assignments.begin(), assignments.end())
  *max_element(STotalList.begin(), STotalList.end())
```

* **向上取整**

```c++
#include <cmath>

ceil( double )
```

* 链表定义


  ```c++
  struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       explicit ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ```

  
