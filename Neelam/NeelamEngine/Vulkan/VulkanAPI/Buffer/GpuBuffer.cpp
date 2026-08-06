//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "GpuBuffer.h"

namespace Neelam::vk
{
	GpuBuffer::GpuBuffer()
		: privBuffer(VK_NULL_HANDLE),
		  privAllocation(VK_NULL_HANDLE),
		  privMapped(nullptr),
		  privSize(0)
	{
	}

	GpuBuffer::~GpuBuffer()
	{
		this->Destroy();
	}

	void GpuBuffer::Create(const void *pData, VkDeviceSize sizeBytes, VkBufferUsageFlags usage)
	{
		assert(pData);
		assert(sizeBytes > 0);

		VkBufferCreateInfo bufferInfo = {};
		bufferInfo.sType       = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.size        = sizeBytes;
		bufferInfo.usage       = usage;
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;		// one queue family

		// HOST_ACCESS_SEQUENTIAL_WRITE tells VMA "the CPU will memcpy into this
		// and never read it back", so it picks write-combined memory where it
		// can. MAPPED keeps the pointer alive for the buffer's lifetime, which
		// is what lets Update() be a bare memcpy with no map/unmap pair.
		VmaAllocationCreateInfo allocCreate = {};
		allocCreate.usage = VMA_MEMORY_USAGE_AUTO;
		allocCreate.flags = VMA_ALLOCATION_CREATE_HOST_ACCESS_SEQUENTIAL_WRITE_BIT |
							VMA_ALLOCATION_CREATE_MAPPED_BIT;

		VmaAllocationInfo allocInfo = {};

		VK_Try(vmaCreateBuffer(VulkanAllocator::Get(), &bufferInfo, &allocCreate,
			&this->privBuffer, &this->privAllocation, &allocInfo));

		// VMA hands back the persistent mapping because of MAPPED above.
		this->privMapped = allocInfo.pMappedData;
		assert(this->privMapped);

		this->privSize = sizeBytes;

		memcpy(this->privMapped, pData, (size_t)sizeBytes);
	}

	void GpuBuffer::Update(const void *pData, VkDeviceSize sizeBytes)
	{
		assert(pData);
		assert(this->privMapped);

		// The allocation is fixed -- growing would mean a new buffer, and any
		// in-flight frame could still be reading the old one.
		assert(sizeBytes <= this->privSize);

		memcpy(this->privMapped, pData, (size_t)sizeBytes);
	}

	void GpuBuffer::Destroy()
	{
		if (this->privBuffer != VK_NULL_HANDLE)
		{
			// Frees the VkBuffer and its allocation together, and unmaps.
			// Must happen before vmaDestroyAllocator.
			vmaDestroyBuffer(VulkanAllocator::Get(), this->privBuffer, this->privAllocation);

			this->privBuffer     = VK_NULL_HANDLE;
			this->privAllocation = VK_NULL_HANDLE;
			this->privMapped     = nullptr;
			this->privSize       = 0;
		}
	}

	VkBuffer GpuBuffer::GetBuffer() const
	{
		return this->privBuffer;
	}

	VkDeviceSize GpuBuffer::GetSize() const
	{
		return this->privSize;
	}
}

// ---  End of File ---
