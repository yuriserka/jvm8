#include "instructions/instruction_set/reference.h"

#include "utils/array_t.h"
#include "utils/flags.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/method_area.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
    <<<<<<< Updated upstream
        namespace Reference {
        /**
         * @brief Load reference from array
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> LoadFromArray::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            int index = th->current_frame->popOperand<int>();
            auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                ->data.as<Utils::Array_t *>();
            th->current_frame->pushOperand(arrayref->get<Utils::Object *>(index));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Store into reference array
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> StoreIntoArray::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto value = th->current_frame->popOperand<Utils::Object *>();
            auto index = th->current_frame->popOperand<int>();
            auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                ->data.as<Utils::Array_t *>();
            arrayref->insert(value, index);
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Push null
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> ConstNull::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand<Utils::Object>(nullptr);
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Load reference from local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Load::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            int localvar_index;
            if (wide) {
                localvar_index =
                    static_cast<int16_t>((*++*code_iterator << 8) | *++*code_iterator);
                *delta_code = 2;
            } else {
                localvar_index = int{*++*code_iterator};
                *delta_code = 1;
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(localvar_index));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Load reference from local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Load_0::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(0));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Load reference from local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Load_1::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(1));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Load reference from local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Load_2::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(2));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Load reference from local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Load_3::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(3));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Create new array of reference
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> NewArray::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
            auto classname = th->method_area->runtime_constant_pool[kpool_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Class_info>()
                ->getValue(th->method_area->runtime_constant_pool);
            *delta_code = 2;
            
            auto count = th->current_frame->popOperand<int>();
            
            if (!count) {
                throw Utils::Errors::JvmException(Utils::Errors::kNEGATIVEARRAYSIZE,
                                                  "NegativeArraySizeException");
            }
            
            auto arr = new Utils::Array_t(count, Utils::Reference::kREF_CLASS);
            auto objectref =
                new Utils::Object(arr, Utils::Reference::kREF_ARRAY, classname);
            
            th->current_frame->pushOperand(th->heap->pushReference(objectref));
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Return reference from method
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Return::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto retval = th->current_frame->popOperand<Utils::Object *>();
            th->pushReturnValue(retval);
            th->current_frame->cleanOperands();
            return {1};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Get length of array
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> ArrayLength::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                ->data.as<Utils::Array_t *>();
            
            th->current_frame->pushOperand(arrayref->length());
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Store reference into local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Store::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            int localvar_index;
            if (wide) {
                localvar_index =
                    static_cast<int16_t>((*++*code_iterator << 8) | *++*code_iterator);
                *delta_code = 2;
            } else {
                localvar_index = int{*++*code_iterator};
                *delta_code = 1;
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, localvar_index);
            
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Store reference into local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Store_0::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 0);
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Store reference into local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Store_1::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 1);
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Store reference into local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Store_2::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 2);
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Store reference into local variable
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Store_3::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 3);
            return {};
        }
        // ----------------------------------------------------------------------------
        /**
         * @brief Throw exception or error
         * 
         * @param code_iterator 
         * @param th 
         * @param delta_code 
         * @param wide 
         * @param pc 
         * @return std::vector<int> 
         */
        std::vector<int> Throw::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            // ??
            throw objectref;
            return {};
        }
        // ----------------------------------------------------------------------------
    }  // namespace Reference
    =======
        namespace Reference {
        std::vector<int> LoadFromArray::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            int index = th->current_frame->popOperand<int>();
            auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                ->data.as<Utils::Array_t *>();
            th->current_frame->pushOperand(arrayref->get<Utils::Object *>(index));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> StoreIntoArray::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto value = th->current_frame->popOperand<Utils::Object *>();
            auto index = th->current_frame->popOperand<int>();
            auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                ->data.as<Utils::Array_t *>();
            arrayref->insert(value, index);
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> ConstNull::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand<Utils::Object>(nullptr);
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Load::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            int localvar_index;
            if (wide) {
                localvar_index =
                    static_cast<int16_t>((*++*code_iterator << 8) | *++*code_iterator);
                *delta_code = 2;
            } else {
                localvar_index = int{*++*code_iterator};
                *delta_code = 1;
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(localvar_index));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Load_0::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(0));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Load_1::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(1));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Load_2::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(2));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Load_3::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            th->current_frame->pushOperand(
                th->current_frame->getLocalVarValue<Utils::Object *>(3));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> NewArray::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto kpool_index = (*++*code_iterator << 8) | *++*code_iterator;
            auto classname = th->method_area->runtime_constant_pool[kpool_index - 1]
                .getClass<Utils::ConstantPool::CONSTANT_Class_info>()
                ->getValue(th->method_area->runtime_constant_pool);
            *delta_code = 2;
            
            auto count = th->current_frame->popOperand<int>();
            
            if (!count) {
                throw Utils::Errors::JvmException(Utils::Errors::kNEGATIVEARRAYSIZE,
                                                  "NegativeArraySizeException");
            }
            
            auto arr = new Utils::Array_t(count, Utils::Reference::kREF_CLASS);
            auto objectref =
                new Utils::Object(arr, Utils::Reference::kREF_ARRAY, classname);
            
            th->current_frame->pushOperand(th->heap->pushReference(objectref));
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Return::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto retval = th->current_frame->popOperand<Utils::Object *>();
            th->pushReturnValue(retval);
            th->current_frame->cleanOperands();
            return {1};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> ArrayLength::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto arrayref = th->current_frame->popOperand<Utils::Object *>()
                ->data.as<Utils::Array_t *>();
            
            th->current_frame->pushOperand(arrayref->length());
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Store::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            int localvar_index;
            if (wide) {
                localvar_index =
                    static_cast<int16_t>((*++*code_iterator << 8) | *++*code_iterator);
                *delta_code = 2;
            } else {
                localvar_index = int{*++*code_iterator};
                *delta_code = 1;
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, localvar_index);
            
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Store_0::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 0);
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Store_1::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 1);
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Store_2::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 2);
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Store_3::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            th->current_frame->pushLocalVar(objectref, 3);
            return {};
        }
        // ----------------------------------------------------------------------------
        std::vector<int> Throw::execute(
            std::vector<Utils::Types::u1>::iterator *code_iterator,
            MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
            if (Utils::Flags::options.kDEBUG) {
                std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
            }
            auto objectref = th->current_frame->popOperand<Utils::Object *>();
            
            throw objectref;
            
            return {};
        }
        // ----------------------------------------------------------------------------
    }  // namespace Reference
    >>>>>>> Stashed changes
}  // namespace Instructions
