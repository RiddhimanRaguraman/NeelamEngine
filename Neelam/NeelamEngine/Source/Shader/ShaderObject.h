//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_OBJECT_H
#define SHADER_OBJECT_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).
#include "ShaderModule.h"
#include "MathEngine.h"

namespace Neelam::vk
{
	//-----------------------------------------------------------------
	// The matrices handed to the vertex stage as PUSH CONSTANTS -- a small block
	// written straight into the command buffer, no descriptor set or allocation.
	//
	// world is per object, viewProj is per frame. view*proj is premultiplied on
	// the CPU: Azul is row-vector, so clip = v * world * (view * proj) associates
	// correctly, and one matrix leaves room for world inside the 128-byte limit
	// the spec guarantees. Today world is identity.
	//
	// The HLSL side must declare these row_major and use mul(vector, matrix) --
	// Azul::Mat4 is 4 row Vec4s, while HLSL packs column-major by default. Get
	// that wrong and every matrix silently arrives transposed.
	//-----------------------------------------------------------------
	struct ShaderMatrices
	{
		Azul::Mat4 world;
		Azul::Mat4 viewProj;
	};

	static_assert(sizeof(ShaderMatrices) == 128,
		"ShaderMatrices must stay within the 128-byte guaranteed push-constant limit");
}

//---------------------------------------------------------------------------
// class ShaderObject  (abstract base)
//
// A complete "technique" -- the Vulkan take on Azul's ShaderObject. It owns
// its vertex + pixel modules AND the VkPipeline they are baked into, plus the
// pipeline layout.
//
// The key Vulkan difference from Azul/DX11: shaders are NOT bound individually.
// They are compiled into an immutable VkPipeline, so:
//   * SetActive() is one vkCmdBindPipeline (not VSSetShader + PSSetShader).
//   * a reload must REBUILD the pipeline, not just swap a module --
//     ReloadFromBlobs() does that.
//
// Derived classes supply only which .hlsl files to use (GetVertexPath /
// GetPixelPath) and their vertex layout. The base handles compile, pipeline
// build and hot-reload. One color attachment, depth on, dynamic viewport and
// scissor so a camera can set them per frame.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class ShaderObject
	{
	public:
		//-----------------------------------------------------------------
		// Identity for manager lookup. A cross-thread command carries this
		// NAME, never a ShaderObject* -- the engine thread resolves it through
		// ShaderObjectNodeMan::Find() when the command executes, so a technique
		// destroyed while a compile was in flight resolves to nullptr instead of a
		// dangling pointer.
		//-----------------------------------------------------------------
		enum class Name
		{
			ColorByVertex,

			NOT_INITIALIZED,
			NullShader
		};

	public:
		ShaderObject();
		ShaderObject(const ShaderObject &) = delete;
		ShaderObject &operator = (const ShaderObject &) = delete;
		virtual ~ShaderObject();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------

		// Compile VS+PS and build the pipeline. colorFormat / depthFormat are
		// the swapchain's formats (dynamic rendering bakes them into the
		// pipeline, so they must match the frame loop's attachments).
		void Create(VkDevice device, VkFormat colorFormat, VkFormat depthFormat);


		void Destroy();

		//-----------------------------------------------------------------
		// Draw-time
		//-----------------------------------------------------------------
		void SetActive(VkCommandBuffer cmd) const;		// vkCmdBindPipeline

		// vkCmdPushConstants. Must be called AFTER SetActive() has bound the
		// pipeline, and re-issued every frame -- push constants live in the
		// command buffer, so a pool reset wipes them.
		void SetMatrices(VkCommandBuffer cmd, const ShaderMatrices &matrices) const;

		//-----------------------------------------------------------------
		// Async hot-reload (engine thread half)
		//-----------------------------------------------------------------

		// Swap in modules built from SPIR-V that the FileThread already
		// compiled, then rebuild the pipeline. The expensive part (disk + DXC)
		// already happened on the file thread.
		// Either blob may be null -> that stage keeps its last-good module.
		void ReloadFromBlobs(IDxcBlob *pVertexSpirv, IDxcBlob *pPixelSpirv);

		//-----------------------------------------------------------------
		// Identity
		//-----------------------------------------------------------------
		ShaderObject::Name GetName() const;
		void               SetName(ShaderObject::Name name);

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------
		VkPipeline       GetPipeline() const;
		VkPipelineLayout GetLayout() const;

		// Source .hlsl files. GetVertexPath is also where ShaderWatcher gets the`r`n`t`t// folder to watch, so it is the only place that path is named.
		virtual const char *GetVertexPath() const = 0;
		virtual const char *GetPixelPath() const  = 0;

		//-----------------------------------------------------------------
		// Vertex format. Baked into the pipeline, so it belongs to the
		// technique -- a derived class describes the layout its .hlsl expects.
		//
		// Default is NO vertex input, which is what a shader that builds its
		// own positions from SV_VertexID needs. Override BOTH or neither.
		//-----------------------------------------------------------------
		virtual uint32_t GetVertexBindings(const VkVertexInputBindingDescription **ppOut) const;
		virtual uint32_t GetVertexAttributes(const VkVertexInputAttributeDescription **ppOut) const;

	protected:
		// Data
		VkDevice         privDevice;
		VkFormat         privColorFormat;
		VkFormat         privDepthFormat;

		ShaderModule     vertexShader;
		ShaderModule     pixelShader;

		VkPipelineLayout privLayout;
		VkPipeline       privPipeline;

		ShaderObject::Name privName;

	private:
		void privBuildLayout();
		void privBuildPipeline();		// destroys the old pipeline first if present
	};
}

#endif   // SHADER_OBJECT_H

// ---  End of File ---
