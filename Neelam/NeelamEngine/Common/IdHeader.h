#pragma once

#include "CommonHeaders.h"

namespace Neelam::Id
{
	using ID_type = u32;								// id type
	constexpr u32 generation_bits{ 8 };						// generation bit count
	constexpr u32 index_bits{ sizeof(ID_type) * 8 - generation_bits };	// index bit count
	constexpr ID_type index_mask{ (ID_type{1} << index_bits) - 1 };	// index mask
	constexpr ID_type generation_mask{ (ID_type{1} << generation_bits) - 1 };	// generation mask
	constexpr ID_type id_mask{ ~ID_type{0} };			// invalid id

	// smallest generation type
	using generation_type =
		std::conditional_t<generation_bits <= 16,
		std::conditional_t<generation_bits <= 8, u8, u16>,
		u32>;

	static_assert(sizeof(generation_type) * 8 >= generation_bits);
	static_assert(sizeof(ID_type) - sizeof(generation_type) > 0);

	inline bool id_valid(ID_type id) { return id != id_mask; }			// valid id check
	inline ID_type Index(ID_type id) { return id & index_mask; }		// get index
	inline ID_type generation(ID_type id) { return (id >> index_bits) & generation_mask; }	// get generation
	inline ID_type New_generation(ID_type id)								// next generation
	{
		const ID_type generation(Id::generation(id) + 1);
		assert(generation < 255);
		return Index(id) | generation << index_bits;
	}

#if _DEBUG
	// typed id base
	namespace internal
	{
		struct id_base
		{
			constexpr explicit id_base(ID_type id) : _id{ id } {}
			constexpr operator ID_type() const { return _id; }
		private:
			ID_type _id;
		};
	} // namespace internal

	// typed id macro
#define DEFINE_TYPED_ID(name)								\
	struct name final : Id::internal::id_base				\
	{														\
		constexpr explicit name(Id::ID_type id) : id_base{ id } {}	\
		constexpr name() : id_base{ Id::id_mask } {}		\
	};
#else
#define DEFINE_TYPED_ID(name) using name = Id::ID_type;
#endif

}
