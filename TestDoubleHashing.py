import matplotlib.pyplot as plt
from DoubleHashing import DoubleHashing
from TestMethod import TestMethod

# TODO method start
class TestDoubleHashing(TestMethod):
    def __init__(self, type_of_case=1, count_of_elements=10000):
        super().__init__(DoubleHashing, type_of_case, count_of_elements)

    def start(self):
        pass