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
	//构造顺序是不变的，但每一步的实现是可变的
	//在各步的实现变化时，不影响客户端代码
	builder_->StepA();
	builder_->StepB();
	builder_->StepC();
}