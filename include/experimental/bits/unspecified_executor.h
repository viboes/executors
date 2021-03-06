//
// unspecified_executor.h
// ~~~~~~~~~~~~~~~~~~~~~~
// Unspecified executor implementation.
//
// Copyright (c) 2014 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EXECUTORS_EXPERIMENTAL_BITS_UNSPECIFIED_EXECUTOR_H
#define EXECUTORS_EXPERIMENTAL_BITS_UNSPECIFIED_EXECUTOR_H

namespace std {
namespace experimental {


inline execution_context& unspecified_executor::context()
{
  return system_executor().context();
}

inline void unspecified_executor::work_started() noexcept
{
  // No-op.
}

inline void unspecified_executor::work_finished() noexcept
{
  // No-op.
}

template <class _Func, class _Alloc>
void unspecified_executor::dispatch(_Func&& __f, const _Alloc& a)
{
  system_executor().dispatch(forward<_Func>(__f), a);
}

template <class _Func, class _Alloc>
inline void unspecified_executor::post(_Func&& __f, const _Alloc& a)
{
  system_executor().post(forward<_Func>(__f), a);
}

template <class _Func, class _Alloc>
inline void unspecified_executor::defer(_Func&& __f, const _Alloc& a)
{
  system_executor().defer(forward<_Func>(__f), a);
}

template <class _Func>
inline auto unspecified_executor::wrap(_Func&& __f) const
{
  return (wrap_with_executor)(forward<_Func>(__f), *this);
}

} // namespace experimental
} // namespace std

#endif
