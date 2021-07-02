#include<iostream>
using namespace std;
const int MaxW = 9999999;  // 假设结点权值不超过9999999
// 定义huffman树结点类
class HuffNode
{
public:
    int weight;     // 权值
    char ch;        //结点字符
    int parent;     // 父结点下标
    int leftchild;  // 左孩子下标
    int rightchild; // 右孩子下标
};
// 定义赫夫曼树类
class HuffMan
{
private:
    void MakeTree();    // 建树
    // 从 1 到 pos 的位置找出权值最小的两个结点，把结点下标存在 s1 和 s2 中
    void SelectMin(int pos, int* s1, int* s2);  
public:
    int len;    // 结点数量
    int lnum;   // 叶子数量
    int f;
    HuffNode* huffTree; // 赫夫曼树，用数组表示
    string* huffCode;   // 每个字符对应的赫夫曼编码
    void MakeTree(int n, int wt[]); // 构建huffman树
    void Coding();  // 赫夫曼编码函数
    void Destroy(); // 销毁赫夫曼树
    void Decode(const string codestr);  //赫夫曼解码
};
// 构建huffman树
void HuffMan::MakeTree(int n, int wt[])
{
    // 参数是叶子结点数量和叶子权值
    // 公有函数，对外接口
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    huffCode = new string[lnum + 1];    // 位置从 1 开始计算
    // huffCode实质是个二维字符数组，第 i 行表示第 i 个字符对应的编码
    // 赫夫曼树huffTree初始化
    for (i = 1; i <= n; i++)
        huffTree[i].weight = wt[i - 1]; // 第0号不用，从1开始编号
    for (i = 1; i <= len; i++)
    {
        if (i > n) huffTree[i].weight = 0;  // 前n个结点是叶子，已经设置
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();  // 调用私有函数建树
    f = 0;
    for (int i = 0; i < n; i++)
    {
        f += wt[i];
    }
}
// 从 1 到 pos 的位置找出权值最小的两个结点，把结点下标存在 s1 和 s2 中
void HuffMan::SelectMin(int pos, int* s1, int* s2)
{
    // 找出最小的两个权值的下标
    // 函数采用地址传递的方法，找出两个下标保存在 s1 和 s2 中
    int w1, w2, i;
    w1 = w2 = MaxW;  // 初始化w1和w2为最大值，在比较中会被实际的权值替换
    *s1 = *s2 = 0;
    for (i = 1; i <= pos; i++)
    {
        // 比较过程如下：
        // 如果第 i 个结点的权值小于 w1，且第 i 个结点是未选择的结点，提示：如果第 i 结点未选择，它父亲为 0
        // 把第 w1 和 s1 保存到 w2 和 s2，即原来的第一最小值变成第二最小值
        // 把第 i 结点的权值和下标保存到 w1 和 s1，作为第一最小值
        // 否则，如果第 i 结点的权值小于 w2，且第 i 结点是未选择的结点
        // 把第 i 结点的权值和下标保存到 w2 和 s2，作为第二最小值
        if ((huffTree[i].weight < w1) && (huffTree[i].parent == 0))
        {
            w2 = w1;
            *s2 = *s1;
            w1 = huffTree[i].weight;
            *s1 = i;
        }
        else if ((huffTree[i].weight < w2) && (huffTree[i].parent == 0))
        {
            w2 = huffTree[i].weight;
            *s2 = i;
        }
    }
}
// 建树
void HuffMan::MakeTree()
{
    // 私有函数，被公有函数调用
    int i, s1, s2;
    for (i = lnum + 1; i <= len; i++)
    {
        SelectMin(i - 1, &s1, &s2);  // 找出两个最小权值的下标放入 s1 和 s2 中
        // 将找出的两棵权值最小的子树合并为一棵子树，过程包括
        // 结点 s1 和结点 s2 的父亲设为 i
        // 结点 i 的左右孩子分别设为 s1 和 s2
        // 结点 i 的权值等于 s1 和 s2 的权值和
        huffTree[s1].parent = i;
        huffTree[s2].parent = i;
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild = s2;
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
    }
}
// 销毁赫夫曼树
void HuffMan::Destroy()
{
    len = 0;
    lnum = 0;
    delete[]huffTree;
    delete[]huffCode;
}
// 赫夫曼编码
void HuffMan::Coding()
{
    string code; // 存储符号的不定长二进制编码
    int i, j, k, parent;
    for (i = 1; i <= lnum; i++)
    { // 从叶子结点出发
        j = i;
        code = ""; // 初始化为空
        while (huffTree[j].parent != 0) { // 往上找到根结点
            parent = huffTree[j].parent; // 父结点
            if (j == huffTree[parent].leftchild) // 如果是左孩子，则记为0
                code += "0";
            else // 右孩子，记为1
                code += "1";
            j = parent; // 上移到父结点
        }
        // 编码要倒过来：因为是从叶子往上走到根，而编码是要从根走到叶子结点
        for (k = (int)code.size() - 1; k >= 0; k--)
            huffCode[i] += code[k]; // 保存编码
    }
}
//赫夫曼解码
void HuffMan::Decode(const string codestr)
{
    string txtstr;
    int c = len;
    char error_recode = '0';
    txtstr = "";
    for (int i = 0; i < codestr.length(); i++)
    {
        if (codestr[i] == '0')
        {
            c = huffTree[c].leftchild;
        }
        else if (codestr[i] == '1')
        {
            c = huffTree[c].rightchild;
        }
        else
        {
            cout << "error" << endl;
            return;
        }
        if (huffTree[c].ch == '0')
        {
            error_recode = '0';
        }
        else
        {
            txtstr += huffTree[c].ch;
            error_recode = huffTree[c].ch;
            c = len;
        }
    }
    if (error_recode == '0')
        cout << "error" << endl;
    else
        cout << txtstr << endl;
    return;
}