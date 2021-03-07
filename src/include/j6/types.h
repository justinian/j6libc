#pragma once
/// \file types.h
/// Basic kernel types exposed to userspace

#include <stdint.h>

/// All interactable kernel objects have a uniqe kernel object id
typedef uint64_t j6_koid_t;

/// Syscalls return status as this type
typedef uint64_t j6_status_t;

/// Some objects have signals, which are a bitmap of 64 possible signals
typedef uint64_t j6_signal_t;

/// Handles are references and capabilities to other objects. The least
/// significant 32 bits are an identifier, and the most significant 32
/// bits are a bitmask of capabilities this handle has on that object.
typedef uint64_t j6_handle_t;
