//
// Created by they4kman on 4/11/22.
//

#include "SeriesGroupWrapper.h"

int32_t SeriesGroupWrapper::GetSeriesID() {
    return *(int32_t*)memory_address;
}

ArrayWrapper<ProductQuality> SeriesGroupWrapper::GetExcludedQualities() {
    return {memory_address + 0x8};
}

SeriesGroupWrapper::SeriesGroupWrapper(std::uintptr_t memory_address) : ObjectWrapper(memory_address) {}
SeriesGroupWrapper &SeriesGroupWrapper::operator=(SeriesGroupWrapper rhs) { this->memory_address = rhs.memory_address; return *this; }
SeriesGroupWrapper::SeriesGroupWrapper(const SeriesGroupWrapper &other) = default;
SeriesGroupWrapper::~SeriesGroupWrapper() = default;