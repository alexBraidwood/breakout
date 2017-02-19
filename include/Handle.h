/*
 * File: Handle.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_HANDLE_H
#define BREAKOUT_HANDLE_H

namespace core {
/**
 * Mix-in template to facilitate RAII-style handling of native resources
 * @tparam THandle Native resource to be managed
 */
template <typename THandle>
class Handle {

protected:
    virtual ~Handle() {}
    THandle* handle;

public:

    auto get() const -> THandle*
    {
        return handle;
    }

    auto reset(THandle* handle) -> void
    {
        this->handle = nullptr;
        this->handle = handle;
    }

    Handle(THandle* handle)
    {
        this->handle = handle;
    }

    Handle(Handle&& other)
    {
        if (this!=&other) {
            this->handle = other.get();
            other.reset(nullptr);
        }
    }

    auto operator=(Handle&& other) -> Handle&
    {
        if (this!=&other) {
            this->handle = other.get();
            other.reset(nullptr);
        }
        return *this;
    }

    Handle(const Handle&) = delete;
    Handle& operator=(const Handle&) = delete;
};
}

#endif //BREAKOUT_HANDLE_H
