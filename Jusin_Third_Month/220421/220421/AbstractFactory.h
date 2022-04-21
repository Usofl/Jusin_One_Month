#pragma once

template<typename T>
class AbstractFactory
{
public:
	static T* Create()
	{
		return new T;
	}
};

