#pragma once

#include <cstdint>

constexpr uint64_t ackermann(const uint64_t m, const uint64_t n)
{
	return (m == 0) ? n + 1 :
			(n == 0) ? ackermann(m - 1, 1) :
			ackermann(m - 1, ackermann(m, n - 1));
}
