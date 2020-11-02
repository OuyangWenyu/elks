# 系统科学相关基础

在水文中一个很重要的数学基础就是信号与系统科学方面的内容，比如线性时不变系统的分析，卡尔曼滤波等滤波算法。

有必要在日常工作，文献阅读中注意积累相关的基础知识。

首先是卡尔曼滤波算法，将其用于校正问题在水文预报，水库调度中都是很常见的，所以这里日常记录下相关的基本原理和代码。

主要参考：

- [[易懂]如何理解那个把嫦娥送上天的卡尔曼滤波算法Kalman filter?](https://zhuanlan.zhihu.com/p/77327349)
- [图说卡尔曼滤波，一份通俗易懂的教程](https://zhuanlan.zhihu.com/p/39912633)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第一部分：概述）](https://zhuanlan.zhihu.com/p/80255855)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第二部分：数学基础背景知识补充](https://zhuanlan.zhihu.com/p/80423632)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第三部分：α−β−γ滤波器）](https://zhuanlan.zhihu.com/p/80444577)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第四部分：一维卡尔曼滤波器【上】）](https://zhuanlan.zhihu.com/p/80324653)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第四部分：一维卡尔曼滤波器【下】）](https://zhuanlan.zhihu.com/p/80555777)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第五部分：多维卡尔曼滤波器）](https://zhuanlan.zhihu.com/p/80773952)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第六部分：扩展卡尔曼滤波器【EKF】线性与非线性）](https://zhuanlan.zhihu.com/p/81021357)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第七部分：扩展卡尔曼滤波器【EKF】处理非线性问题）](https://zhuanlan.zhihu.com/p/81025326)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第七部分：扩展卡尔曼滤波器【EKF】非线性滤波器）](https://zhuanlan.zhihu.com/p/81028351)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第八部分：扩展卡尔曼滤波器【EKF】计算导数）](https://zhuanlan.zhihu.com/p/81080390)
- [图解卡尔曼滤波器，无需深厚的数学知识也易懂（第九部分：扩展卡尔曼滤波器【EKF】雅可比矩阵）](https://zhuanlan.zhihu.com/p/81083875)
- [SLAM相关](https://www.zhihu.com/column/c_1149619223558012928)
- [KalmanFilter.NET](https://www.kalmanfilter.net/default.aspx)
- [An Introduction to the Kalman Filter](http://www.cs.unc.edu/~welch/media/pdf/kalman_intro.pdf)
- [Kalman Filtering](https://academic.csuohio.edu/simond/courses/eec644/kalman.pdf)
- [FilterPy - Kalman filters and other optimal and non-optimal estimation filters in Python](https://github.com/rlabbe/filterpy)
- [How are Neural Networks and Kalman Filters related?](https://www.quora.com/How-are-Neural-Networks-and-Kalman-Filters-related)

本文件夹下关于卡尔曼滤波的部分主要基于上面的《图解卡尔曼滤波器，无需深厚的数学知识也易懂》系列，简单记录卡尔曼滤波的基本原理，后面会看情况适当补充水文水资源相关的文献阅读。这个系列主要是对 KalmanFilter.NET 教程的翻译，原教程作者是Alex Becker，一个无线技术领域的工程师，所以教程例子主要来自雷达跟踪目标领域，不过其原理是适合所有需要估计和预测的领域（比如水文预报模型）。其教程主要是三个部分：

1. 第一部分：对Kalman filter的介绍。本部分以八个数值示例为基础。不需要太多的数学知识。本教程提供了所有必要的数学背景知识，包括平均值、方差和标准差等术语。如果你愿意的话，你可以称之为“The Kalman Filter for Dummies”。在阅读了第一部分之后，你会理解卡尔曼滤波器的概念，甚至可以设计一维卡尔曼滤波器。
2. 第二部分：多维卡尔曼滤波器（矩阵表示法中的卡尔曼滤波器）。相比第一部分，这部分的多维卡尔曼滤波器较难。大多数现实的卡尔曼滤波器实现是多维的，需要线性代数的基础知识（仅矩阵运算）。本教程还提供了必要的背景知识。
3. 第三部分：高阶主题。这部分是为高阶读者写的，它需要一定的数学背景，主要是在统计领域。目前，该部分**正在规划中**。它应该包括卡尔曼滤波器的数学推导、误差传播、扩展卡尔曼滤波器、卡尔曼滤波器在不同实际应用中的实现等。

本文件夹就针对不同的部分分别记录。
