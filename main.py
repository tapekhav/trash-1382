# Bring radical
# a*x^5 + p*x + q = 0
class Equation:
    def __init__(self, a, p, q):
        self.__a = a
        self.__p = p
        self.__q = q

        self.__interval = list()
        self.__x1 = None

    def make_reduced_equation(self) -> None:
        self.__p /= self.__a
        self.__q /= self.__a
        self.__a /= self.__a

    @staticmethod
    def substitute_values(self, value=0) -> float:
        return self.__a * (value ** 5) + self.__p * value + self.__q

    @staticmethod
    def derivative_value(self, value) -> float:
        return self.__a * 5 * (value ** 4) + self.__p


# abstract class for other methods
class NumericalMethod:
    def __init__(self, equation, eps=0.001, left=None, right=None):
        self._equation = equation
        self._eps = eps

        self._right = left
        self._left = right

    def _find_interval(self) -> None:
        val_if_0 = self._equation.substitute_values(self)

        cur_value = 1
        while cur_value != (-1) * val_if_0:
            cur_value = self._equation.substitute_values(self, cur_value)
            cur_value += 1

        self._right = cur_value
        self._left = cur_value - 1

    def get_eps(self) -> float:
        return self._eps

    def _checks(self):
        self._equation.make_reduced_equation()

        if not self._left and not self._right:
            self._find_interval()

        if self._eps <= 0:
            raise ValueError("Неверное значение точности")
        if self._left > self._right:
            raise ValueError("Неверные значения интервалов")

    def solve_equation(self):
        pass


# Newton's method
class Newton(NumericalMethod):
    def __init__(self, equation, eps=0.001, left=None, right=None):
        super().__init__(equation, eps, left, right)

    def solve_equation(self) -> float:
        prev_value = self._right
        cur_value = self._left

        cur_eps = abs(prev_value - cur_value)
        while cur_eps > self._eps:
            cur_value = prev_value - self._equation.substitute_values(prev_value) \
                        / self._equation.derivative_value(prev_value)
            cur_eps = abs(cur_value - prev_value)

            prev_value = cur_value

        return cur_value


# Bisection method
class Bisection(NumericalMethod):
    def __init__(self, equation, eps=0.001, left=None, right=None):
        super().__init__(equation, eps, left, right)

    def solve_equation(self) -> float:
        super()._checks()

        prev_value = self._right
        cur_value = self._left
        while abs(cur_value - prev_value) > self._eps:
            c = (self._left + self._right) / 2
            if self._equation.substitute_values(cur_value) \
                    * self._equation.substitute_values(c):
                prev_value = c
            else:
                cur_value = c

        return (cur_value + prev_value) / 2


def main():
    coefficients = map(int, input('Введите коэффициенты уравнения: ').split())
    eps = int(input('Введите погрешность: '))

    equation = Equation(*coefficients)
    solve_bisection = Bisection(equation, eps)
    solve_newton = Newton(equation, eps)

    print(solve_newton.solve_equation())
    print(solve_bisection.solve_equation())


if __name__ == '__main__':
    main()
