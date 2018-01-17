#pragma once

#include <memory>
class MyClass
{
public:
	MyClass();
	~MyClass();			//the destructor is declared here because if it's generate by the compiler, the impl complete type will not be available at destructor implementation
	MyClass(MyClass&&); // if the destructor is declare, themove constructor/assign isn't generatedby the compiler
	MyClass& operator = (MyClass&&);
	MyClass(const MyClass&);//can't copy a uniquePtr so default implementation won't work, instead using default implementation of Impl
	MyClass& operator = (const MyClass&);

private:
	struct Impl;		//only the declaration, it's an non complete type
	std::unique_ptr<Impl> m_impl;
};

