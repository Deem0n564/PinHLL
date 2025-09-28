#pragma once

class Object
{
	int serialNumber;

public:
	Object()
	{
		serialNumber = quantity;
	}

	int getSerialNumber() const;

	static int quantity;
};
