#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "SeriesGroupWrapper.h"


class BAKKESMOD_PLUGIN_EXPORT ProductsConfigWrapper : ObjectWrapper {
public:
    CONSTRUCTORS(ProductsConfigWrapper)

    ArrayWrapper<SeriesGroupWrapper> GetItemSeries_AllowTradeIn();
};

template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<SeriesGroupWrapper>;