# -*- coding: utf-8 -*-
"""
Created on Wed Dec 27 08:21:08 2017

@author: user
"""

import matplotlib.pyplot as plt
#绘制时间坐标轴
x=[]
y=[]
for i in range(0,7):
    x.append(i)
    y.append(1)
xp=[0,2,4,6]
yp=[1,1,1,1]
plt.plot(x,y,color='black')
plt.axis('off')
plt.plot(xp,yp,'ko')
# 在线段下方标识出时段的范围
ylabel=0.98
plt.text(-0.03,ylabel,'|')
plt.text(1.98,ylabel,'|')
xt1p=[0,2]
yt1p=[ylabel,ylabel]
plt.ylim(0.9,1.2)
plt.plot(xt1p,yt1p)
plt.text(0.9,0.96,'t-1',fontsize=18)
plt.text(1.7,1.01,'start',fontsize=16)
#在对应时段的线段上面标识出径流的表示符号
plt.text(0.7,1.01,'$Q_{t-1}$',fontsize=16)
plt.text(2.7,1.01,'$Q_t$',fontsize=16)
plt.text(4.7,1.01,'$Q_{t+1}$',fontsize=16)
plt.savefig('D:/Projects/self-study/iwre-self-study/paper/forecast-paper-investigate/timeLine.jpg')