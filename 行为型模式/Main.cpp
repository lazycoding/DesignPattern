#include "Request.h"
#include "ConcreteHandler.h"
#include "ConcreteHandlerB.h"

#include "Invoker.h"
#include "Receiver.h"
#include "ConceretCommandA.h"
#include "ConceretCommandB.h"

#include "Context.h"

#include "Aggregate.h"
#include "IEnumerator.h"
#include "IEumnerable.h"

#include "Mediator.h"
#include "ConcreteMediator.h"
#include "ConcreteColleague1.h"
#include "ConcreteColleague2.h"
#include "Colleague.h"

#include "MementoManager.h"
#include "GameRole.h"

#include "Strategy_Context.h"
#include "ConcereteStrategy2.h"
#include "ConcreteStrategy1.h"

#include "TemplateMethod_Abstract.h"
#include "ConcreteClass.h"

#include "Visitor.h"
#include "Element.h"
#include "objectstructure.h"
#include "ConcreteElementA.h"
#include "ConcreteElementB.h"
#include "ConcreteVisitor.h"

#include "subject.h"


#include <memory>
#define CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
using namespace std;

template<class T>
void IteratorDP(IEnumerable<T>* enumerable)
{
	auto enumerator = enumerable->GetEnumerator();
	while (enumerator->MoveNext())
	{
		enumerator->Current();
	}
}

int main()
{
	//1.ְ����
	//���ͻ��ύһ������ʱ,��������������ֱ����һ���������������.���ʹ�����ߺͷ����߶�û�жԷ�����ȷ��Ϣ
	//�����еĶ����Լ�Ҳ����֪�����Ľṹ.�����ְ�����ɼ򻯶�����໥����,���ǽ��豣��һ��ָ�������ߵ�����(ָ��),
	//�����豣�������еĺ�ѡ�����ߵ�����(ָ��)	
	{
		Request req(3, "type 3");
		ConcreteHandler ch;
		ConcreteHandlerB chb;
		ch.SetSuccessor(&chb);
		ch.Handle(req);
	}

	//2.����ģʽ
	//�������Ŷӻ��¼������־,�Լ�֧�ֿɳ����Ĳ�������Ϊʱ, '��Ϊ������'��'��Ϊʵ����'����Ҫ������(�ع�)����
	{
		Invoker inv;
		Receiver recver;
		inv.AddCommand(make_shared<ConceretCommandA>(&recver));
		inv.AddCommand(make_shared<ConceretCommandB>(&recver));
		inv.DoCommand();
	}

	//3.״̬ģʽ
	{
		Context ctx;		
		while (ctx.GetTime() < 10)
		{
			ctx.IncreaseTime();
			ctx.Request();
		}		
	}

	//4.������ģʽ���ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ
	{
		Aggregate ag;
		IteratorDP(&ag);
	}

	//5.������ģʽ
	//����һ��������Ҫ����ִ�У�������ɽ��������еľ��ӱ�ʾΪһ�������﷨��ʱ������ʹ��
	//���ӣ��������ģʽ�� ���ֽ�����; ����ԭ���ʷ��������﷨������
	{
		/*
		InterpreterContext ictx;
		shared_ptr<Expreesion> ex;
		vector<shared_ptr<Expression>> vec;
		while (ictx.Next())
		{
			auto ch = ictx.Current();
			switch (ch)
			{
			case 'O':
				ex = make_shared<Scale>();
				break;
			case 'C':case 'D':case'E':case'F':case'G':case'A':case'B':case'P':
				ex = make_shared<Note>();
				break;
			}
			ex.Interpret(ictx);
			vec.push_back(ex);
		}
		*/
	}

	//6.�н���ģʽ��
	//������windows��Ϣ������
	//qt�źŲۣ�slot����
	{
		ConcreteMediator cm;
		ConcreteColleague1 cc1(&cm);
		ConcreteColleague2 cc2(&cm);
		cm.SetC1(&cc1);
		cm.SetC2(&cc2);
		cc1.Send("hello c2, i'm c1.");
		cc2.Send("hello c1, i'm c2.");
	}

	//7.����¼ģʽ��
	{
		GameRole role;
		MementoManager mgr;		
		auto state = role.SaveState();
		mgr.SetRoleStateMemento(state);
		//...
		role.Dead();
		auto recovery = mgr.GetRoleStateMemento();
		role.RecoveryState(recovery);
	}

	//8.����ģʽ
	{		
		Strategy::Context ctx(make_shared<Strategy::ConcreteStrategy1>());
		//Strategy::Context ctx(make_shared<Strategy::ConcereteStrategy2>());
		ctx.GetResult();
	}

	//9.ģ�巽��
	{
		shared_ptr<templatemethod::AbstractClass> absc = make_shared<templatemethod::ConcreteClass>();
		absc->TemplateMethod();
	}


	//10.������ģʽ
	{
		visitor::ObjectStructure ojs;
		ojs.Add(make_shared<visitor::ConcreteElementA>());
		ojs.Add(make_shared<visitor::ConcreteElementB>());
		visitor::ConcreteVisitor cv;
		ojs.Accpet(&cv);
	}

	//11.�۲���ģʽ(����-���ģ�
	{
		Subject sub;
		ObserverA oa;
		ObserverB ob;
		sub.Attach(&oa);
		sub.Attach(&ob);
		cout << "\nSubject Notify..." << endl;
		sub.Notify();
		sub.Detach(&ob);
		cout << "\nSubject Notify..." << endl;
		sub.Notify();
	}
	_CrtDumpMemoryLeaks();

	return 0;
}