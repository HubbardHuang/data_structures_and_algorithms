/*
题目：二叉搜索树的后序遍历序列

题目描述：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

// 法一，利用“左子树 < 父亲 < 右子树”的性质
class Solution {
public:
    bool VerifySquenceOfBST(vector<int>& sequence) {
        vector<int> in_order(sequence);
        // 排序得到中序遍历序列
        sort(in_order.begin(), in_order.end());
        if (sequence.empty()) {
            return false;
        }
        return Recursive(sequence, sequence.size() - 1, in_order, 0, in_order.size() - 1);
    }
    bool Recursive(const vector<int>& seq, int post_root_index,
                   const vector<int>& in_order, int in_start_index, int in_end_index) {
        // 该子树只包含一个结点时，直接返回 true
        if (in_start_index >= in_end_index) {
            return true;
        }
        int in_root_index;
        // 寻找中序遍历序列中根结点的索引
        for (in_root_index = in_start_index; in_root_index <= in_end_index;
             in_root_index++) {
            if (in_order[in_root_index] == seq[post_root_index]) {
                break;
            }
        }
        bool result = false;
        int root = seq[post_root_index];

        int left_index = post_root_index - (in_end_index - in_root_index + 1);
        // 根位置为子树后序遍历序列的起始位置，则不存在左子树
        if (post_root_index != in_start_index) {
            if (seq[left_index] < root) { // 判断左儿子是否小于父亲
                result = true;
            } else {
                return false;
            }
        }
        int right_index = post_root_index - 1;
        // 根位置为子树后序遍历序列的终止位置，则不存在右子树
        if (in_end_index != in_root_index) {
            if (root < seq[right_index]) { // 判断右儿子是否大于父亲
                result = true;
            } else {
                return false;
            }
        }

        return Recursive(seq, left_index, in_order, in_start_index, in_root_index - 1) &&
               Recursive(seq, right_index, in_order, in_root_index + 1, in_end_index);
    }
};

// 法二，利用“正确的后续遍历序列中，在第一个比根结点大的结点与根结点之间的所有结点一定都大于根结点”的性质
class Solution {
public:
    bool VerifySquenceOfBST(vector<int>& sequence) {
        if (sequence.empty()) {
            return false;
        }
        return Recursive(sequence, 0, sequence.size() - 1);
    }

private:
    bool Recursive(const vector<int>& seq, int start_index, int end_index) {
        if (start_index >= end_index) {
            return true;
        }
        int root = seq[end_index];

        // 寻找第一个比 root 大的元素的索引，并以此划分左右子树进行递归
        int pivot = -1;
        for (int i = start_index; i < end_index; i++) {
            if (seq[i] > root) {
                pivot = i;
                break;
            }
        }

        // 第一个比根结点大的结点与根结点之间的所有结点的索引位于区间
        // [pivot + 1, end_index - 1] 内
        for (int i = pivot + 1; pivot != -1 && i < end_index; i++) {
            if (seq[i] < root) {
                return false;
            }
        }
        // 只有左子树，没有右子树
        if (pivot == -1) {
            return Recursive(seq, start_index, end_index - 1);
        }
        // 只有右子树，没有左子树
        if (pivot == start_index) {
            return Recursive(seq, start_index, end_index - 1);
        }
        // 有左子树也有右子树
        return Recursive(seq, start_index, pivot - 1) &&
               Recursive(seq, pivot, end_index - 1);
    }
};
