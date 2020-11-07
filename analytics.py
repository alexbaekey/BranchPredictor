import numpy as np
import matplotlib.pyplot as plt
plt.ion()


#./sim smith 1 gcc_trace.txt

b = [1,2,3,4,5,6]
# 1<=b<=6
# y axis is branch misprediction rate
# x axis is b value

# GRAPH 1
# gcc_trace.txt

# misprediction rate
mispredgcc = [45.24, 43.01, 41.57, 41.68, 41.33, 41.94]
plt.plot(b,mispredgcc)
plt.title("gcc_trace, smith")
plt.xlabel('b')
plt.ylabel('branch misprediction rate')
plt.savefig('gcc_trace,smith.jpg')
plt.clf()

# GRAPH 2
# jpeg_trace.txt
mispredjpeg = [50.02, 30.98, 29.12, 28.14, 28,00, 27.94]
plt.plot(b,mispredjpeg)
plt.title("jpeg_trace, smith")
plt.xlabel('b')
plt.ylabel('branch misprediction rate')
plt.savefig('jpeg_trace,smith.jpg')
plt.clf()

# GRAPH 3
# perl_trace.txt
mispredperl = [47.66, 47.98, 48.65, 46.74, 47.55, 47.69]
plt.plot(b,mispredperl)
plt.title("perl_trace, smith")
plt.xlabel('b')
plt.ylabel('branch misprediction rate')
plt.savefig('perl_trace,smith.jpg')




