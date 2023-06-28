#pragma once
#include <istream>

struct EngineInfo;

class ILoaderConfig{
    public:
    [[nodiscard]] virtual bool load(std::basic_istream<char>& stream) = 0;
    virtual const EngineInfo& getResult() const = 0;
};