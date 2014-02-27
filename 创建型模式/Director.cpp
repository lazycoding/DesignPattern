#include "Director.h"
#include "Builder.h"

Director::Director(Builder* builder) :builder_(builder)
{
}


Director::~Director()
{
}

void Director::Construct()
{
	//����˳���ǲ���ģ���ÿһ����ʵ���ǿɱ��
	//�ڸ�����ʵ�ֱ仯ʱ����Ӱ��ͻ��˴���
	builder_->StepA();
	builder_->StepB();
	builder_->StepC();
}