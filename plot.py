from numpy import *
from matplotlib.pyplot import *
#figure(figsize = (6,5))
rc('text', usetex = True)

def plotDual(name):
    x = loadtxt(name + "_x.txt")
    u = loadtxt(name + "_u.txt")
    v = loadtxt(name + "_v.txt")
    N = len(u)
    relDiff = (v-u)/abs(u)

    subplot(211)
    title("Numerical vs analytical calculations for n=" + str(len(x)))
    plot(x,v, label = "numerical")
    plot(x,u, label = "analytical")
    legend()

    subplot(212)
    title("Relative error")
    plot(linspace(1,N-1,N),relDiff)

    savefig(name + ".pdf")
    clf()

plotDual("general_10")
plotDual("general_100")
plotDual("general_1000")

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
