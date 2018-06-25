# 量子化学计算程序的说明-ver.01

##### 贡献人： 贺麒霖， 资治， 刘昊明， 腾达， 乔卓然， 贺鑫  
-----
## 编译和使用方法
编译方法
1. linux/unix 平台
在主目录或`./src`子目录下，使用`make`命令进行编译，使用的语言是c++， 默认的编译器是g++。 生成的可执行程序在`./src`目录下。
2. windows 平台 ： 请自行解决。

使用方法

| 参数     | 内容      | 补充     |
| ---------| -------- | -------- |
| `main -h`     | 获得使用帮助     | Text     |
| `main -d`    | 进行默认的测试计算 (计算HeH+分子)     | 测试文件位于`../test`目录     |
| `main -f [file.gjf]`  | 进行其他测试文件的测试     | 测试文件位于`../test`目录, 必须使用`.gjf`文件格式     |

可选的的测试文件位于`../test`下，包括**H.gjf**, **He.gjf**, **H2.gjf**, **HeH.gjf**, **H4.gjf**, **CH4.gjf**。使用的示例如`main -f ../test/H2.gjf`。

## 建模的类的定义的说明
#### 下面的类来自于**basic_Global.h**文件
类的关系示意图为：
```	
#################################################################  

       [ note: ----- inherit, ===== list, =-=-= inherit & list ]                
                                                                                
       Point ----- Orbital =-=-= Orbital_cgto                                   
          '                     //                                              
               '               //                                               
                    '         //                                                
                         ' Atom  =-=-=-=-= Molecule =-=-=-= System  
 
################################################################# 
``` 
从输入文件到构建计算的基组矩阵空间，使用了如下的建模结构 ： 
* Point
>属性
> 
>| 名称     | 数据类型      | 含义     |
| ---------| -------- | -------- |
| x    | integer     | 位置参数    |
| y    | integer     | 位置参数    |
| z    | integer     | 位置参数    |
| name    | string     | 代表一个点的名字， 抽象属性    |
>
>方法
> 
>| 名称     | 接受参数      | 返回类型    | 含义|
| ---------| -------- | -------- |-----|
|||||

* Orbital
(继承自Point)
>额外属性
>
>| 名称     | 数据类型      | 含义     |
| ---------| -------- | -------- |
||||
>
>额外方法
> 
>| 名称     | 接受参数      | 返回类型    | 含义|
| ---------| -------- | -------- |-----|
|||||
* Orbital_cgto
* Atom
* Molecule
* System

#### 下面的类来自于**basic_Parser.h**文件
* Task

#### 下面的类来自于**basic_Parser.h**文件
* SCFer


## 分子积分的处理(关于**basic_Integral.h**的文件说明)
可以认为使用的是助教所给的积分。当然也有我们自己写的积分，这里暂时不详细说明。(之后有时间补充)

## 自洽场程序的流程
1. _main_ read the arguments, pass to Parser(or Task object).  
2. Parser preread the file, determine how many atoms it contains. And pass to creat object.  
3. Parser read file, initialize task and system parameters.  
4. Parser deals with the modeling of basis, Creating System/Atom object, and initializing basis with coefficients 
and exponents.  
5. Pass Task to SCFer, SCFer creat the array space.  
6. Do integration of S, H, ERI integration.  
7. Geuss a density matrix P (just use H to from a P).
8. calculate Fock matrix and Fock'.
9. calculate Coefficient Matrix C'.
10. transfer C' to C.
11. calculate density matrix P and Energy E.
12. Judge whether converge of E or P, otherwise back to calculation Fock matrix again using new P.

## 对称性的应用(暂无)

## 测试与结果 
| 测试体系     | 结果 \[au\]      | Gauss09对比\[au\]  |  结论 |
| ---------| -------- | -------- |--------|
| H     | -0.42244193     | -0.4982329  | 不能解决open-shell问题|
| He     | -2.85516043     | -2.8551604  | 一 致|
| H2     | -1.11003090     | -1.1100309  | 一致 |
| HeH+   | -2.89478689     | -2.8947869  | 一致 |
| H4     | -1.80246920     | -1.7251712  | 不一致 |
| CH4    | 震荡问题       | -39.9119255 |不一致|
