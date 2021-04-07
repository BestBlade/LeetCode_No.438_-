/* ------------------------------------------------------------------|
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	滑动窗口法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了95.41%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了99.29%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

bool check(int s[], int p[]) {
    for (int i = 0; i < 26; i++) {
        if (s[i] != p[i]) {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (p.size() > s.size()) {
        return res;
    }

    int s_cnt[26] = { 0 };
    int p_cnt[26] = { 0 };
    for (int i = 0; i < p.size(); ++i) {
        s_cnt[s[i] - 'a']++;
        p_cnt[p[i] - 'a']++;
    }
    if (check(s_cnt,p_cnt)) {
        res.emplace_back(0);
    }

    int l = 0;
    int r = p.size() - 1;

    while (r < s.size() - 1) {
        s_cnt[s[l++] - 'a']--;
        s_cnt[s[++r] - 'a']++;
        if (check(s_cnt, p_cnt)) {
            res.emplace_back(l);
        }
    }
    return res;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    findAnagrams(s, p);
}