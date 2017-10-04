from numpy import *
from matplotlib.pyplot import *
#figure(figsize = (6,5))
#rc('text', usetex = True)

def plotDataSets(xVals,dataSets,title = "",dataSetLabels = 0):
    if(dataSetLabels == 0):
        dataSetLabels = [""]*len(dataSets)
    for i in range(len(dataSets)):
        title(title)
        plot(xVals,dataSets[i],label = dataSetLabels[i])
    legend()
    savefig(title + ".pdf")

def getDataXUV(name):
    x = loadtxt(name + "_x.txt")
    u = loadtxt(name + "_u.txt")
    v = loadtxt(name + "_v.txt")
    relDiff = (v-u)/abs(u)
    return [[x],[u],[v],[relDiff]]

g10 = getDataXUV("general_10")
g100 = getDataXUV("general_100")
g1000 = getDataXUV("general_1000")

"""
title("Relative error")
plot(linspace(1,N-1,N),relDiff)

savefig(name + ".pdf")
clf()

relErrPlot("general_10")
relErrPlot("general_100")
relErrPlot("general_1000")

title("Numerical vs analytical calculations")
plot(x,v, label = "numerical")
plot(x,u, label = "analytical")
legend()
"""

"""
x = linspace(0,4*pi,1000)
sine = sin(x)
cosine = cos(x)
subplot(211)
plot(x,sine,label = '$\sin x$')
plot(x,cosine,label = '$\cos x$')
title('$\\sin(x)$ and $\\cos(x)$')
xlabel('x')
ylim(-1.1,1.1)
legend(loc = 'lower center')
subplot(212)
plot(x,cosine+0.5*sin(4*x),'r')
title('$\\cos x + 0.5\\sin x$')
xlabel('x')
tight_layout()
show()
"""

""" colormap
imshow([nested list])
colorbar()
"""
