#include "ProductsConfigWrapper.h"

ArrayWrapper<SeriesGroupWrapper> ProductsConfigWrapper::GetItemSeries_AllowTradeIn() {
    return {memory_address + 0x98};
}

ProductsConfigWrapper::ProductsConfigWrapper(std::uintptr_t memory_address) : ObjectWrapper(memory_address) {}
ProductsConfigWrapper &ProductsConfigWrapper::operator=(ProductsConfigWrapper rhs) { this->memory_address = rhs.memory_address; return *this; }
ProductsConfigWrapper::ProductsConfigWrapper(const ProductsConfigWrapper &other) = default;
ProductsConfigWrapper::~ProductsConfigWrapper() = default;
