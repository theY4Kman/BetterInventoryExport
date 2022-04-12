#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "BetterInventoryExport.h"


class BAKKESMOD_PLUGIN_EXPORT SeriesGroupWrapper : ObjectWrapper {
public:
    CONSTRUCTORS(SeriesGroupWrapper)

    int32_t GetSeriesID();
    ArrayWrapper<ProductQuality> GetExcludedQualities();
};

template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ProductQuality>;