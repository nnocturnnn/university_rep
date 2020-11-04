import math
import random
import matplotlib.pyplot as plot
from scipy.signal import lfilter
import numpy as np



#1

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# c = [1, 2 ,3 , 4]
# d = [12, 3, 5, 7]
# Fs=256
# T=1
# t=np.arange(0,T,1./Fs)
# # t=t.transpose()
# lenth=max(len(a),len(b)) - 1
# tis = np.sin(2.0*np.pi*10.0*t)
# os = lfilter(c,d,tis)
# osr = lfilter(b,a,tis,np.random.rand(1,lenth))
# figure = plot.plot(t,tis,'.-',t,os,'.-',t,osr,'.-').grid()
# figure.xlim([0,0.1])
# figure.ylim([-1.5,1.5])
# figure.legend('<Вхідний сигнал>', '<Вихідний сигнал без запізнення>','<Вихідний сигнал із запізненням>')
# figure.xlabel('t,c')
# figure.ylabel('A,B')
# figure = plot.plot(t,tis,'.-',t,os,'.-',t,osr,'.-').grid()
# figure.ylim ([-1.5,1.5])
# figure.legend('<Вхідний сигнал>', '<Вихідний сигнал без запізнення>','<Вихідний сигнал із запізненням>')
# figure.xlabel('t,c')
# figure.ylabel('A,B')


#2

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# Fs=256
# T=1
# t=np.arange(0,T,1./Fs)
# lenth=max(len(a),len(b)) - 1
# tis=np.sin(2*np.pi*10*t)
# os = lfilter(b,a,tis)
# osr = lfilter(b,a,tis,np.randomrand(1,len))
# [is_max, N]=find_peaks(abs(tis))
# [os_max, N1]=find_peaks(abs(os))
# delta_t=t(N(7))-t(N1(7))
# K_u = os_max(7)/is_max(7)
# disp(['Різниця фаз ',str(delta_t)])
# disp(['Коефіціент підсилення ',str(K_u)])

#3 

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# Fs=256
# T=1
# t=np.arange(0,T,1./Fs)
# is1=sin(2*pi*3*t)
# is2=sin(2*pi*20*t)
# os1=lfilter(b,a,is1)
# os2=lfilter(b,a,is2)
# os3=lfilter(b,a,is1 + is2)
# os4=lfilter(b,a,is1*3)
# os5=3*lfilter(b,a,is1)
# subplot(2,1,1)
# plt = plot.plot(t,os3).xlabel('t,c').ylabel('А,B')
# title('Реакція ЛДС на суму двох сигналів')
# subplot(2,1,2)
# plt = plot.plot(t,os1+os2).xlabel('t,c').ylabel('А,B').title('Сума реакцій ЛДС на два сигнали')
# subplot(3,1,1)
# plt = plot.plot(t,os1).xlabel('t,c').ylabel('А,B').title('Вхідний сигнал')
# subplot(3,1,2)
# plt = plot.plot(t,os4).xlabel('t,c').ylabel('А,B').title('Реакція ЛДС на сигнал втричі більшої амплітуди ')
# subplot(3,1,3)
# plt = plot.plot(t,os5).xlabel('t,c').ylabel('А,B').title('Реакція системи на сигнал, помножена на три')
#4 

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# t=np.arange(0,29)
# imp=np.zeros(1,30)
# imp(1,1)=1
# os=lfilter(b,a,imp)
# subplot(2,1,1)
# plt = plot.stem(t,imp).xlabel('n').ylabel('А,B').title('Вхідний сигнал (одиничний імпульс)')
# subplot(2,1,2)
# plt = plot.stem(t,os).xlabel('n').ylabel('А,B').title('Вихідний сигнал (імпульсна харктеристика)')
# 5

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# imp=signal.impulse2(b,a,30)
# plt = plot.stem(imp).xlabel('n').ylabel('А,B').title('Вихідний сигнал (імпульсна харктеристика)')
# 6

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# Fs=256
# T=1
# t=np.arange(0,T,1./Fs)
# lenth=max(len(a),len(b)) - 1
# tis=np.sin(2*np.pi*10*t)
# h=signal.impulse2(b,a)
# os=np.convolve(tis,h)
# t1=np.arange(0,T,1./Fs/Fs*(length(os)-1))
# plt = plot.plot(t,tis,'.-',t1,os,'.-').grid().xlim ([0,1.1]).ylim ([-1.5,1.5]).legend('<Вхідний сигнал>', '<Вихідний сигнал >').xlabel('t,c').ylabel('A,B')
# 7

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# Fs=256
# f, h =freqz(b,a,1000,Fs)
# q=lambda f: f(abs(H)<=1)
# ans=['система послаблює сигнал при частоті від ',str(q(1)),' Гц до ',str(q(end)),' Гц']
# plt = plot.freqz(b,a,100,Fs).title ('АЧХ та ФЧХ при частоті дискретизації Fs=256 Гц')
#

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# Fs=256
# T=1
# t=t=np.arange(0,T,1./Fs)
# f, h =freqz(b,a,1000,Fs)
# Ku=abs(H)
# Fi=phase(H)
# subplot(2,1,1)
# plt = plot.plot(w,Ku).xlim([0, 130]).xlabel('f,Hz').ylabel('Ku').title('AЧХ').grid()
# subplot(2,1,2)
# plt = plot.plot(w,Fi).xlim([0, 130]).xlabel('f,Hz').ylabel('fi, rad').title('ФЧХ').grid()

#

# q=lambda f: f(abs(H)<=1)
# if :f>=0:
#     n=10000
#     Fs=256
#     a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
#     b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
#     h,f1=freqz(b,a,n,Fs)
#     N=np.round(f/f1(2))+1
#     K_u=abs(h(N))
#     fi=phase(h(N))
# else:
#     print("err")
#

# a=[1, -0.0462, -0.0071, 0, 0, -0.0333]
# b=[0.6, -0.45, 0, -0.1667, 0.3, -0.05]
# Fs=256
# t=t=np.arange(0,T,1./Fs)
# tis=square(2*pi*t*3,30)
# os=lfilter(b,a,tis)
# plt = plot.plot(t,tis,t,os).xlim([0,1.1]).ylim([-1.1,1.1]).grid().xlabel('t,c').ylabel('A,B').title('Реакція системи на послідовність прямокутних імпульсів').legend('Вхідний сигнал','Вихідний сигнал')