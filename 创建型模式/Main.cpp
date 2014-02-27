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

//�ͻ�����
int main()
{
	//�򵥹�������Ʒ�����ʱʹ��, ���Ų�Ʒ�����ӣ�Ϊ�˱�֤ocpԭ���ݻ�Ϊ��������
	{
		auto product = SimpleFactory::Create("ProductA");
		product->Foo();
	}
	_CrtDumpMemoryLeaks();
	//������������Ʒ��϶࣬�Ҳ�ȷ����Ʒ���Ƿ����չʱ����
	//			��������Ʒ��ʱҲ��Ҫ������Ʒ��Ĺ����࣬��չ���š�
	//			ֻ�޸Ŀͻ�����Ĺ�����ʵ���������ֵĴ��룬�����в�Ʒ��͹�������޸ķ��
	{
		shared_ptr<IFactory> factory(new FactoryB);
		auto product = factory->Create();
		product->Foo();
	}
	_CrtDumpMemoryLeaks();

	//���󹤳���ͬһ��Ʒ�Ĳ�ͬʵ�֣�����Ӱ��ͻ������ʹ��
	//���� �������ݿ���ʵ������У����ݿ��е�ÿ����Ϊ��Ʒ����Ը������ݿ����ͣ����������ʱ�Ĳ�����ͬ
	//     �����ʱ�Ĳ�����������Ʒ���࣬�����˱仯
	//
	{
		shared_ptr<AbstracFactory> absfactory(new AbsFactoryA);
		auto product = absfactory->CreateProduct();
		auto new_product = absfactory->CreateNewProduct();
		product->Foo();
		new_product->Bar();
	}
	_CrtDumpMemoryLeaks();

	//������ģʽ�������Ӷ���Ĺ��������ı�ʾ���룬����������ͬ�������е�ÿ������ı��ֲ�ͬ
	//Builder:Ϊ����һ��Product����ĸ�������ָ���ĳ���ӿ�
	//Director��һ��ʹ��Builder�ӿڵĶ���
	{
		shared_ptr<Builder> builder(new ConcreteBuilder);
		Director dtor(builder.get());
		dtor.Construct();//
		auto product = builder->GetProduct();
		product->Foo();
	}
	_CrtDumpMemoryLeaks();

	//ԭ��ģʽ���ǳ���������ƣ�
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

	//����ģʽ
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