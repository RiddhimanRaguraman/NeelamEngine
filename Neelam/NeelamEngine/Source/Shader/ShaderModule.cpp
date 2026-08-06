//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderModule.h"

namespace Neelam::vk
{
	ShaderModule::ShaderModule()
		: privDevice(VK_NULL_HANDLE),
		  privStage(ShaderStage::Vertex),
		  privPath{},
		  privModule(VK_NULL_HANDLE)
	{
	}

	ShaderModule::~ShaderModule()
	{
		this->Destroy();
	}

	void ShaderModule::Create(VkDevice device, const char *pFilePath, ShaderStage stage)
	{
		this->privDevice = device;
		this->privStage  = stage;
		strcpy_s(this->privPath, sizeof(this->privPath), pFilePath);

		this->privModule = this->privCompile();

		// A shader that will not compile on first load is fatal -- there is no
		// last-good version to fall back to yet.
		if (this->privModule == VK_NULL_HANDLE)
		{
			Debug::out("ShaderModule: initial compile failed for '%s'\n", this->privPath);
			assert(false);
			ExitProcess(1);
		}
	}

	bool ShaderModule::CreateFromBlob(IDxcBlob *pSpirv)
	{
		assert(pSpirv);

		VkShaderModuleCreateInfo info = {};
		info.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		info.codeSize = pSpirv->GetBufferSize();						// bytes
		info.pCode    = (const uint32_t *)pSpirv->GetBufferPointer();

		VkShaderModule fresh = VK_NULL_HANDLE;
		VkResult res = vkCreateShaderModule(this->privDevice, &info, nullptr, &fresh);

		if (res != VK_SUCCESS)
		{
			Debug::out("ShaderModule: vkCreateShaderModule failed for '%s' (%d)\n",
				this->privPath, (int)res);
			return false;
		}

		if (this->privModule != VK_NULL_HANDLE)
		{
			vkDestroyShaderModule(this->privDevice, this->privModule, nullptr);
		}
		this->privModule = fresh;
		return true;
	}

	void ShaderModule::Destroy()
	{
		if (this->privModule != VK_NULL_HANDLE)
		{
			vkDestroyShaderModule(this->privDevice, this->privModule, nullptr);
			this->privModule = VK_NULL_HANDLE;
		}
	}

	VkShaderModule ShaderModule::privCompile() const
	{
		// HLSL -> SPIR-V (DXC). The blob owns the bytecode; vkCreateShaderModule
		// COPIES it, so we can release the blob right after.
		IDxcBlob *pSpirv = ShaderCompiler::CompileFile(this->privPath, this->privStage);
		if (pSpirv == nullptr)
		{
			return VK_NULL_HANDLE;
		}

		VkShaderModuleCreateInfo info = {};
		info.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		info.codeSize = pSpirv->GetBufferSize();						// bytes
		info.pCode    = (const uint32_t *)pSpirv->GetBufferPointer();

		VkShaderModule module = VK_NULL_HANDLE;
		VkResult res = vkCreateShaderModule(this->privDevice, &info, nullptr, &module);

		pSpirv->Release();

		if (res != VK_SUCCESS)
		{
			Debug::out("ShaderModule: vkCreateShaderModule failed for '%s' (%d)\n",
				this->privPath, (int)res);
			return VK_NULL_HANDLE;
		}

		return module;
	}

	VkShaderModule ShaderModule::GetModule() const
	{
		return this->privModule;
	}

	VkShaderStageFlagBits ShaderModule::GetStageBit() const
	{
		return (this->privStage == ShaderStage::Vertex)
			? VK_SHADER_STAGE_VERTEX_BIT
			: VK_SHADER_STAGE_FRAGMENT_BIT;
	}

	const char *ShaderModule::GetPath() const
	{
		return this->privPath;
	}

	VkPipelineShaderStageCreateInfo ShaderModule::GetStageCreateInfo() const
	{
		VkPipelineShaderStageCreateInfo info = {};
		info.sType  = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		info.stage  = this->GetStageBit();
		info.module = this->privModule;
		info.pName  = "main";		// HLSL entry point (-E main)
		return info;
	}
}

// ---  End of File ---
