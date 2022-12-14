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


# TODO realize abstract class
# abstract class for other methods
class NumericalMethod:
    def __init__(self, equation, eps=0.001, left=None, right=None):
        self._equation = equation
        self._eps = eps

        self.__right = left
        self.__left = right

    def _find_interval(self) -> None:
        val_if_0 = self._equation.substitute_values(self)

        cur_value = 1
        while cur_value != (-1) * val_if_0:
            cur_value = self._equation.substitute_values(self, cur_value)
            cur_value += 1

        self.__right = cur_value
        self.__left = cur_value - 1

    def get_eps(self) -> float:
        return self._eps


# Newton's method
class Newton:
    def __init__(self, equation, eps=0.001, left=None, right=None):
        self.__equation = equation
        self.__eps = eps

        self.__right = left
        self.__left = right

    def _find_interval(self) -> None:
        val_if_0 = self.__equation.substitute_values(self)

        cur_value = 1
        while cur_value != (-1) * val_if_0:
            cur_value = self.__equation.substitute_values(self, cur_value)
            cur_value += 1

        self.__right = cur_value
        self.__left = cur_value - 1

    def get_eps(self) -> float:
        return self.__eps

    def solve_equation(self) -> float:
        self.__equation.make_reduced_equation()

        if not self.__left and not self.__right:
            self._find_interval()

        if self.__eps <= 0:
            raise ValueError("Неверное значение точности")
        if self.__left > self.__right:
            raise ValueError("Неверные значения интервалов")

        prev_value = self.__right
        cur_value = self.__left

        cur_eps = abs(prev_value - cur_value)
        while cur_eps > self.__eps:
            cur_value = prev_value - self.__equation.substitute_values(prev_value) \
                        / self.__equation.derivative_value(prev_value)
            cur_eps = abs(cur_value - prev_value)

            prev_value = cur_value

        return cur_value


# Bisection method
class Bisection:
    def __init__(self, equation, eps=0.001, left=None, right=None):
        self.__equation = equation
        self.__eps = eps

        self.__left = left
        self.__right = right

    def get_eps(self) -> float:
        return self.__eps

    def _find_interval(self) -> None:
        val_if_0 = self.__equation.substitute_values(self)

        cur_value = 1
        while cur_value != (-1) * val_if_0:
            cur_value = self.__equation.substitute_values(self, cur_value)
            cur_value += 1

        self.__right = cur_value
        self.__left = cur_value - 1

    def solve_equation(self) -> float:
        self.__equation.make_reduced_equation()

        if not self.__left and not self.__right:
            self._find_interval()

        if self.__eps <= 0:
            raise ValueError("Неверное значение точности")
        if self.__left > self.__right:
            raise ValueError("Неверные значения интервалов")

        prev_value = self.__right
        cur_value = self.__left

        while abs(cur_value - prev_value) > self.__eps:
            c = (self.__left + self.__right) / 2
            if self.__equation.substitute_values(cur_value) \
                    * self.__equation.substitute_values(c):
                prev_value = c
            else:
                cur_value = c

        return (cur_value + prev_value) / 2


def main():
    pass


if __name__ == '__main__':
    main()
