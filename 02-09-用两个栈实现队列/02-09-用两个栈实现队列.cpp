// 02-09-用两个栈实现队列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	return 0;
}

template<typename T> class CQueue
{
public:
	CQueue();
	~CQueue();

	void AppendTail(const T& node);
	T DeleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::AppendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::DeleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& t = stack1.top();
			stack1.pop();
			stack2.push(t);
		}
	}

	if (stack2.size() == 0)
	{
		throw new exception("队列为空，无法删除节点");
	}

	T data = stack2.top();
	stack2.pop();
	return data;
}