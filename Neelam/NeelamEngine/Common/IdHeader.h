#pragma once

#include "Common/CommonHeaders.h"

namespace Azul::Id 
{
	using ID_type = u32;
	constexpr u32 header_bits{ 8 };
	constexpr u32 index_bits{ sizeof(ID_type) * 8 - header_bits };
	constexpr ID_type index_mask{ (ID_type{1} << index_bits) - 1 };
	constexpr ID_type header_mask{ (ID_type{1} << header_bits) - 1 };
	constexpr ID_type id_mask{ ID_type{-1} };

	using Header_type =
		std::conditional_t<header_bits <= 16,
		std::conditional_t<header_bits <= 8, u8, u16>,  
		u32>;

	static_assert(sizeof(Header_type) * 8 >= header_bits);
	static_assert(sizeof(ID_type) - sizeof(Header_type) > 0);

	inline bool id_valid(ID_type id) { return id != id_mask; }
	inline ID_type Index(ID_type id) { return id & index_mask; }
	inline ID_type Header(ID_type id) { return (id >> index_bits) & header_mask; }
	inline ID_type New_Header(ID_type id) 
	{
		const ID_type Header(Id::Header(id) + 1);
		assert(Header < 255);
		return Index(id) | Header << index_bits;
	}

}