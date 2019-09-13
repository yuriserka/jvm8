#ifndef INCLUDE_UTILS_ATTRIBUTES_H_
#define INCLUDE_UTILS_ATTRIBUTES_H_

#include "utils/types.h"

namespace types = Utils::Types;

namespace Utils {
namespace Attributes {
class BaseAttribute {
 public:
    BaseAttribute() = default;

    explicit BaseAttribute(const types::u1 &nameIdx, const types::u4 &attrLen) {
        this->attribute_name_index = nameIdx;
        this->attribute_length = attrLen;
    }

    virtual ~BaseAttribute() = default;

    types::u2 attribute_name_index;
    types::u4 attribute_length;
};

class attribute_info {
 public:
    attribute_info() = default;
    
    ~attribute_info() = default;

    template<typename T>
    void deleteclass() {
        auto derivedptr = this->getClass<T>();
        derivedptr->~T();

        delete derivedptr;
    }

    template<typename T>
    T *setBase(const types::u1 &tag) {
        this->base = new T(tag);
        return this->getClass<T>();
    }

    template<typename T>
    T *getClass() {
        return dynamic_cast<T *>(this->base);
    }

    BaseAttribute *base;
};

class ConstantValue_attribute : public BaseAttribute {
 public:
    explicit ConstantValue_attribute(const types::u1 &nameIdx,
                                     const types::u4 &attrLen)
                                    : BaseAttribute(nameIdx, attrLen) {}

    ~ConstantValue_attribute() = default;
    
    types::u2 constantvalue_index;
};

class Code_attribute : public BaseAttribute {
 public:
    types::u2 max_stack;
    types::u2 max_locals;
    types::u4 code_length;
    std::vector<types::u1> code;
    types::u2 exception_table_length;
    types::u2 attributes_count;
    std::vector<attribute_info> attributes;
    struct excpt{
        types::u2 start_pc;
        types::u2 end_pc;
        types::u2 handler_pc;
        types::u2 catch_type;
    };
    std::vector<excpt> exception_table;
};

class Exceptions_attribute : public BaseAttribute {
    types::u2 number_of_exceptions;
    std::vector<types::u2> exception_index_table;
};
}  // namespace Attributes   
}  // namespace Utils



#endif  // INCLUDE_UTILS_ATTRIBUTES_H_