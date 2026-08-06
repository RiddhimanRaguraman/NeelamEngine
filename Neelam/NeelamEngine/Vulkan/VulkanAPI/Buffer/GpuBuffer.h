//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef GPU_BUFFER_H
#define GPU_BUFFER_H

// Vulkan + VMA types come from the force-included Framework.h.

namespace Neelam::vk
{
	//-----------------------------------------------------------------------
	// struct VertexPosColor
	//
	// One vertex as the GPU sees it. Plain floats, not Azul::Vec3: Vec3 is
	// Align16, so a {Vec3,Vec3} vertex would be a 32-byte stride with 8 bytes of
	// padding per field. This is 24, packed, and its offsets match the attribute
	// descriptions in ShaderObject_ColorByVertex.
	//-----------------------------------------------------------------------
	struct VertexPosColor
	{
		float x, y, z;			// POSITION
		float r, g, b;			// COLOR0
	};

	static_assert(sizeof(VertexPosColor) == 24,
		"VertexPosColor must stay packed -- the attribute offsets depend on it");

	//-----------------------------------------------------------------------
	// class GpuBuffer
	//
	// One VMA-allocated VkBuffer. Used for both vertex and index data -- the
	// only difference is the usage flag, so this is one class rather than two
	// near-identical ones.
	//
	// Host-visible and persistently MAPPED, written with a plain memcpy -- no
	// staging buffer and no transfer command buffer.
	//
	// Tradeoff: on a discrete GPU the data is read across PCIe every draw. Fine
	// for small or frequently-rewritten data; large STATIC geometry wants
	// DEVICE_LOCAL plus a staging copy.
	//
	// Allocation goes through vk::VulkanAllocator, so every byte is tracked.
	//-----------------------------------------------------------------------
	class GpuBuffer
	{
	public:
		GpuBuffer();
		GpuBuffer(const GpuBuffer &) = delete;
		GpuBuffer &operator = (const GpuBuffer &) = delete;
		~GpuBuffer();

		// usage is VK_BUFFER_USAGE_VERTEX_BUFFER_BIT / INDEX_BUFFER_BIT.
		// Copies pData in immediately; pData is not retained.
		void Create(const void *pData, VkDeviceSize sizeBytes, VkBufferUsageFlags usage);

		// Overwrite the contents. Same size only -- the allocation is fixed.
		void Update(const void *pData, VkDeviceSize sizeBytes);

		void Destroy();

		VkBuffer     GetBuffer() const;
		VkDeviceSize GetSize() const;

	private:
		VkBuffer      privBuffer;
		VmaAllocation privAllocation;
		void         *privMapped;		// persistent mapping, owned by VMA
		VkDeviceSize  privSize;
	};
}

#endif   // GPU_BUFFER_H

// ---  End of File ---
