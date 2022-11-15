from modules.Constants import Constants
from math import exp, sqrt
import matplotlib.pyplot as plt


class Rocket_stage:
    F = 0
    m = 0
    m0 = 0
    alpha = 0


class Rocket:
    count = 0
    rocket_stages = []
    v = 0
    M = 0
    s = 10


class Simulation:
    H, t = 0, 0
    const = Constants()
    rocket = Rocket()

    def __init__(self, time_lim):
        self.time_lim = time_lim

    # init stage
    def stage(self, stage1_F, stage1_m, stage1_m0, stage1_alpha) -> None:
        stage = Rocket_stage()
        stage.F = stage1_F
        stage.m = stage1_m
        stage.m0 = stage1_m0
        stage.alpha = stage1_alpha
        self.rocket.rocket_stages.append(stage)

    # method for 1 stage
    def one_stage(self, rocket_count, stage_F, stage_m, stage_m0, stage_alpha) -> None:
        self.rocket.count = rocket_count

        # init stage 1
        self.stage(stage_F, stage_m, stage_m0, stage_alpha)

        # init res M
        for i in self.rocket.rocket_stages:
            self.rocket.M += (i.m + i.m0)

    # method for 2 stages
    def two_stages(self, rocket_count, stage1_F, stage1_m, stage1_m0, stage1_alpha,
                   stage2_F, stage2_m, stage2_m0, stage2_alpha) -> None:
        self.rocket.count = rocket_count

        # init stage 1
        self.stage(stage1_F, stage1_m, stage1_m0, stage1_alpha)

        # init stage 2
        self.stage(stage2_F, stage2_m, stage2_m0, stage2_alpha)

        # init res M
        for i in self.rocket.rocket_stages:
            self.rocket.M += (i.m + i.m0)

    # method for 3 stages
    def three_stages(self, rocket_count, stage1_F, stage1_m, stage1_m0, stage1_alpha,
                     stage2_F, stage2_m, stage2_m0, stage2_alpha, stage3_F, stage3_m, stage3_m0, stage3_alpha) -> None:
        self.rocket.count = rocket_count

        # init stage 1
        self.stage(stage1_F, stage1_m, stage1_m0, stage1_alpha)

        # init stage 2
        self.stage(stage2_F, stage2_m, stage2_m0, stage2_alpha)

        # init stage 3
        self.stage(stage3_F, stage3_m, stage3_m0, stage3_alpha)

        # init res M
        for i in self.rocket.rocket_stages:
            self.rocket.M += (i.m + i.m0)

    def init_rocket(self):
        print('Введите количество ступеней ракеты')
        self.rocket.count = int(input())
        temp_count = 1
        while temp_count != self.rocket.count + 1:
            stage = Rocket_stage()
            self.init_stage(stage, temp_count)
            self.rocket.rocket_stages.append(stage)
            temp_count += 1
        for i in self.rocket.rocket_stages:
            self.rocket.M += (i.m + i.m0)

    def init_stage(self, stage, temp_count):
        print('Введите силу тяги ', temp_count, 'ступени ракеты')
        stage.F = int(input())
        print('Введите массу топлива ', temp_count, 'ступени ракеты')
        stage.m = int(input())
        print('Введите массу пустой ', temp_count, 'ступени ракеты')
        stage.m0 = int(input())
        print('Введите альфу ', temp_count, 'ступени ракеты')
        stage.alpha = int(input())

    def start(self):
        fig = plt.subplot2grid((2, 1), (0, 0), colspan=1)
        fig.set_facecolor('cyan')
        fig.set(
            title='График изменения H(t)',
            xlabel='Время t в сек',
            ylabel='Высота H в км')

        fig2 = plt.subplot2grid((2, 1), (1, 0), rowspan=1)
        fig2.set_facecolor('yellow')
        fig2.set(
            title='График изменения v(t)',
            xlabel='Время t в сек',
            ylabel='скорость v (1 = 7800 м/c)')

        while self.rocket.count != 0:
            stage = self.rocket.rocket_stages[0]
            self.rocket.M -= stage.m
            tk = self.t + stage.m / stage.alpha
            while self.t < tk:
                self.bogatsky(fig, fig2, stage)
                if self.H < 0:
                    break
            if self.rocket.count != 1:
                self.rocket.M -= stage.m0
                self.rocket.rocket_stages.pop(0)
            self.rocket.count -= 1

        self.rocket.count = 1
        tk = self.t + self.time_lim
        if self.rocket.v >= self.second_space():
            while self.t <= tk:
                self.const_v(fig, fig2)
        else:
            self.rocket.rocket_stages[0].F = 0
            while self.t <= tk:
                self.falling(fig, fig2, self.rocket.rocket_stages[0])

        plt.tight_layout()
        plt.show()

    def second_space(self):
        return sqrt(2) * sqrt(self.const.G * self.const.M / (self.const.R + self.H))

    def acceleration_of_gravity(self, temp_H):
        return self.const.G * self.const.M / (self.const.R + temp_H) ** 2

    def func(self, temp_H, stage):
        g = self.acceleration_of_gravity(temp_H)
        a = (stage.F - (self.rocket.M + stage.m) * g - self.const.c * self.rocket.s * self.rocket.count *
             self.const.ro * exp(-1 * self.const.b * temp_H) * self.rocket.v * self.rocket.v / 2) / (
                    self.rocket.M + stage.m)
        return a

    def const_v(self, ax, ax2):
        temp_H = self.H
        temp_t = self.t
        self.H = self.H + self.const.h * self.rocket.v
        self.t += self.const.h
        ax.plot((temp_t, self.t), (temp_H / 1000, self.H / 1000), color='0.1')
        ax2.plot((temp_t, self.t), (self.rocket.v / 7800, self.rocket.v / 7800), color='0.1')

    def falling(self, ax, ax2, stage):
        temp_H = self.H
        temp_t = self.t
        temp_v = self.rocket.v
        k1 = self.func(self.H, stage)
        k2 = self.func(self.H + self.const.h * 0.5 * k1, stage)
        k3 = self.func(self.H + self.const.h * 0.5 * k2, stage)
        k4 = self.func(self.H + self.const.h * k3, stage)
        self.rocket.v += (k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6) * self.const.h
        self.H = self.H + self.const.h * self.rocket.v
        self.t += self.const.h
        ax.plot((temp_t, self.t), (temp_H / 1000, self.H / 1000), color='0.1')
        ax2.plot((temp_t, self.t), (temp_v / 7800, self.rocket.v / 7800), color='0.1')

    def runge4(self, ax, ax2, stage):
        temp_H = self.H
        temp_t = self.t
        temp_v = self.rocket.v
        k1 = self.func(self.H, stage)
        k2 = self.func(self.H + self.const.h * 0.5 * k1, stage)
        k3 = self.func(self.H + self.const.h * 0.5 * k2, stage)
        k4 = self.func(self.H + self.const.h * k3, stage)
        self.rocket.v += (k1 / 6 + k2 / 3 + k3 / 3 + k4 / 6) * self.const.h
        self.H = self.H + self.const.h * self.rocket.v
        self.t += self.const.h
        stage.m -= stage.alpha * self.const.h
        if stage.m <= 0 or self.H <= 0:
            ax.scatter([self.t], [self.H / 1000], color='red')
            ax2.scatter([self.t], [self.rocket.v / 7800], color='red')
        ax.plot((temp_t, self.t), (temp_H / 1000, self.H / 1000), color='black')
        ax2.plot((temp_t, self.t), (temp_v / 7800, self.rocket.v / 7800), color='black')

    def method38(self, ax, ax2, stage):
        k1 = self.func(self.H, stage)
        temp_H = self.H
        temp_t = self.t
        temp_v = self.rocket.v
        k2 = self.func(self.H + self.const.h / 3 * k1, stage)
        k3 = self.func(self.H - self.const.h / 3 * k1 + self.const.h * k2, stage)
        k4 = self.func(self.H + self.const.h * k1 - self.const.h * k2 + self.const.h * k3, stage)
        self.rocket.v += (k1 + 3 * k2 + 3 * k3 + k4) / 8 * self.const.h / 7800
        self.H = self.H + self.const.h * self.rocket.v
        self.t += self.const.h
        stage.m -= stage.alpha * self.const.h
        if stage.m <= 0 or self.H <= 0:
            ax.scatter([self.t], [self.H / 1000], color='red')
            ax2.scatter([self.t], [self.rocket.v / 7800], color='red')
        ax.plot((temp_t, self.t), (temp_H / 1000, self.H / 1000), color='black')
        ax2.plot((temp_t, self.t), (temp_v / 7800, self.rocket.v / 7800), color='black')

    def midpoint(self, ax, ax2, stage):
        temp_H = self.H
        temp_t = self.t
        temp_v = self.rocket.v
        self.rocket.v += self.const.h * self.func(self.H + self.const.h / 2 * self.func(self.H, stage), stage) / 7800
        self.H = self.H + self.const.h * self.rocket.v
        self.t += self.const.h
        stage.m -= stage.alpha * self.const.h
        if stage.m <= 0 or self.H <= 0:
            ax.scatter([self.t], [self.H / 1000], color='red')
            ax2.scatter([self.t], [self.rocket.v / 7800], color='red')
        ax.plot((temp_t, self.t), (temp_H / 1000, self.H / 1000), color='black')
        ax2.plot((temp_t, self.t), (temp_v / 7800, self.rocket.v / 7800), color='black')

    def bogatsky(self, ax, ax2, stage) -> None:
        temp_H = self.H
        temp_t = self.t
        temp_v = self.rocket.v

        k1 = self.func(self.H, stage)
        k2 = self.func(self.H + self.const.h * 0.5 * k1, stage)
        k3 = self.func(self.H + 3 * k2 * (self.const.h / 4), stage)
        k4 = self.func(self.H + (self.const.h * k1 * 2 / 9) + (self.const.h * k2 / 3) +
                       (self.const.h * k3 * 4 / 9), stage)

        x1 = (k1 * self.const.h * 2 / 9) + (self.const.h * k2 / 3) + (self.const.h * k3 * 4 / 9)
        x2 = (self.const.h / 24) * (7 * k1 + 6 * k2 + 8 * k3 + 3 * k4)

        error = abs(x1 - x2)
        if error < 0.0001 and self.const.h * 2 <= 0.2:
            self.const.h *= 2
        else:
            self.const.h /= 1.5

        self.rocket.v += (7 * k1 + 6 * k2 + 8 * k3 + 3 * k4) * self.const.h * (1 / 24)
        self.H = self.H + self.const.h * self.rocket.v
        self.t += self.const.h
        stage.m -= stage.alpha * self.const.h
        if stage.m <= 0 or self.H <= 0:
            ax.scatter([self.t], [self.H / 1000], color='red')
            ax2.scatter([self.t], [self.rocket.v / 7800], color='red')
        ax.plot((temp_t, self.t), (temp_H / 1000, self.H / 1000), color='black')
        ax2.plot((temp_t, self.t), (temp_v / 7800, self.rocket.v / 7800), color='black')
