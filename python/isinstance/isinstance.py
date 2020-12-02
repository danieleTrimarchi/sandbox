
class Base(object) :

    def __init__(self):
        self.__requirements__ = []

    def getRequirementListByType(self,classType):

        reqList = []
        for iReq in self.__requirements__:

            if isinstance(iReq,classType):
                # candidate for insertion. Only insert if another instance of the same class
                # is not already there
                if(isinstance(x, type(iReq)) for x in reqList):
                    reqList.append(iReq)

            reqList.extend( iReq.getRequirementListByType(classType) )

        return reqList


class A(Base):
    def __init__(self):
        super(A, self).__init__()

class Aderived(A):
    def __init__(self):
        super(Aderived, self).__init__()

class B(Base):
    def __init__(self):
        self.__requirements__ = []

class Bderived(B):
    def __init__(self):
        super(Bderived, self).__init__()
        self.__requirements__ = [Aderived(),A(),B()]

b= Bderived()
print(b.getRequirementListByType(Bderived))