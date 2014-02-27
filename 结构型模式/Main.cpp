#include "Client.h"
#include "Adapter.h"

#include "Abstraction.h"

#include "CompanyA.h"
#include "PartA.h"
#include "PartB.h"

#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

#include "Facade.h"

#include "FlyweightFactory.h"
#include "Flyweight.h"
void DecoratorShow(Component* pc);

//适配器模式是在类已经设计好后实施
//桥接模式在设计类之前实施
//外观模式定义一个新接口
//适配器模式是复用原有的接口, 即适配器模式是使两个原有的接口协同工作, 而不是定义一个全新的接口
int main()
{
	//适配器模式：客户欲使用的功能与已有类Adaptee相同，但客户已知接口与Adaptee不同，
	//			 此时由于特殊原因无法修改Adaptee的接口，和客户使用接口的代码。
	//			 则创建一个适配接口的类Adapter，含有Adaptee的实例，接口声明为客户待使用的接口。
	//			 在Adapter实现中调用功能相同的Adaptee的方法
	Adapter a;
	Client c(&a);
	c.Do();


	//桥接模式：impl技法 抽象接口与实现分离，各自独立变化互不影响
	//			实现改变时不影响客户代码使用
	//			接口改变，功能不变时实现代码不需变化
	Abstraction abs;
	abs.Foo();
	abs.Bar();

	//组合模式：需求中是体现部分与整体层次的结构时，又希望用户可以忽略组合对象与单个对象的不同
	//		   统一地使用组合结构中的所有对象时
	//透明方式和安全方式
	PartA pa("PartA");
	PartB pb("PartB");
	CompanyA ca("rootCompany");
	ca.AddPart(&pa);
	ca.AddPart(&pb);
	ca.Display(1);

	//装饰模式：动态地给一个对象添加一些额外的额职责，就增加功能来说，装饰模式比生成子类更为灵活
	//优点：把每个要装饰的功能放在单独的类中，并让这个类包装它所要装饰的对象。因此，当需要执行特殊行为时，
	//客户代码就可以在运行时根据需要有选择地、按顺序地使用装饰功能包装对象。
	//有效地把类的核心职责和装饰功能区分开了，可以去除相关类中重复的装饰逻辑
	//装饰----当系统需要新功能的时候，是向旧的类中添加新的代码，例如：新的字段，新的方法和新的逻辑
	//这些新加的代码通常装饰了原有类的核心职责或主要行为
	ConcreteComponent cct;
	DecoratorShow(&cct);

	//外观模式:为子系统中的一组接口提供一个一致的界面,此模式定义了一个高层接口,这个接口使得这一子系统更加容易使用
	//完美体现依赖倒转, 迪米特法则
	//使用时机:
	//1.设计初期,不同的层分离,层与层之间建立外观Facade
	//2.开发阶段,子系统往往因为不断的重构演化而变得越来越复杂,增加外观可以提供一个简单的接口,减少它们之间的依赖.
	//3.维护阶段,为新系统开发一个外观类,来提供设计粗糙或高度复杂的遗留代码的比较清晰简单的接口,让新系统与Facade对象交互
	//			Facade对象与旧系统的遗留代码交互所有复杂的工作
	Facade facade;
	facade.Foo();
	facade.Bar();

	//享元模式:	如果一个应用程序使用了大量的对象,而大量的这些对象造成了很大的存储开销时就应该考虑使用;还有就是对象的大多数状态可以外部状态,
	//			如果删除对象的外部状态,那么可以用相对较少的共享对象取代很多组对象
	//例:.net中String; 休闲游戏中的棋子对象
	//缺点:使用享元模式需要维护一个记录了系统已有的所有享元的列表,本身需要耗费资源,也使系统更加复杂
	FlyweightFactory ff;
	auto f1 = ff.GetFlyweight("ABC");
	f1->Operation();
	auto f2 = ff.GetFlyweight("DEF");
	f2->Operation();
	auto f3 = ff.GetFlyweight("ABC");
	f3->Operation();

	int count = ff.GetInstanceCount();

	//代理模式：为其他对象提供一种代理以控制这个对象的访问
	//1.远程代理
	//2.虚代理
	//3.保护代理
	//4.智能指针
	//
}

//每个装饰对象的实现和如何使用这个对象分离开
//每个装饰对象只关心自己的功能，不需要关心如
//何被添加到对象链当中（由客户程序决定）
//
void DecoratorShow(Component* pc)
{
	ConcreteDecoratorA cda(pc);
	ConcreteDecoratorB cdb(&cda);
	cdb.Operation();
}