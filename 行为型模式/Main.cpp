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
	//1.职责链
	//当客户提交一个请求时,请求是沿链传递直至有一个具体对象负责处理它.这就使接收者和发送者都没有对方的明确信息
	//且链中的对象自己也并不知道链的结构.结果是职责链可简化对象的相互连接,它们仅需保持一个指向其后继者的引用(指针),
	//而不需保持它所有的候选接受者的引用(指针)	
	{
		Request req(3, "type 3");
		ConcreteHandler ch;
		ConcreteHandlerB chb;
		ch.SetSuccessor(&chb);
		ch.Handle(req);
	}

	//2.命令模式
	//对请求排队或记录请求日志,以及支持可撤销的操作等行为时, '行为请求者'和'行为实现者'就需要做解耦(重构)操作
	{
		Invoker inv;
		Receiver recver;
		inv.AddCommand(make_shared<ConceretCommandA>(&recver));
		inv.AddCommand(make_shared<ConceretCommandB>(&recver));
		inv.DoCommand();
	}

	//3.状态模式
	{
		Context ctx;		
		while (ctx.GetTime() < 10)
		{
			ctx.IncreaseTime();
			ctx.Request();
		}		
	}

	//4.迭代器模式：提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示
	{
		Aggregate ag;
		IteratorDP(&ag);
	}

	//5.解释器模式
	//当有一个语言需要解释执行，并且你可将该语言中的句子表示为一个抽象语法树时，可以使用
	//例子：《大话设计模式》 音乐解释器; 编译原理（词法分析，语法分析）
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

	//6.中介者模式：
	//可用于windows消息处理吗？
	//qt信号槽（slot）？
	{
		ConcreteMediator cm;
		ConcreteColleague1 cc1(&cm);
		ConcreteColleague2 cc2(&cm);
		cm.SetC1(&cc1);
		cm.SetC2(&cc2);
		cc1.Send("hello c2, i'm c1.");
		cc2.Send("hello c1, i'm c2.");
	}

	//7.备忘录模式：
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

	//8.策略模式
	{		
		Strategy::Context ctx(make_shared<Strategy::ConcreteStrategy1>());
		//Strategy::Context ctx(make_shared<Strategy::ConcereteStrategy2>());
		ctx.GetResult();
	}

	//9.模板方法
	{
		shared_ptr<templatemethod::AbstractClass> absc = make_shared<templatemethod::ConcreteClass>();
		absc->TemplateMethod();
	}


	//10.访问者模式
	{
		visitor::ObjectStructure ojs;
		ojs.Add(make_shared<visitor::ConcreteElementA>());
		ojs.Add(make_shared<visitor::ConcreteElementB>());
		visitor::ConcreteVisitor cv;
		ojs.Accpet(&cv);
	}

	//11.观察者模式(发布-订阅）
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