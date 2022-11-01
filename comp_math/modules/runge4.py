from modules.Constants import Constants
from math import exp
import matplotlib.pyplot as plt


class Simulation:
    v, H, t = 0, 0, 0
    const = Constants()

    def __init__(self, F, m0, mk, alpha):
        self.F = F * 1.5
        self.m0 = m0
        self.mk = mk
        self.alpha = alpha
        self.m = self.m0 - self.alpha * self.t

    def start(self):
        tk = (self.m0 - self.mk) / self.alpha

        fig = plt.subplot2grid((2, 1), (0, 0), colspan=1)
        fig.set_facecolor('yellow')
        fig.set(xlim=[0, tk],
                ylim=[0, 30],
                title='График изменения H(t)',
                xlabel='Время t в сек',
                ylabel='Высота H в км')

        fig2 = plt.subplot2grid((2, 1), (1, 0), rowspan=1)
        fig2.set_facecolor('cyan')
        fig2.set(
                title='График изменения v(t)',
                xlabel='Время t в сек',
                ylabel='скорость v в м/сек')

        while self.t <= tk and self.v <= 1.0:
            self.runge4(fig, fig2)
        plt.tight_layout()
        plt.show()

    def func(self, temp_H):
        a = (self.F - self.m * self.const.g - self.const.c *
             self.const.ro * exp(-1 * self.const.b * temp_H) * self.v * self.v / 2) / self.m
        return a

    def runge4(self, ax, ax2):
        k1 = self.func(self.H)
        temp_H = self.H
        temp_t = self.t
        temp_v = self.v
        k2 = self.func(self.H + self.const.h * 0.5 * k1)
        k3 = self.func(self.H + self.const.h * 0.5 * k2)
        k4 = self.func(self.H + self.const.h * k3)
        self.v += (k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6) * self.const.h / 7800
        self.H = self.H + self.const.h * self.v
        self.t += self.const.h
        self.m = self.m0 - self.alpha * self.t
        ax.plot((temp_t, self.t), (temp_H, self.H), color='0.1')
        ax2.plot((temp_t, self.t), (temp_v, self.v), color='0.1')

    def method38(self, ax, ax2):
        k1 = self.func(self.H)
        temp_H = self.H
        temp_t = self.t
        temp_v = self.v
        k2 = self.func(self.H + self.const.h / 3 * k1)
        k3 = self.func(self.H - self.const.h / 3 * k1 + self.const.h * k2)
        k4 = self.func(self.H + self.const.h * k1 - self.const.h * k2 + self.const.h * k3)
        self.v += (k1 + 3 * k2 + 3 * k3 + k4) / 8 * self.const.h / 7800
        self.H = self.H + self.const.h * self.v
        self.t += self.const.h
        self.m = self.m0 - self.alpha * self.t
        ax.plot((temp_t, self.t), (temp_H, self.H), color='0.1')
        ax2.plot((temp_t, self.t), (temp_v, self.v), color='0.1')

    def midpoint(self, ax, ax2):
        temp_H = self.H
        temp_t = self.t
        temp_v = self.v
        self.v += self.const.h * self.func(self.H + self.const.h / 2 * self.func(self.H)) / 7800
        self.H = self.H + self.const.h * self.v
        self.t += self.const.h
        self.m = self.m0 - self.alpha * self.t
        ax.plot((temp_t, self.t), (temp_H, self.H), color='0.1')
        ax2.plot((temp_t, self.t), (temp_v, self.v), color='0.1')
