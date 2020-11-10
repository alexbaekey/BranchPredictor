import numpy as np
import matplotlib.pyplot as plt
plt.ion()


################ SMITH PREDICTOR ######################

#./sim smith 1 gcc_trace.txt

b = [1,2,3,4,5,6]
# 1<=b<=6
# y axis is branch misprediction rate
# x axis is b value

# GRAPH 1
# gcc_trace.txt
mispredgcc = [45.24, 43.01, 41.57, 41.68, 41.33, 41.94]
plt.plot(b,mispredgcc, marker='o')
plt.title("gcc_trace, smith")
plt.xlabel('b')
plt.ylabel('branch misprediction rate')
plt.grid()
plt.savefig('gcc_trace,smith.jpg')
plt.clf()

# GRAPH 2
# jpeg_trace.txt
mispredjpeg = [50.02, 30.98, 29.12, 28.14, 28.00, 27.94]
plt.plot(b,mispredjpeg, marker='o')
plt.title("jpeg_trace, smith")
plt.xlabel('b')
plt.ylabel('branch misprediction rate')
plt.grid()
plt.savefig('jpeg_trace,smith.jpg')
plt.clf()

# GRAPH 3
# perl_trace.txt
mispredperl = [47.66, 47.98, 48.65, 46.74, 47.55, 47.69]
plt.plot(b,mispredperl, marker='o')
plt.title("perl_trace, smith")
plt.xlabel('b')
plt.ylabel('branch misprediction rate')
plt.grid()
plt.savefig('perl_trace,smith.jpg')
plt.clf()


################### BIMODAL PREDICTOR ###################


m = [7,8,9,10,11,12]

# GRAPH 1
# gcc_trace.txt
misgcc = [25.72,21.66,18.00,15.33,13.46,12.30]
plt.plot(m,misgcc, marker='o')
plt.title("gcc_trace, bimodal")
plt.xlabel('m')
plt.ylabel('branch misprediction rate')
plt.grid()
plt.savefig('gcc_trace,bimodal.jpg')
plt.clf()



# GRAPH 2
# jpeg_trace.txt
misjpeg = [7.85, 7.75, 7.69, 7.65, 7.51, 7.49]
plt.plot(m,misjpeg, marker='o')
plt.title("jpeg_trace, bimodal")
plt.xlabel('m')
plt.ylabel('branch misprediction rate')
plt.grid()
plt.savefig('jpeg_trace,bimodal.jpg')
plt.clf()


# GRAPH 3
# perl_trace.txt
misperl = [20.60, 16.17, 13.79, 11.62, 10.59, 8.94]
plt.plot(m,misperl, marker='o')
plt.title("perl_trace, bimodal")
plt.xlabel('m')
plt.ylabel('branch misprediction rate')
plt.grid()
plt.savefig('perl_trace,bimodal.jpg')
plt.clf()




################### GSHARE PREDICTOR ###################


#gcc_trace




gm_n2  = [7,8,9,10,11,12]
gm_n4  = [7,8,9,10,11,12]
gm_n6  = [7,8,9,10,11,12]
gm_n8  = [8,9,10,11,12]
gm_n10 = [10,11,12]
gm_n12 = [12]


gmisn2   = [27.81, 23.56, 19.94, 16.95, 14.46, 12.53]
gmisn4   = [28.95, 24.96, 20.84, 18.00, 15.05, 13.40]
gmisn6   = [31.10, 27.53, 23.47, 19.88, 17.06, 14.47]
gmisn8   = [29.53, 25.49, 21.22, 17.75, 15.16]
gmisn10  = [22.52, 18.84, 15.69]
gmisn12  = [16.28]


plt.plot(gm_n2, gmisn2, label='n=2', marker='o')
plt.plot(gm_n4, gmisn4, label='n=4', marker='o')
plt.plot(gm_n6, gmisn6, label='n=6', marker='o')
plt.plot(gm_n8, gmisn8, label='n=8', marker='o')
plt.plot(gm_n10, gmisn10, label='n=10', marker='o')
plt.plot(gm_n12, gmisn12, label='n=12', marker='o')
plt.title("gcc_trace, gshare")
plt.xlabel('m')
plt.ylabel('branch misprediction rate')
plt.legend()
plt.grid()
plt.savefig('gcc_trace,gshare.jpg')
plt.clf()


#jpeg_trace

jm_n2  = [7,8,9,10,11,12]
jm_n4  = [7,8,9,10,11,12]
jm_n6  = [7,8,9,10,11,12]
jm_n8  = [8,9,10,11,12]
jm_n10 = [10,11,12]
jm_n12 = [12]

jmisn2   = [8.41, 8.04, 7.94, 7.87, 7.45, 7.43]
jmisn4   = [8.65, 8.20, 8.04, 7.97, 7.62, 7.60]
jmisn6   = [9.49, 8.82, 8.46, 8.37, 7.90, 7.84]
jmisn8   = [9.07, 8.32, 8.05, 7.50, 7.28]
jmisn10  = [7.98, 7.47, 7.30]
jmisn12  = [7.35]

plt.plot(jm_n2, jmisn2, label='n=2', marker='o')
plt.plot(jm_n4, jmisn4, label='n=4', marker='o')
plt.plot(jm_n6, jmisn6, label='n=6', marker='o')
plt.plot(jm_n8, jmisn8, label='n=8', marker='o')
plt.plot(jm_n10, jmisn10, label='n=10', marker='o')
plt.plot(jm_n12, jmisn12, label='n=12', marker='o')
plt.title("jpeg_trace, gshare")
plt.xlabel('m')
plt.ylabel('branch misprediction rate')
plt.legend()
plt.grid()
plt.savefig('jpeg_trace,gshare.jpg')
plt.clf()


#perl_trace

pm_n2  = [7,8,9,10,11,12]
pm_n4  = [7,8,9,10,11,12]
pm_n6  = [7,8,9,10,11,12]
pm_n8  = [8,9,10,11,12]
pm_n10 = [10,11,12]
pm_n12 = [12]

pmisn2   = [21.28, 17.47, 14.58, 11.52, 9.91, 8.83]
pmisn4   = [24.78, 19.00, 16.11, 13.19, 11.03, 9.42]
pmisn6   = [28.72, 22.63, 18.19, 13.78, 12.03, 10.00]
pmisn8   = [23.39, 17.69, 12.64, 9.29, 6.97]
pmisn10  = [13.66, 8.91, 6.42]
pmisn12  = [6.88]

plt.plot(pm_n2, pmisn2, label='n=2', marker='o')
plt.plot(pm_n4, pmisn4, label='n=4', marker='o')
plt.plot(pm_n6, pmisn6, label='n=6', marker='o')
plt.plot(pm_n8, pmisn8, label='n=8', marker='o')
plt.plot(pm_n10, pmisn10, label='n=10', marker='o')
plt.plot(pm_n12, pmisn12, label='n=12', marker='o')
plt.title("perl_trace, gshare")
plt.xlabel('m')
plt.ylabel('branch misprediction rate')
plt.legend()
plt.grid()
plt.savefig('perl_trace,gshare.jpg')
plt.clf()



