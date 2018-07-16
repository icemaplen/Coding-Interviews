// 02-09-用两个队列实现栈.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


template<typename T> class CStack
{
public:
	CStack();
	~CStack();

	void AppendTail(const T& node);
	T DeleteHead();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T> void CStack<T>::AppendTail(const T& element)
{
	if (queue1.size() == 0 && queue2.size() == 0)
	{
		queue1.push(element);
	}
	else if (queue1.size() > 0)
	{
		queue1.push(element);
	}
	else
	{
		queue2.push(element);
	}
}

template<typename T> T CStack<T>::DeleteHead()
{
	if (queue1.size() > 0)
	{
		while (queue1.size()>1)
		{
			T t = queue1.front();
			queue1.pop();
			queue2.push(t);
		}

		T data = queue1.front();
		queue1.pop();
		return data;
	}
	else if (queue2.size()>0)
	{
		while (queue2.size() > 1)
		{
			T t = queue2.front();
			queue2.pop();
			queue1.push(t);
		}

		T data = queue2.front();
		queue2.pop();
		return data;
	}
	else
	{
		throw new exception("栈为空，无法删除节点");
	}
	}
}