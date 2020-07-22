class Base(object):
    def __init__(self):
        pass

    def printSubs(self) :
        for cls in Base.__subclasses__():
            print("Base subclass : ", cls.__name__)

    def getSubs(self) :
        return Base.__subclasses__()

class A(Base) :
    def __init__(self):
        super(A, self).__init__()

    def print():
        print("I am A")

class B(Base) :
    def __init__(self):
        super(B, self).__init__()

    def print():
        print("I am B")

a = A()
a.printSubs()
for iClass in a.getSubs() :
    iClass.print()

# class A(object):
#  def hello(self):
#   print("Hello A")
#
# class B(A):
#  def hello(self):
#    print("Hello B")
#
# for cls in A.__subclasses__():
#     print(cls.__name__)

