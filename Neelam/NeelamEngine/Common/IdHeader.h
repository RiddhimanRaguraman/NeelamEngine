#pragma once

#include "CommonHeaders.h"

namespace Neelam::Id
{
	using ID_type = uint32_t;													// id type
	
	namespace Internal
	{
		constexpr uint32_t generation_bits{ 8 };									// generation bit count
		constexpr uint32_t index_bits{ sizeof(ID_type) * 8 - generation_bits };		// index bit count
		constexpr ID_type index_mask{ (ID_type{1} << index_bits) - 1 };				// index mask
		constexpr ID_type generation_mask{ (ID_type{1} << generation_bits) - 1 };	// generation mask
	}
	constexpr ID_type invalid_id{ ~ID_type{0} };									// invalid id

	// smallest generation type
	using generation_type =
		std::conditional_t<Internal::generation_bits <= 16,
		std::conditional_t<Internal::generation_bits <= 8, uint8_t, uint16_t>,uint32_t>;

	static_assert(sizeof(generation_type) * 8 >= Internal::generation_bits);
	static_assert(sizeof(ID_type) - sizeof(generation_type) > 0);

	inline bool id_valid(ID_type id) 												// valid id check
	{
		return id != invalid_id;
	}

	inline ID_type Index(ID_type id)												// get index
	{ 
		ID_type index{ id & Internal::index_mask };
		assert(index != Internal::index_mask);
		return index; 
	}										
	
	inline ID_type generation(ID_type id) { return (id >> Internal::index_bits) & Internal::generation_mask; }	// get generation
	inline ID_type New_generation(ID_type id)																	// next generation
	{
		const ID_type generation(Id::generation(id) + 1);
		assert(generation < (((u64)1 << Internal::generation_bits) - 1));
		return Index(id) | generation << Internal::index_bits;
	}

#if _DEBUG
	// typed id base
	namespace Internal
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
	struct name final : Id::Internal::id_base				\
	{														\
		constexpr explicit name(Id::ID_type id)				\
								: id_base{ id } {}			\
		constexpr name() : id_base{ 0 } {}					\
	};
#else
#define DEFINE_TYPED_ID(name) using name = Id::ID_type;
#endif

}
