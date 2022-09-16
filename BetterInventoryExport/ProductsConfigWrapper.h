#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "SeriesGroupWrapper.h"


class BAKKESMOD_PLUGIN_EXPORT ProductsConfigWrapper : ObjectWrapper {
public:
    CONSTRUCTORS(ProductsConfigWrapper)

    ArrayWrapper<SeriesGroupWrapper> GetItemSeries_AllowTradeIn();
};

template<> class BAKKESMOD_PLUGIN_EXPORT ArrayWrapper<SeriesGroupWrapper> {
public:
	ArrayWrapper(std::uintptr_t mem) {
        base = (SeriesGroupWrapper *)mem;
        count = (int32_t *)(base + 0x8);
        max = (int32_t *)(base + 0x16);
    }
	ArrayWrapper(const ArrayWrapper<SeriesGroupWrapper>& other) = default;
	ArrayWrapper& operator=(ArrayWrapper<SeriesGroupWrapper> rhs) {
        this->base = rhs.base;
        this->count = rhs.count;
        this->max = rhs.max;
        return *this;
    }
	~ArrayWrapper() = default;

	int Count() { return *count; }
	SeriesGroupWrapper Get(int index) { return base[index]; }
    bool IsNull() { return base == NULL; }

protected:
    SeriesGroupWrapper *base;
    int32_t *count;
    int32_t *max;
};