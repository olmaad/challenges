// "Printer" task solution (https://ideone.com/EHRbtp)
// by Oleg Malts (olma@live.in)

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Generic printer value pointer type
class PrinterValueBase
{
public:
	virtual void print(ostream& out) const = 0;

};

// Printer value template for print format customization
template<class T> class PrinterValue : public PrinterValueBase
{
public:
	PrinterValue(const T& value) :
		mValue(value)
	{ }

	void print(ostream& out) const
	{
		out << *this;
	}

	const T& getPureValue() const
	{
		return mValue;
	}

protected:
	T mValue;

};

// Type specializations.
// To add new type "Foo" support for Printer, implemement
// ostream& operator<<(ostream& stream, const PrinterValue<Foo>& value)

ostream& operator<<(ostream& stream, const PrinterValue<int>& value)
{
	return stream << value.getPureValue();
}

ostream& operator<<(ostream& stream, const PrinterValue<int*>& value)
{
	return stream << "[" << *value.getPureValue() << "]";
}

ostream& operator<<(ostream& stream, const PrinterValue<double>& value)
{
	return stream << value.getPureValue();
}

ostream& operator<<(ostream& stream, const PrinterValue<float*>& value)
{
	return stream << "[" <<  *value.getPureValue() << "]";
}

ostream& operator<<(ostream& stream, const PrinterValue<string>& value)
{
	return stream << value.getPureValue();
}

// Default print support.

template<class T> ostream& operator<<(ostream& stream, const PrinterValue<T>& value)
{
	return stream << value.getPureValue();
}

/// implement your class here
class Printer
{
public:
	// Stores value as printer value to use later
	template<class T> Printer& operator=(const T& value)
	{
		mValue = make_unique<PrinterValue<T>>(value);

		return *this;
	}

	// Prints value if present, empty line otherwise
	void print()
	{
		if (mValue)
		{
			mValue->print(cout);
		}

		cout << endl;
	}

private:
	unique_ptr<PrinterValueBase> mValue;

};

int main() {
	Printer printer;

	printer = 42;
	printer.print(); //should print "42" to standard output

	int* value = new int(10);
	printer = value;
	printer.print(); // should print "[10]"

	*value = 20; // the value pointer did not change, changed a value by it
	printer.print(); // should print "[20]"

	float* fvalue = new float(9.81);
	printer = fvalue;
	printer.print(); // should print "[9.81]"

	*fvalue = 0.2 + 0.3;
	printer.print(); // should print "[0.5]"

	printer = std::string("Hello world");
	printer.print();
	//should print "Hello world"

	printer = 2.718281;
	printer.print();
	//should print "2.718281"

	delete fvalue;
	delete value;
	return 0;
}


// the standard output should be:
//42
//[10]
//[20]
//[9.81]
//[0.5]
//Hello world
//2.71828