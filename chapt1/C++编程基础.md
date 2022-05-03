01什么是class？

class是用户自定义的数据类型（user-defined type），增强程序内置类型抽象化层次的能力。

class分为两个部分：

- 头文件（headerfile）——用来声明class的各种操作行为。
- 程序代码文件（program text）——包含了操作行为的实现内容。

02对象初始化方式

1. =运算符

   沿袭自C语言 int num = 0

2. 构造函数法

   解决“多值初始化”的问题

   使内置类型与class类型初始化方式统一