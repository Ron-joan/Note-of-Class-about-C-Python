from abc import ABCMeta,abstractmethod                       #由于Python没有关于抽象类的设置,所以我在这里引用第三方库来包装抽象类
                                                             #抽象类不可以被直接调用,它是一种为了被继承而创建的类
class Person(object,metaclass = ABCMeta):                    #在类的参数中添加metaclass = ABCMeta,使其成为一个抽象类
    count = 0                                                 #相当于静态变量
    def __init__(self,name = "Dish",age = 15):               #init在这里起到的是构造函数的作用
        self._name = name                                    #所有方法的第一项形参必须它所继承的类,object是被所有类继承的类
        self._age = age                                      #self是类本身,cls是包含当前类相关的信息的对象
        self.count = self.count + 1

    @classmethod                                             #@xxxxx起到了装饰器的效果
    def one(cls):                                            #@classmethod说明该函数是一种类方法,返回的类型是一个对象
        return cls("Dish",16)

    @property                                                #@property可以把一个方法变成属性调用的
    def name(self):
        print("I work!")                                     #往往用于替函数内部数据设定是否拥有只读属性
        return self._name

    @property
    def age(self):
        return self._age

    @age.setter                                             #若具有可读属性,采用@函数名.setter声明可读
    def age(self,age):
        self._age = age

    @staticmethod                                           #@staticmethod说明该函数是静态函数,只能用类名.函数名的方法来调用
    def man(age):
        if age<4:
            return 0
        else :
            return -2

    @abstractmethod                                         #@abstractmethod说该方法是抽象方法,子类不将其重写就无法调用
    def live(self):
        if(self._age<15):
            print("You are young")
        else :
            print("You are old enough to do it ")

    def __del__(self):                                      #__del__,相当于析构函数
        print("析构函数",self.count)
        self.count = self.count - 1
class Student(Person):                                      #子类的继承,Python允许多重继承,括号内填写继承父类名
    def __init__(self,name,age,sno):
        super().__init__(name,age)                          #super().__init__(xx,xx),括号内填写从父类中继承的变量
        self._sno = sno

    @property
    def sno(self):
        return self._sno

    def live(self):
        print("You should study.")


def main():
    student = Student("Dish",18,55)
    print(student.age)
    student.live()
if __name__ == '__main__':
    main()