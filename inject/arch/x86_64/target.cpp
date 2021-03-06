#include "target.hpp"

extern "C" void do_remote_call_64();
extern const size_t do_remote_call_64_size;

extern "C" void do_dlopen_64();
extern const size_t do_dlopen_64_size;

extern "C" void do_dlclose_64();
extern const size_t do_dlclose_64_size;

using namespace dyntrace::inject;
using target::x86_64;

void x86_64::set_args(ptrace<x86_64>&, x86_64::regs& r, const remote_args<x86_64>& args, remote_ptr<x86_64> func, remote_ptr<x86_64> caller) noexcept
{
    r.rdi = args._0;
    r.rsi = args._1;
    r.rdx = args._2;
    r.rcx = args._3;
    r.r8 = args._4;
    r.r9 = args._5;
    r.r10 = args._6;
    r.r11 = args._7;

    r.rax = func.get();
    r.rip = caller.get();
}

x86_64::regval x86_64::get_return(const x86_64::regs& r) noexcept
{
    return r.rax;
}

void* x86_64::remote_call_impl_ptr() noexcept
{
    return reinterpret_cast<void*>(do_remote_call_64);
}

size_t x86_64::remote_call_impl_size() noexcept
{
    return do_remote_call_64_size;
}

void* x86_64::remote_dlopen_impl_ptr() noexcept
{
    return reinterpret_cast<void*>(do_dlopen_64);
}

size_t x86_64::remote_dlopen_impl_size() noexcept
{
    return do_dlopen_64_size;
}

void* x86_64::remote_dlclose_impl_ptr() noexcept
{
    return reinterpret_cast<void*>(do_dlclose_64);
}

size_t x86_64::remote_dlclose_impl_size() noexcept
{
    return do_dlclose_64_size;
}