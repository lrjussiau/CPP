#include "Serializer.hpp"

int main() {
    Data myData = {42};
    Data* myDataPtr = &myData;

    // Serialize the pointer to a uintptr_t
    uintptr_t rawData = Serializer::serialize(myDataPtr);

    // Deserialize back to a Data pointer
    Data* deserializedDataPtr = Serializer::deserialize(rawData);

    // Test if the deserialization worked
    std::cout << "Original pointer: " << myDataPtr << ", Deserialized pointer: " << deserializedDataPtr << std::endl;
    std::cout << "Original value: " << myDataPtr->value << ", Deserialized value: " << deserializedDataPtr->value << std::endl;

    return 0;
}