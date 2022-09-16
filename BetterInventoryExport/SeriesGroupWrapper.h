#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "BetterInventoryExport.h"


class BAKKESMOD_PLUGIN_EXPORT SeriesGroupWrapper : ObjectWrapper {
public:
    CONSTRUCTORS(SeriesGroupWrapper)

    int32_t GetSeriesID();
    ArrayWrapper<ProductQuality> GetExcludedQualities();
};

template<> class BAKKESMOD_PLUGIN_EXPORT ArrayWrapper<ProductQuality> {
public:
	ArrayWrapper(std::uintptr_t mem) {
        base = (ProductQuality *)mem;
        count = (int32_t *)(base + 0x8);
        max = (int32_t *)(base + 0x16);
    }
	ArrayWrapper(const ArrayWrapper<ProductQuality>& other) = default;
	ArrayWrapper& operator=(ArrayWrapper<ProductQuality> rhs) {
        this->base = rhs.base;
        this->count = rhs.count;
        this->max = rhs.max;
        return *this;
    }
	~ArrayWrapper() = default;

	int Count() { return *count; }
	ProductQuality Get(int index) { return base[index]; }
    bool IsNull() { return base == NULL; }

protected:
    ProductQuality *base;
    int32_t *count;
    int32_t *max;
};