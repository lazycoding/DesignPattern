#include "IProduct.h"
#include "SimpleFactory.h"
#include "IFactory.h"
#include "FactoryB.h"
#include "AbstracFactory.h"
#include "AbsFactoryA.h"
#include "Director.h"
#include "ConcreteBuilder.h"
#include "Cloneable.h"
#include "ProductD.h"
#include "Singleton.h"
#include <memory>
#include <iostream>
using namespace std;

#define CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


Prototype* CopyProduct(const Cloneable* cloneable)
{
	auto pt = cloneable->Clone();
	return pt;
}

//客户代码
int main()
{
	//简单工厂：产品类较少时使用, 随着产品类增加，为了保证ocp原则，演化为工厂方法
	{
		auto product = SimpleFactory::Create("ProductA");
		product->Foo();
	}
	_CrtDumpMemoryLeaks();
	//工厂方法：产品类较多，且不确定产品类是否会扩展时适用
	//			当新增产品类时也需要新增产品类的工厂类，扩展开放。
	//			只修改客户代码的工厂类实例创建部分的代码，对已有产品类和工厂类的修改封闭
	{
		shared_ptr<IFactory> factory(new FactoryB);
		auto product = factory->Create();
		product->Foo();
	}
	_CrtDumpMemoryLeaks();

	//抽象工厂：同一产品的不同实现，不会影响客户代码的使用
	//例： 多种数据库访问的需求中，数据库中的每个表为产品，针对各种数据库类型（驱动）访问表的操作不同
	//     将访问表的操作降低至产品子类，隔离了变化
	//
	{
		shared_ptr<AbstracFactory> absfactory(new AbsFactoryA);
		auto product = absfactory->CreateProduct();
		auto new_product = absfactory->CreateNewProduct();
		product->Foo();
		new_product->Bar();
	}
	_CrtDumpMemoryLeaks();

	//建造者模式：将复杂对象的构建与它的表示分离，创建过程相同，过程中的每个步骤的表现不同
	//Builder:为创建一个Product对象的各个部件指定的抽象接口
	//Director：一个使用Builder接口的对象
	{
		shared_ptr<Builder> builder(new ConcreteBuilder);
		Director dtor(builder.get());
		dtor.Construct();//
		auto product = builder->GetProduct();
		product->Foo();
	}
	_CrtDumpMemoryLeaks();

	//原型模式：深，浅拷贝（复制）
	//
	{
		ProductD pd;
		pd.Name("ProductD");
		auto pt = CopyProduct(&pd);
		auto pdd = dynamic_cast<ProductD*>(pt);
		if (pdd)
		{
			pdd->Name("Copyed");
			std::cout << pdd->Name() << endl;
			cout << pd.Name() << endl;
		}
		delete pt;
		pt = nullptr;
	}
	_CrtDumpMemoryLeaks();

	//单例模式
	{
		auto single = SingletonTest::Instance();
		single->Foo();
		{
			auto s2 = SingletonTest::Instance();
			s2->Foo();
		}
		single->Release();
	}
	_CrtDumpMemoryLeaks();

	return 0;
}