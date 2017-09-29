#### 写在前面

Author:S1xe

Date:2016/12/10

Email:zbl914588599@gmail.com

#### 常见复杂计算发生的复杂度

##### 样例说明

> $O(n)$
>
> 例:遍历一个数据集

##### 正文部分

1. $O(1)$      

   从一个数据集中获取第一个元素

2. $O(lg n)$

   将一个数据集分成两半,然后将分开的每一半再分成两半,以此类推

3. $O(n)$

   遍历一个数据集

4. $O(nlg  n)$

   将一个数据集分成两半,然后将分开的每一半再分成两半,以此类推,在此过程中同时遍历每一半数据

5. $O(n^2)$

   遍历一个数据集中每个元素的同时遍历另一数量级相同的数据集

6. $O(2^n)$

   为一个数据集生成其可能的所有子集

7. $O(n!)$

   为一个数据集生成其可能的所有排列组合

#### 计算时间复杂度

$$
T(n)=\begin{cases}O(1),&\text{n=1}\\kT(\frac{n}{m})+f(n),&\text{n>1}\end{cases}
$$

#####可套用如下公式
$$
if \ \  f(n)=O(1)\\
T(n)=
\begin{cases}
O({n}^{\log_{m}{k}}),&&& \text{k>1}\\
O(\log{n}),&&& \text{k=1}
\end{cases}
$$

$$
if \ \  f(n)=O(n)\\
T(n)=
\begin{cases}
O({n}^{\log_{m}{k}}),&&& \text{k>m}\\
O(n\log{n}),&&& \text{k=m}\\
O(n),&&& \text{k<m}\\
\end{cases}
$$
