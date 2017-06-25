class A
{
private:
	int privDataA;
protected:
	int protDataA;
public:
	int publicDataA;
};

class B : public A
{
public:
	void func()
	{
		int a;
		a = privDataA;	//no access
		a = protDataA;
		a = publicDataA;
	}
};

class C : private A
{
public:
	void func()
	{
		int a;
		a = privDataA;	//no access
		a = protDataA;
		a = publicDataA;
	}
};

int main()
{
	int a;
	B objB;
	
	a = objB.privDataA; // no access
	a = objB.protDataA; // no access
	a = objB.publicDataA;

	C objC;
	a = objC.privDataA; // no access
	a = objC.protDataA; // no access
	a = objC.publicDataA; // no access

	return 0;
}
