from modules.runge4 import Simulation

print('F = ')
F = int(input())

print('m0 = ')
m0 = int(input())

m0 = 20000000
print('mk = ')

mk = int(input())
mk = 500000

print('alpha = ')
alpha = input()

alpha = 100000
A = Simulation(F, m0, mk, alpha)
A.start()
