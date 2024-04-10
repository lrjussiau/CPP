#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include <cstdint>

struct Data {
	unsigned int value;
};

class Serializer
{
	private:
		Serializer();
		virtual ~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif