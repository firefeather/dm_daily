第31周工作记录
5D 20181210-20181214
本周计划
1.校准模块BUG修改，BUG版本发布
2.设置模块，常规设置功能完善开发，方案和功能，预定会议室；
3.1114项目代码优化方案输出和计划制定; 20181210
4.BUG更改；10个？

+++
20181210 mo cloud
1.1114IPU周报；ok

2.1114代码优化方案开发计划，早上；

3.新鲜血问题沟通；16：40-17：07
需要计算弹窗界面

4.校准模块发布？

5.优化方案输出计划；ok？



20181211
1.GDB调试解决版本自测死机问题，人工校准；
问题总结：没注意看编译信息，可变参数在Linux下存在问题；
warning: cannot pass objects of non-POD type 'class QString' through '...'; call will abort at runtime
DmMessageBox::question(title, mess, 3, yesBtn, noBtn, cancelBtn); // 问题函数不能在Linux下使用

移植代码到Linux下，运行总是崩溃（在windows下正常）。
调试发现问题出在下列语句：
wxString szSiteHead = wxString::Format( wxT("<Location /%s>"), file.GetName() );
查看编译记录有下列警告信息
warning: cannot pass objects of non-POD type 'class wxString' through '...'; call will abort at runtime|
提示在运行时会异常。
查找 POD type定义如下：
POD stands for Plain Old Data - that is, a struct (or class) with no members except data members. Wikipedia goes into a bit more detail and defines a POD in C++ as "A Plain Old Data Structure in C++ is an aggregate class that contains only PODS as members, has no user-defined destructor, no user-defined copy assignment operator, and no nonstatic members of pointer-to-member type."
代码更改后OK。
wxString szSiteHead = wxString::Format( wxT("<Location /%s>"), file.GetName().c_str() );

源码调试：
使用GDB加载app，将源码按照编译路径存储在设备内，添加断点，运行到断电
命令：
ist默认参数可以用show listsize来查看，如果感觉10行太多或者太少，还可以用set listsize <count>来更改。
list 还可以加上其他参数，比如：
list 5,10   显示第5行到第10行的代码；
list func   显示func函数周围的代码，显示范围和list参数有关；
list test.c:5,10  显示源文件test.c第5行到第10行的代码，一般用于调试含多个源文件的程序。
gdb 还支持字符串查找，search str，从当前行开始，向前查找含str的字符串；
reverse-search str，从当前行开始，向后查找含str的字符串。

list fileName：行号1，行号2   查看源码行号1到行号2
break 行号 添加断点
info breakpoints 查看断点信息
run，开始运行程序；
continue，程序暂停时继续运行程序的命令；
print 变量名或表达式，打印该变量或者该表达式的值。whatis 变量名或者表达式，可以显示该变量或表达式的数据类型。
print  变量=值，这种形式还可以给对应的变量赋值；类似的还有set variable 变量=值。作用和用print赋值相同。
next，继续执行下一条语句；
还有一条命令step，与之类似，不同的是，当下一条语句遇到函数调用的时候，next不会跟踪进入函数，而是继续执行下面的语句，而step命令则会跟踪进入函数内部
还有nexti和stepi命令，这两个是单步执行一条机器指令，比如(i=0;i<n;i++)这条语句需要输入多个nexti才能执行完；两个的区别和上面相同。
quit，退出gdb调试，如果调试中想要退出，可以直接输入该命令，会出现提示选择是否退出。kill命令，结束当前程序的调试，（不会退出gdb）。

2.WBS计划输出；ok

3.测试沟通版本问题；ok
自测烧录ok
发布版本A0.0.6 ok

4.UI设计和风格问题，需要工业设计提供效果图和图片资源，最迟交付2月底；
将功能完成后，输出一个基本的界面截图，给到UI设计；

5.输出设置常规设置设计方案；部分


20181212
1.设计设置方案完整输出；

2.UI设计沟通；

3.提测bug问题，校准物bug未提交禅道；

4.10:30 设置方案评审
问题较多，重做 80%

5.关于校准物校准时间判定的问题；

6.软键盘的替换问题。ok

7.framework问题解决；



20181213
1.常规设置方案完善；
100%

2.测试问题确认，校准BUG更改，人工校准，退出时取消，却把信号槽断联的问题；

3.简会，人员安排，14:00；

4.framwork源码阅读，以及类图整理完善；

5.导航栏代码编写；

6.常规设置，新框架基本功能搭建；

20181214
1.周报

2.framework

3.设置功能

4.BUG提交
