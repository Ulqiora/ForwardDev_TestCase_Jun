#pragma once 
#include <istream>
#include "ILoaderConfig.h"
#include "EngineInfo.h"

class LoaderConfig : public ILoaderConfig{
    public:
    [[nodiscard]] bool load(std::basic_istream<char>& stream) override final;
    const EngineInfo& getResult() const override final;
    private:
    EngineInfo info_;
};
