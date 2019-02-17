/*
题目：序列化二叉树

题目描述：
请实现两个函数，分别用来序列化和反序列化二叉树。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
      : val(x)
      , left(NULL)
      , right(NULL) {}
};
*/
class Solution {
private:
    int index = 0;

public:
    char* Serialize(TreeNode* node) {
        if (!node) {
            return "#,";
        }
        string curr = to_string(node->val);
        curr.push_back(',');
        char* left = Serialize(node->left);
        char* right = Serialize(node->right);

        int length = curr.size() + strlen(left) + strlen(right);
        char* result = new char[length + 1];
        result[length] = '\0';
        strcpy(result, curr.data());
        strcat(result, left);
        strcat(result, right);
        return result;
    }
    TreeNode* Deserialize(char* str) {
        if (str[index] == '#') {
            index += 2;
            return nullptr;
        }
        int num = 0;
        while (str[index] != ',' && str[index] != '\0') {
            num = num * 10 + (str[index] - '0');
            ++index;
        }
        ++index;
        TreeNode* root = new TreeNode(num);
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};