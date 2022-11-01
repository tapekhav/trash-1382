from modules.runge4 import Simulation

F = int(input('F = '))
# F = 10000000

m0 = int(input('m0 = '))
# m0 = 20000000

mk = int(input('mk = '))
# mk = 500000

alpha = int(input('alpha = '))
# alpha = 100000

A = Simulation(F, m0, mk, alpha)
A.start()
