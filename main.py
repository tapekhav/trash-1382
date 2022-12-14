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

    def substitute_values(self, value=0) -> float:
        return self.__a * (value ** 5) + self.__p * value + self.__q

    def derivative_value(self, value) -> float:
        return self.__a * 5 * (value ** 4) + self.__p


# quadratic equation for tests
class Eq2:
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

    def substitute_values(self, value=0) -> float:
        return self.__a * (value ** 2) + self.__p * value + self.__q

    def derivative_value(self, value) -> float:
        return self.__a * 2 * value + self.__p


# abstract class for other methods
class NumericalMethod:
    def __init__(self, equation, eps=0.001, left=None, right=None, max_count=1000):
        self._equation = equation
        self._eps = eps

        self._left = left
        self._right = right
        self._max_count = max_count

    def get_eps(self) -> float:
        return self._eps

    def _checks(self):
        self._equation.make_reduced_equation()

        if self._eps <= 0:
            raise ValueError("Неверное значение точности")
        if self._left > self._right or self._left is None or self._right is None:
            raise ValueError("Неверные значения интервалов")

    def solve_equation(self):
        pass


# Newton's method
class Newton(NumericalMethod):
    def __init__(self, equation, eps=0.001, left=None, right=None, max_count=1000):
        super().__init__(equation, eps, left, right, max_count)

    def solve_equation(self) -> float:
        super()._checks()
        k = 0

        prev_value = self._right
        cur_value = self._left

        cur_eps = abs(prev_value - cur_value)
        while cur_eps > self._eps:
            cur_value = prev_value - self._equation.substitute_values(prev_value) \
                        / self._equation.derivative_value(prev_value)

            cur_eps = abs(cur_value - prev_value)
            prev_value = cur_value

            if k > self._max_count:
                raise ValueError("Слишком много шагов")
            k += 1

        return cur_value


# Bisection method
class Bisection(NumericalMethod):
    def __init__(self, equation, eps=0.001, left=None, right=None, max_count=100000):
        super().__init__(equation, eps, left, right, max_count)

    def solve_equation(self) -> float:
        super()._checks()
        k = 0

        b = self._right
        a = self._left

        if self._equation.substitute_values(a) \
                * self._equation.substitute_values(b) > 0:
            raise ValueError("Неправильно введен интервал")

        c = (a + b) / 2
        while abs(self._equation.substitute_values(c)) > self._eps:
            if self._equation.substitute_values(a) \
                    * self._equation.substitute_values(c) < 0:
                b = c
            elif self._equation.substitute_values(b) \
                    * self._equation.substitute_values(c) < 0:
                a = c

            c = (a + b) / 2

            if k > self._max_count:
                raise ValueError("Слишком много шагов")
            k += 1

        return c


def main():
    coefficients = list(map(float, input('Введите коэффициенты уравнения: ').split()))
    eps = float(input('Введите погрешность: '))
    left, right = list(map(float, input('Введите левую и правую границы интервала: ').split()))

    equation = Eq2(*coefficients)
    solve_newton = Newton(equation, eps, left, right)
    print(solve_newton.solve_equation())

    solve_bisection = Bisection(equation, eps, left, right)
    print(solve_bisection.solve_equation())


if __name__ == '__main__':
    main()
