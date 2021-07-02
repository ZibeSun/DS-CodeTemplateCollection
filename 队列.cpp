/*
队列queue的用法如下：
1.包含头文件：#include <queue>
2.定义一个整数队列对象：queue<int>  myQe;
3.定义一个整数队列对象数组：queue<int>  myQA[10];
4.入队操作：myQe.push(itemp); //把整数itemp进入队列
5.出队操作：myQe.pop();  //把队头元素弹出队列，注意本操作不获取队头元素
6.获取队头元素： itemp = myQe.front(); // 把队头元素放入itemp中，注意本操作不弹出元素
7.判断队列是否为空：myQe.empty();//队列空则返回true，不空则返回false
*/